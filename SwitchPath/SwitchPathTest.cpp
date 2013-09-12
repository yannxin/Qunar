// SwitchPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "switchPath.h"

void test1(string inPath, string exception)
{
	string outPath;
	SwitchPath(inPath, outPath);
//	puts(outPath.c_str());
	if (outPath == exception)
		printf("It's ok.\n");
	else
		printf("Something is wrong.\n");
}

int main(int argc, char* argv[])
{
	test1("/home/yannxin/../temp/test/../", "/home/temp");
	test1("/home/yannxin/./temp/test/../", "/home/yannxin/temp");
	test1("/home/yannxin/../../temp/test/../", "/temp");
	test1("/home/yannxin/../temp/test/../../", "/home");
	test1("/home/yannxin/../temp/test/../", "/home/temp");
	test1("/home/../../temp/test/../", "");
	test1("", "");
	return 0;
}

