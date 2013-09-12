#include "stdafx.h"

char *difference(char *str1, char *str2)
{
	if (NULL == str1 || NULL == str2)
	{
		return str2;
	}
	char *s1 = str1;
	char *s2 = str2;

	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	
	return s2;

}