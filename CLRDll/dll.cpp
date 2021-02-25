#include "pch.h"
#include <string>

using namespace System::Runtime::InteropServices;

dll::dll()
{
	_cdll = new cdll();
	_cshapedll_native = new cshapedll_native();
	_cshapedll = gcnew CShapeDll::Dll();
}

dll::~dll()
{
	if (_cdll != NULL)
	{
		delete _cdll;
		_cdll = NULL;
	}

	if (_cshapedll_native != NULL)
	{
		delete _cshapedll_native;
		_cshapedll_native = NULL;
	}
}

System::String^ dll::invoke1(String^% str, unsigned int bytes)
{
	const char* value = (const char*)(void*)Marshal::StringToHGlobalAnsi(str);
	if (_cdll != NULL && _cdll->invoke1(value, bytes))
	{
		return gcnew String("Success");
	}
	else
	{
		return gcnew String("Failed");
	}
}

void dll::invoke2(String^% str)
{
	std::string file((char*)(void*)Marshal::StringToHGlobalAnsi(str));
	if (_cdll != NULL)
	{
		_cdll->invoke2(file);
	}

}

void dll::invoke3()
{
	if (_cdll != NULL)
	{
		_cdll->invoke3();
	}
}

void dll::invoke4(String^% str)
{
	if (_cshapedll != nullptr)
	{
		_cshapedll->Invoke(str);
	}
}

void dll::invoke5(String^% str)
{
	if (_cshapedll_native != NULL && ((CShapeDll::Dll ^)(_cshapedll_native->dll)) != nullptr)
	{
		_cshapedll_native->dll->Invoke(str);
	}
}

