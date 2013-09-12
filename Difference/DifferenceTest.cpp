// Difference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Difference.h"

void test1(char *str1, char *str2, char *exception)
{
	char *result = NULL;
	result = difference(str1, str2);
//	printf("%s\n", result);
	if (strcmp(result, exception) == 0)
		printf("It's ok.\n");
	else
		printf("Something is wrong.\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1("abcd","abcdg","g");
	return 0;
}

