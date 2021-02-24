#include "pch.h"
#include <string>

using namespace System::Runtime::InteropServices;

dll::dll()
{
	_cshapedll = new gcroot<CShapeDll::Dll^>(gcnew CShapeDll::Dll());
	_cdll = new cdll();
}

dll::~dll()
{
	if (_cdll != NULL)
	{
		delete _cdll;
		_cdll = NULL;
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

void dll::invoke4(String^ str)
{
	if (_cshapedll != NULL)
	{
		((CShapeDll::Dll^)*_cshapedll)->Invoke(str);
	}
}

