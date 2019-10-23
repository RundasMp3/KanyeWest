// KanyeWest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <array>

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

int verificarHeader(char*);
int ConvertirShortInt(char*);
bool loadFile();
void running(char*, int);
int compareTo(const char*, char*);

struct st_stack {
	//char tipo;
	/*union {
		short int dir;
		int entero;
		double doble;
		char* apuntador;
		char caracter;
	}dato;*/
	union {
		uint8_t id;
		int Int32;
		unsigned char bytes[4];
	}u;
};




int main(int argc)
{
	FILE *fp;
	char *buffer = NULL;// [131081];
	char *sc;
	char *sd;
	//errno_t err;
	st_stack stack; //struct st_stack stack;
	long filend;

	fopen_s(&fp, "C:\\test2.ye", "rb");
	
	//char i = fread(buffer, 1, 11, fp);
	fseek(fp, 0, SEEK_END);
	filend = ftell(fp);
	rewind(fp);
	buffer = (char *)malloc((filend + 1) * sizeof(char)); // Enough memory for file + \0
	fread(buffer, filend, 1, fp); // Read in the entire file
	fclose(fp); // Close the file
	buffer[filend] = '\0';

	//
	if (!verificarHeader(buffer))
	{
		printf("Howow! Bwad headew smh\n");
	}
	else
	{
		printf("Gwood!\n");
	}

	//st_stack stack[17];

	int TSC = (int)((buffer[7] << 8) | buffer[8]);
	//stack->dato = ((buffer[9] << 8) | buffer[10]);
	sc = (char*)malloc(TSC);
	sd = (char*)malloc(TSC);

	if (sc == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	if (sd == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	//i = fread(sc, 1, TSC, fp);
	int TOS = -1;
	int PC = 0;//deberia comenzar en 11, creo


	for (int i = 0; i < filend; ++i)
	{
		fread(&stack, sizeof(struct st_stack), 1, fp);
		printf("Id:  %d\tInt:  %d\tbytes:  %d\n", stack.u.id, stack.u.Int32, stack.u.bytes);//"tipo:  %d\tapuntador:  %d\tcaracter:  %d\tdireccion: %d\tdoble: %d\tentero: %d\n", stack.tipo, stack.dato.apuntador, stack.dato.caracter, stack.dato.dir, stack.dato.doble, stack.dato.entero);
		printf("bytes:  %d\n", stack.u.bytes[0]);
		printf("bytes:  %d\n", stack.u.bytes[1]);
		printf("bytes:  %d\n", stack.u.bytes[2]);
		printf("bytes:  %d\n", stack.u.bytes[3]);
	}

	if (loadFile())
	{
		running(sc, PC);
	}
	else
	{

	}
}


//11 bytes header
#define MAX_STACK 100
short int TOS;
st_stack STACK[MAX_STACK];



int ConvertirShortInt(char *a)
{
	return atoi(a);//	No convierte short a int, sino que lo trata de leer char como int desde el principio, checa si sirve despues
}

bool loadFile()
{
	return true;
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

void running(char* sc, int pc)
{
	printf("Enhorabuena!\n");

	while (sc[pc] != 0)//SegmentoDeCodigo[Puntero]!=Null o 0 o final) <---Fixfix
	{
		switch (sc[pc])//*(sc + pc))//SegmentoDeCodigo[Puntero])
		{
		case EFE:
			break;
		case RDI:
			pc++;
			//scanf("@d", &x);
			break;
		case RDD:
			pc++;
			break;
		case RDS:
			pc++;
			break;
		case RDB:
			pc++;
			break;
		case RDC:
			pc++;
			break;
		case RDIV:
			pc++;
			break;
		case RDDV:
			pc++;
			break;
		case RDSV:
			pc++;
			break;
		case RDBV:
			pc++;
			break;
		case RDCV:
			pc++;
			break;
		case PRTM:
			pc++;
			break;
		case PRTI:
			pc++;
			break;
		case PRTD:
			pc++;
			break;
		case PRTS:
			pc++;
			break;
		case PRTB:
			pc++;
			break;
		case PRTC:
			pc++;
			break;
		case PRTIV:
			pc++;
			break;
		case PRTDV:
			pc++;
			break;
		case PRTSV:
			pc++;
			break;
		case PRTBV:
			pc++;
			break;
		case PRTCV:
			pc++;
			break;
		case PUSHI:
			pc++;
			break;
		case PUSHD:
			pc++;
			break;
		case PUSHS:
			pc++;
			break;
		case PUSHB:
			printf("PUSHB\n");
			pc++;
			break;
		case PUSHC:
			pc++;
			break;
		case PUSHKI:
			pc++;
			break;
		case PUSHKD:
			pc++;
			break;
		case PUSHKS:
			pc++;
			break;
		case PUSHKB:
			pc++;
			break;
		case PUSHKC:
			pc++;
			break;
		case POPI:
			pc++;
			break;
		case POPD:
			pc++;
			break;
		case POPS:
			pc++;
			break;
		case POPB:
			pc++;
			break;
		case POPC:
			pc++;
			break;
		case POPIV:
			pc++;
			break;
		case POPDV:
			pc++;
			break;
		case POPSV:
			pc++;
			break;
		case POPBV:
			pc++;
			break;
		case POPCV:
			pc++;
			break;
		case SUM:
			pc++;
			break;
		case SUB:
			pc++;
			break;
		case MULT:
			pc++;
			break;
		case DIV:
			pc++;
			break;
		case MOD:
			pc++;
			break;
		case AND:
			pc++;
			break;
		case OR:
			pc++;
			break;
		case XOR:
			pc++;
			break;
		case MAX:
			pc++;
			break;
		case MIN:
			pc++;
			break;
		case INCI:
			pc++;
			break;
		case INCD:
			pc++;
			break;
		case INCC:
			pc++;
			break;
		case DECI:
			pc++;
			break;
		case DECD:
			pc++;
			break;
		case DECC:
			pc++;
			break;
		case BRANCH:
			pc++;
			break;
		case CMPLE:
			pc++;
			break;
		case CMPL:
			pc++;
			break;
		case CMPGE:
			pc++;
			break;
		case CMPG:
			pc++;
			break;
		case CMPE:
			pc++;
			break;
		case CMPNE:
			pc++;
			break;
		case 65:
			pc++;
			break;
		case BRNCHC:
			pc++;
			break;

		default:
			printf("Def\n");
			pc++;
			break;
		}
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
