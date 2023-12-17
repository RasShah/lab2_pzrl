#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bin.h"

int bintodec(const char * n)
{
	int sum = 0;
	if (strlen(n) == 2 && n[0] == '0')
	{
		return 0;
	}
	int i = 0;
	if (n[0] == '-')
	{
		i += 1;
	}
	for (i; i < strlen(n) - 1; i++)
	{
		if (n[i] == '1')
		{
			sum += pow(2, strlen(n) - i - 2);
		}
		else if (n[i] != '1' && n[i] != '0')
		{
			printf("input or type ERROR\n");
			exit(1);
		}
	}
	if (n[0] == '-')
	{
		return -sum;
	}	
	return sum;
}
char* dectobin(int n)
{ 
	int flag = 0;
	if (n < 0)
	{
		flag = 1;
		n = abs(n);
	}
	else if (n == 0)
	{
		return "0";
	}
	int lenght = 32;
	char* binary = (char*)malloc(lenght * sizeof(char));
	if (binary == NULL)
	{
		exit(1);
	}
	int indexx = 0;
	while (n > 0 && indexx < lenght - 1)
	{
		binary[indexx++] = (char)(n % 2 + '0');
		n /= 2;
	}
	if (flag == 1)
	{
		binary[indexx] = '-';
		binary[indexx + 1] = '\0';
		indexx++;
	}
	else
	{
		binary[indexx] = '\0';
	}
	int start = 0;
	int end = indexx - 1;
	while (start < end)
	{
		char temp = binary[start];
		binary[start] = binary[end];
		binary[end] = temp;
		start++;
		end--;
	}
	return binary;
}
