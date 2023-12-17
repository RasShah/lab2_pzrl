#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "oct.h"

int octtodec(const char * n)
{
	int sum = 0;
	int i = 0;
	if (n[0] == '-')
	{
		i = i + 1;
	}
	for (i; i < strlen(n) - 1; i++)
	{       if (isdigit(n[i]) != 0 && (int)(n[i] - '0') < 8)	
		{	
			sum += (int)(n[i] - '0') * pow(8, strlen(n) - i - 2); 
		}
		else
		{
			printf("ERROR.\n");
			exit(1);
		}
	}
	if (n[0] == '-')
	{	
		return -sum;
	}
	return sum;
}

char* dectooct(int n)
{
	int lenght = 32;
	char* octal = (char*)malloc(lenght * sizeof(char));
	if (n >= 0)
	{	
		sprintf(octal, "0%o", abs(n));
	}
	else
	{
		sprintf(octal, "-0%o", abs(n));
	}
	return octal;
}
