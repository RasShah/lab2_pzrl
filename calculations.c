#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculations.h"

int summ(int n1, int n2)
{
	return n1 + n2;
}

int multi(int n1, int n2)
{
	return n1 * n2;
}

int substr(int n1, int n2)
{
	return n1 - n2;
}

int procent(int n1, int n2)
{
	return n1 % n2;
}

int ampersant(int n1, int n2)
{
	return n1 & n2;
}

int triangle(int n1, int n2)
{
	return n1 ^ n2;
}

int bitoder(int n1, int n2)
{
	return n1 | n2;
}

int tilde(const int n)
{
	if (n == 0)
		return 0;
	return -(n + 1);	
}

int typeofn(char* n)
{
	if (n[0] == '-')
	{
		n = n + 1;
	}
	if (n[0] == '0' && n[1] == 'x')
	{
		return 0;
	}
	else if (n[0] == '0')
	{
		if (strlen(n) == 2)
		{
			return 2;
		}
		return 1;
	}
	else
	{
		return 2;
	}
}
