#pragma once
#include "../CDll/cdll.h"
#include <vcclr.h>

#using "..\CShapeDll\bin\x86\Debug\net5.0\CShapeDll.dll" 

using namespace System;

public ref class dll
{
public:
    dll();
    ~dll();
    String^ invoke1(String^% str, unsigned int bytes);
    void invoke2(String^% str);
    void invoke3();
    void invoke4(String^ str);

private:
    gcroot<CShapeDll::Dll^>* _cshapedll;
    cdll* _cdll;
};

