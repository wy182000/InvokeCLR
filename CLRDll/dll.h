#pragma once
#include "../CDll/cdll.h"

public ref class dll
{
public:
    dll();
    ~dll();
    System::String^ invoke1(System::String^% str, unsigned int bytes);
    void invoke2(System::String^% str);
    void invoke3();

private:
    cdll* _cdll;
};

