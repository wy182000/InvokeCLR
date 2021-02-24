#pragma once
#include <string>

class cdll
{
public:
	bool invoke1(const char* str, unsigned int bytes);
	void invoke2(std::string str);
	void invoke3();
};

