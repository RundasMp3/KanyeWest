// KanyeWest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
int main()
{

}
//11 bytes header
#define MAX_STACK 100
short int TOS;
st_stack STACK[MAX_STACK];


struct st_stack {
	char tipo;
	union {
		short int dir;
		int entero;
		double doble;
		char* apuntador;
		char caracter;
	}dato;
};


int verificarHeader(char *s)
{
	return compareTo("ICC2020", s);
}

int compareTo(const char *a, char *b)
{
	while (*a)
	{
		if (*a++ != *b++)
			return 0;
	}
	return 1;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
