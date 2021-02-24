#include "pch.h"
#include <stdio.h>

bool cdll::invoke1(const char* str, unsigned int bytes)
{
	printf("invoke1: %s\n", str);
	return true;
}

void cdll::invoke2(std::string str)
{
	printf("invoke2: %s\n", str.c_str());
}

void cdll::invoke3()
{
	printf("invoke3\n");
}
