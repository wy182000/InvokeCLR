#pragma once
#include "../CDll/cdll.h"
#include <vcclr.h>

#using "CShapeDll.dll" 

using namespace System;

// test for naive class hold ref class
class cshapedll_native
{
public:
    gcroot<CShapeDll::Dll^> dll = gcnew CShapeDll::Dll();
};

public ref class dll
{
public:
    dll();
    ~dll();
    String^ invoke1(String^% str, unsigned int bytes);
    void invoke2(String^% str);
    void invoke3();
    void invoke4(String^% str);
    void invoke5(String^% str);

private:
    cdll* _cdll;
    CShapeDll::Dll^ _cshapedll;
    cshapedll_native* _cshapedll_native;
};
