#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "oct.h"

int hextodec(char * n)
{
	int sum = 0, otrsum = 0 - sum;
	int i = 0;
	if (n[0] == '-')
	{
		i += 3;
	}
	else
	{
		i += 2;
	}
	for (i; i < strlen(n) - 1; i++)
	{      	
		if (n[i] == 'a')
		{
			sum += 10 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'b')
		{
			sum += 11 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'c')
		{
			sum += 12 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'd')
		{
			sum += 13 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'e')
		{
			sum += 14 * pow(16, strlen(n) - i - 2);
		}
		else if (n[i] == 'f')
		{
			sum += 15 * pow(16, strlen(n) - i - 2);
		}
		else
		{
			if (isdigit(n[i]) != 0)
			{	
				sum += (int)(n[i] - '0') * pow(16, strlen(n) - i - 2);
			}
			else
			{
				printf("ERROR\n");
				exit(1);
			}
		}
	}
	if (n[0] == '-')
	{	
		return -sum;
	}
	return sum;
}

char* dectohex(int n)
{ 
	int lenght = 32;
	char* hexal = (char*)malloc(lenght * sizeof(char));
	if (n >= 0)
	{
		sprintf(hexal, "0x%x", abs(n));
	}
	else
	{
		sprintf(hexal, "-0x%x", abs(n));
	}
	return hexal;	
}	
