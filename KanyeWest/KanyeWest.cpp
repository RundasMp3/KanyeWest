// KanyeWest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#pragma region defines

#define EFE 0
#define RDI 1
#define RDD	2
#define RDS	3
#define RDB	4
#define RDC	5
#define RDIV 6
#define RDDV 7
#define RDSV 8
#define RDBV 9
#define RDCV 10
#define PRTM 11
#define PRTI 12
#define PRTD 13
#define PRTS 14
#define PRTB 15
#define PRTC 16
#define PRTIV 17
#define PRTDV 18
#define PRTSV 19
#define PRTBV 20
#define PRTCV 21
#define PUSHI 22
#define PUSHD 23
#define PUSHS 24
#define PUSHB 25
#define PUSHC 26
#define PUSHKI 27
#define PUSHKD 28
#define PUSHKS 29
#define PUSHKB 30
#define PUSHKC 31
#define POPI 32
#define POPD 33
#define POPS 34
#define POPB 35
#define POPC 36
#define POPIV 37
#define POPDV 38
#define POPSV 39
#define POPBV 40
#define POPCV 41
#define SUM 42
#define SUB 43
#define MULT 44
#define DIV 45
#define MOD 46
#define AND 47
#define OR 48
#define XOR 49
#define MAX 50
#define MIN 51
#define INCI 52
#define INCD 53
#define INCC 54
#define DECI 55
#define DECD 56
#define DECC 57
#define BRANCH 58
#define CMPLE 59
#define CMPL 60
#define CMPGE 61
#define CMPG 62
#define CMPE 63
#define CMPNE 64
#define IDX 64
#define BRNCHC 66
#pragma endregion


int main(int argc)
{
	FILE *fp;
	char buffer[131081];
	char *sc;
	char *sd;
	int pc = 0;//deberia comenzar en 11, creo
	fp = fopen("file.txt", "w+");
	char i = fread(buffer, 1, 11, fp);
	if (!verificarHeader(buffer))
	{
		printf("Howow! Bwad headew smh");
	}
	int TSC = ConvertirShortInt(&buffer[7]);
	int TSD = ConvertirShortInt(&buffer[9]);
	sc = (char*)malloc(TSC);
	sd = (char*)malloc(TSD);
	i = fread(sc, 1, TSC, fp);
	int TOS = -1;
	int PC = 0;
	while (!sc[pc])//SegmentoDeCodigo[Puntero]!=Null o 0 o final) <---Fixfix
	{
		switch (*(sc+pc))//SegmentoDeCodigo[Puntero])
		{
		case RDI:
			scanf("@d", &x);
			break;
		case EFE:
			break;
		default:
			printf("Howow! incowect code unu");
			break;
		}
	}
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

int ConvertirShortInt(char *a)
{
	return atoi(a);//	No convierte short a int, sino que lo trata de leer char como int desde el principio, checa si sirve despues
}

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
