#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculations.h"
#include "hex.h"
#include "oct.h"
#include "bin.h"

void main()
{
	char* input = NULL;
	size_t len = 0;
	char* num1 = NULL;
	char* num2 = NULL;
	char* operator = NULL;
	char* hex;
	char* oct;
	char* bin;
	getline(&input, &len, stdin);
	if (strchr(input, '~') != NULL)
	{
		num1 = input + 1;
		if (typeofn(num1) == 0)
		{
			hex = dectohex(tilde(hextodec(num1)));
			printf("%s \t (%i)\n", hex, tilde(hextodec(num1)));
			free(hex);
		}
		else if (typeofn(num1) == 1)
		{
			oct = dectooct(tilde(octtodec(num1)));
			printf("%s \t (%i)\n", oct, tilde(octtodec(num1)));
			free(oct);
		}
		else
		{
			bin = dectobin(tilde(bintodec(num1)));
			printf("%s \t (%i)\n", bin, tilde(bintodec(num1)));
			if (bin[0] != '0')
			{
				free(bin);
			}
		}
		free(input);
		exit(0);
	}
	char num1_buffer[100];
	char op_buff[2];
	char num2_buffer[100];
	sscanf(input, "%99s %1s %99s", num1_buffer, op_buff, num2_buffer);
	num1 = strdup(num1_buffer);
	operator = strdup(op_buff);
	num2 = strdup(num2_buffer);
	size_t len2 = strlen(num1);
	size_t len3 = strlen(num2);
	char* new_string = (char*)malloc(len2 + 2);
	char* new_string2 = (char*)malloc(len3 + 2);
	strcpy(new_string, num1);
	strcpy(new_string2, num2);
	new_string[len2] = '0';
	new_string2[len3] = '0';
	free(num1);
	free(num2);
	num1 = new_string;
	num2 = new_string2;
	
	if (typeofn(num1) != typeofn(num2))
	{
		printf("input or type ERROR\n");
		free(input);
		free(num1);
		free(num2);
		free(operator);
		exit(1);
	}
	if (*operator == '+')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(summ(hextodec(num1),hextodec(num2))); 
				printf("%s \t (%i)\n", hex, summ(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
			case 1:
				oct = dectooct(summ(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, summ(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
			case 2:
				bin = dectobin(summ(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, summ(bintodec(num1),bintodec(num2)));
				if (bin[0] != '0')
				{
					free(bin);
					break;
				}
		}
	}
	else if (*operator == '*')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(multi(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, multi(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
				
			case 1:
				oct = dectooct(multi(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, multi(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
				
			case 2:
				bin = dectobin(multi(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, multi(bintodec(num1),bintodec(num2)));
				if (bin[0] != '0')
				{
					free(bin);
					break;
				}
		}
	}	
	else if (*operator == '-')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(substr(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, substr(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
				
			case 1:
				oct = dectooct(substr(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, substr(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
				
			case 2:
				bin = dectobin(substr(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, substr(bintodec(num1),bintodec(num2)));
				if (bin[0] != '0')
				{
					free(bin);
					break;
				}
		}
	}
	else if (*operator == '%')
	{
		switch(typeofn(num1))
		{
			case 0:
				hex = dectohex(procent(hextodec(num1),hextodec(num2)));
				printf("%s \t (%i)\n", hex, procent(hextodec(num1),hextodec(num2)));
				free(hex);
				break;
			case 1:
				oct = dectooct(procent(octtodec(num1),octtodec(num2)));
				printf("%s \t (%i)\n", oct, procent(octtodec(num1),octtodec(num2)));
				free(oct);
				break;
			case 2:
				bin = dectobin(procent(bintodec(num1),bintodec(num2)));
				printf("%s \t (%i)\n", bin, procent(bintodec(num1),bintodec(num2)));
				if (bin[0] != '0')
				{
					free(bin);
					break;
				}
		}
	}
	else if (*operator == '&')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					hex = dectohex(ampersant(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, ampersant(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(ampersant(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, ampersant(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(ampersant(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, ampersant(bintodec(num1),bintodec(num2)));
					if (strlen(num1) == strlen(num2))
					{
						if (bin[0] != '0')
						{
							free(bin);
						}
					}
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*operator == '|')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					hex = dectohex(bitoder(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, bitoder(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(bitoder(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, bitoder(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(bitoder(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, bitoder(bintodec(num1),bintodec(num2)));
					if (bin[0] != '0')
					{
						free(bin);
					}
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	else if (*operator == '^')
	{
		if (num1[0] != '-' && num2[0] != '-')
		{	
			switch(typeofn(num1))
			{
				case 0:
					hex = dectohex(triangle(hextodec(num1),hextodec(num2)));
					printf("%s \t (%i)\n", hex, triangle(hextodec(num1),hextodec(num2)));
					free(hex);
					break;
				case 1:
					oct = dectooct(triangle(octtodec(num1),octtodec(num2)));
					printf("%s \t (%i)\n", oct, triangle(octtodec(num1),octtodec(num2)));
					free(oct);
					break;
				case 2:
					bin = dectobin(triangle(bintodec(num1),bintodec(num2)));
					printf("%s \t (%i)\n", bin, triangle(bintodec(num1),bintodec(num2)));
					if (bin[0] != '0')
					{
						free(bin);
					}
					break;
			}
		}	
		else
		{
			printf("ERROR\n");
		}
	}
	else
	{
		printf("ERROR\n");
	}
	free(input);
	free(num1);
	free(num2);
	free(operator);
	exit(0);
}
