// KanyeWest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>

#define EFE 0
#define RDI
#define RDD
#define RDS
#define RDB
#define RDC
#define RDIV
#define RDDV
#define RDSV
#define RDBV
#define RDCV
#define PRTM
#define PRTI
#define PRTD
#define PRTS
#define PRTB
#define PRTC
#define PRTIV
#define PRTDV
#define PRTSV
#define PRTBV
#define PRTCV
#define PUSHI
#define PUSHD
#define PUSHS
#define PUSHB
#define PUSHC
#define PUSHKI
#define PUSHKD
#define PUSHKS
#define PUSHKB
#define PUSHKC
#define POPI
#define POPD
#define POPS
#define POPB
#define POPC
#define POPIV
#define POPDV
#define POPSV
#define POPBV
#define POPCV
#define SUM
#define SUB
#define MULT
#define DIV
#define MOD
#define AND
#define OR
#define XOR
#define MAX
#define MIN
#define INCI
#define INCD
#define INCC
#define DECI
#define DECD
#define DECC
#define BRANCH
#define CMPLE
#define CMPL
#define CMPGE
#define CMPG
#define CMPE
#define CMPNE
#define BRNCHC
#define JMPT
#define JEZ
#define JNZ
#define JMZ
#define JMEZ
#define JLZ
#define JLEZ

int main(int argc)
{
	str
	if (!loadFile())
	{
		running();
	}
	else
	{

	}
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

bool loadFile()
{

}

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

void running()
{
	while (1 != 0)//SegmentoDeCodigo[Puntero]!=Null o 0 o final) <---Fixfix
	{
		switch (EFE)//SegmentoDeCodigo[Puntero])
		{
		case EFE:
			break;
		}
		case 
	}
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
