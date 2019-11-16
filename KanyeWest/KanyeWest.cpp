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
#define IDX 65
#define BRNCHC 66
#pragma endregion



#pragma region stwack uwu
struct st_node {
	char tipo;
	union {
		short int dir;
		int entero;
		double doble;
		char* apuntador;
		char caracter;
	}dato;
	int* dir;

};

struct st_stack {
	int capacity;
	st_node* array;
	int top;
};

struct st_stack* createStack(unsigned capacity)
{
	struct st_stack* stack = (struct st_stack*)malloc(sizeof(struct st_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (st_node*)malloc(stack->capacity * sizeof(st_node));
	return stack;
}

int isFull(struct st_stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1 
int isEmpty(struct st_stack* stack)
{
	return stack->top == -1;
}

void push(struct st_stack* stack, st_node item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;

	//printf("%d pushed to stack\n", item);
}

st_node pop(struct st_stack* stack)
{
	st_node nulo;
	nulo.tipo = 'n';

	if (isEmpty(stack))
		return nulo;
	return stack->array[stack->top--];
}

st_node top(struct st_stack* stack) {
	st_node nulo;
	nulo.tipo = 'n';

	if (isEmpty(stack))
		return nulo;
	return stack->array[stack->top];
}

void printNodeContent(st_node item)
{
	switch (item.tipo)
	{
	case 'i':
		printf("%d top of stack\n", item.dato.entero);
		break;
	case 'c':
		printf("%c top of stack\n", item.dato.caracter);
		break;
	case 'd':
		printf("%f top of stack\n", item.dato.doble);
		break;
	case 's':
		printf("%d top of stack\n", item.dato.dir);
		break;
	}
}

void printErrthang(st_stack* stack)
{
	if (!isEmpty(stack))
	{
		printNodeContent(pop(stack));
		return printErrthang(stack);
	}
	else
		return;
}

int Test() {
	struct st_stack* stack = createStack(100);
	st_node node;

	node.tipo = 'i';
	node.dato.entero = 10;
	push(stack, node);

	node.tipo = 'c';
	node.dato.caracter = 'c';
	push(stack, node);
	node.tipo = 'd';
	node.dato.doble = 10.3;
	push(stack, node);

	printErrthang(stack);
	//printf("%d popped from stack\n", pop(stack).dato.doble);

	return 0;
}
#pragma endregion

#pragma region Vawables
struct tb_Variable {
	tb_Variable* Next;
	short dir;
	uint16_t size;
	char type;
	char* name;
	st_node* value;
};

struct tb_Variable* getLatest(tb_Variable* first) {
	if (first->Next == nullptr) {
		return first;
	}
	else {
		return getLatest(first->Next);
	}
};

struct tb_Table {
	tb_Variable* First;

};

struct tb_Table* createTable(tb_Variable* first)
{
	struct tb_Table* table = (struct tb_Table*)malloc(sizeof(struct tb_Table));
	table->First = first;
	return table;
}

void AddVariable(tb_Table* table, tb_Variable* newVariable) {
	getLatest(table->First)->Next = newVariable;
}
#pragma endregion


int index = 0;
int verificarHeader(char*);
int ConvertirShortInt(char*);
bool loadFile();
void running(char*, int, char*, st_stack*);
int compareTo(const char*, char*);

int main(int argc)
{
	FILE *fp;
	char *buffer = NULL;// [131081];
	char *sc;
	char *sd;
	//errno_t err;
	st_stack* stack = createStack(100); //struct st_stack stack;
	long filend;

	fopen_s(&fp, "test.ye", "rb");
	
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

	int TSC = (int)((buffer[7]) | buffer[8]);
	int TSD = (int)((buffer[9]) | buffer[10]);
	//stack->dato = ((buffer[9] << 8) | buffer[10]);
	sc = (char*)malloc(TSC * sizeof(char*));
	sd = (char*)malloc(TSD * sizeof(char*));

	for (int i = 0; i <= TSC; i++)
	{
		sc[i] = buffer[i + 11];
		printf("ins\t%d\tdir%d\n", sc[i], i);
	}
	printf("\n");
	for (int i = 0; i < TSD; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
	printf("\n");

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


	running(sc, PC, sd, createStack(100));

}


//11 bytes header





#define MAX_STACK 100
short int TOS;
st_node STACK[MAX_STACK];


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
	if (*a)
	{
		if (*a++ != *b++)
			return 0;
		else
			return compareTo(a, b);
	}
	else
		return 1;
	
	while (*a)
	{
		if (*a++ != *b++)
			return 0;
	}
	return 1;
}

void LeerYEscribirIntenDir(char* sd, int dir)
{
	unsigned char bytes[4];
	unsigned int n;
	scanf_s("%d", &n);
	//Get each byte value from int.
	bytes[3] = (n >> 24) & 0x000000FF;
	bytes[2] = (n >> 16) & 0x0000FF00;
	bytes[1] = (n >> 8) & 0x00FF0000;
	bytes[0] = n & 0xFF;

	int Int32 = 0;

	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = bytes[3];
	sd[dir++] = bytes[2];
	sd[dir++] = bytes[1];
	sd[dir++] = bytes[0];

	Int32 = bytes[0] | bytes[1] | bytes[2] | bytes[3];
	printf("%d", bytes[0]);
	printf("%d", bytes[3]);
	printf("\n");
	printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
}

void LeerYEscribirDoubleenDir(char* sd, int dir)
{
	unsigned char bytes[8];
	double n;
	scanf_s("%f", &n);
	//Get each byte value from int.
	/*bytes[7] = (n >> 52) & 0x00000000000000FF;
	bytes[6] = (n >> 48) & 0x000000000000FF00;
	bytes[5] = (n >> 40) & 0x0000000000FF0000;
	bytes[4] = (n >> 32) & 0x00000000FF000000;
	bytes[3] = (n >> 24) & 0x000000FF00000000;
	bytes[2] = (n >> 16) & 0x0000FF0000000000;
	bytes[1] = (n >> 8)  & 0x00FF000000000000;
	bytes[0] = n & 0xFF;*/

	int Int32 = 0;

	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = bytes[3];
	sd[dir++] = bytes[2];
	sd[dir++] = bytes[1];
	sd[dir++] = bytes[0];

	Int32 = bytes[0] | bytes[1] | bytes[2] | bytes[3];
	printf("%d", bytes[0]);
	printf("%d", bytes[3]);
	printf("\n");
	printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
}

void LeerYEscribirCharenDir(char* sd, int dir)
{
	unsigned char n;
	scanf_s("%a", &n);
	//Get each byte value from int.



	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = n;


	printf("%a", n);
	printf("\n");
	printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
}


void EscribirIntenDir(unsigned int n, char* sd, int dir)
{
	unsigned char bytes[4];
	unsigned int n;
	//Get each byte value from int.
	bytes[3] = (n >> 24) & 0x000000FF;
	bytes[2] = (n >> 16) & 0x0000FF00;
	bytes[1] = (n >> 8) & 0x00FF0000;
	bytes[0] = n & 0xFF;

	int Int32 = 0;

	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = bytes[3];
	sd[dir++] = bytes[2];
	sd[dir++] = bytes[1];
	sd[dir++] = bytes[0];

	//Debugging flags
	//Int32 = bytes[0] | bytes[1] | bytes[2] | bytes[3];
	//printf("%d", bytes[0]);
	//printf("%d", bytes[3]);
	//printf("\n");
	//printf("DATA SEGMENT\n");
	//for (int i = 0; i < 4; i++)
	//{
	//	printf("ins\t%d\tdir%d\n", sd[i], i);
	//}
}

void EscribirDoubleenDir(double n, char* sd, int dir)
{
	unsigned char bytes[8];
	double n;
	//Get each byte value from int.
	/*bytes[7] = (n >> 52) & 0x00000000000000FF;
	bytes[6] = (n >> 48) & 0x000000000000FF00;
	bytes[5] = (n >> 40) & 0x0000000000FF0000;
	bytes[4] = (n >> 32) & 0x00000000FF000000;
	bytes[3] = (n >> 24) & 0x000000FF00000000;
	bytes[2] = (n >> 16) & 0x0000FF0000000000;
	bytes[1] = (n >> 8)  & 0x00FF000000000000;
	bytes[0] = n & 0xFF;*/

	int Int32 = 0;

	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = bytes[3];
	sd[dir++] = bytes[2];
	sd[dir++] = bytes[1];
	sd[dir++] = bytes[0];

	Int32 = bytes[0] | bytes[1] | bytes[2] | bytes[3];
	printf("%d", bytes[0]);
	printf("%d", bytes[3]);
	printf("\n");
	printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
}

void EscribirCharenDir(unsigned char n, char* sd, int dir)
{
	//Get each byte value from int.



	/*Int32 = (Int32 << 8) + bytes[3]; //UNCOMMENT TO DEBUG VALUE
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];*/

	sd[dir++] = n;


	printf("%a", n);
	printf("\n");
	printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}
}

void ConvertShortToByte(unsigned int n, std::ofstream& outfile)
{
	unsigned char bytes[2];
	//Get each byte value from short.
	bytes[1] = n & 0xFF;
	outfile << bytes[0];
	outfile << bytes[1];

	int Int16 = 0;

	Int16 = (Int16 << 8) + bytes[1];
	Int16 = (Int16 << 8) + bytes[0];
}

void ConvertDoubleToByte(double* n, std::ofstream& outfile)
{
	unsigned char bytes[4];

	char* ptrByte = (char*)n;


	outfile << n;

}

void SUMVARS(st_stack* stack)
{
	st_node nodo = pop(stack);
	st_node aux = pop(stack);
	switch (nodo.tipo)
	{
	case 'i':
		nodo.dato.entero += aux.dato.entero;
		printf("SUMVALUE:\t%d", nodo.dato.entero);

		break;
	case 'd':
		nodo.dato.doble += aux.dato.doble;
		printf("SUMVALUE:\t%f", nodo.dato.doble);

		break;
	case 'c':
		nodo.dato.caracter += aux.dato.caracter;
		printf("SUMVALUE:\t%a", nodo.dato.caracter);

		break;
	case 's':
		//TODO: SUM string
		break;

	}
	push(stack, nodo);
}

void SUBVARS(st_stack* stack)
{
	st_node nodo = pop(stack);
	st_node aux = pop(stack);
	switch (nodo.tipo)
	{
	case 'i':
		nodo.dato.entero -= aux.dato.entero;
		printf("SUB VALUE:\t%d", nodo.dato.entero);

		break;
	case 'd':
		nodo.dato.doble -= aux.dato.doble;
		printf("SUB VALUE:\t%f", nodo.dato.doble);

		break;
	case 'c':
		nodo.dato.caracter -= aux.dato.caracter;
		printf("SUB VALUE:\t%a", nodo.dato.caracter);

		break;
	case 's':
		//TODO: SUM string
		break;

	}
	push(stack, nodo);
}

void MULTVARS(st_stack* stack)
{
	st_node nodo = pop(stack);
	st_node aux = pop(stack);
	switch (nodo.tipo)
	{
	case 'i':
		nodo.dato.entero *= aux.dato.entero;
		printf("MULT VALUE:\t%d", nodo.dato.entero);

		break;
	case 'd':
		nodo.dato.doble *= aux.dato.doble;
		printf("MULT VALUE:\t%f", nodo.dato.doble);

		break;
	case 'c':
		nodo.dato.caracter *= aux.dato.caracter;
		printf("MULT VALUE:\t%a", nodo.dato.caracter);

		break;
	case 's':
		//TODO: SUM string
		break;

	}
	push(stack, nodo);
}

void DIVVARS(st_stack* stack)
{
	st_node nodo = pop(stack);
	st_node aux = pop(stack);
	switch (nodo.tipo)
	{
	case 'i':
		nodo.dato.entero /= aux.dato.entero;
		printf("DIV VALUE:\t%d", nodo.dato.entero);

		break;
	case 'd':
		nodo.dato.doble /= aux.dato.doble;
		printf("DIV VALUE:\t%f", nodo.dato.doble);

		break;
	case 'c':
		nodo.dato.caracter /= aux.dato.caracter;
		printf("DIV VALUE:\t%a", nodo.dato.caracter);

		break;
	case 's':
		//TODO: SUM string
		break;

	}
	push(stack, nodo);
}

void MAXVAR(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero > node2.dato.entero)
		{
			push(stack, node1);
		}
		else
		{
			push(stack, node2);
		}
		break;
	case 'd':
		if (node1.dato.doble > node2.dato.doble)
		{
			push(stack, node1);
		}
		else
		{
			push(stack, node2);
		}
		break;
	case 'c':
		if (node1.dato.caracter > node2.dato.caracter)
		{
			push(stack, node1);
		}
		else
		{
			push(stack, node2);
		}
		break;
	case 's':
		//TODO: SUM string
		break;

	}
}

void running(char* sc, int pc, char* sd, st_stack* stack)
{
	printf("BACK IN CYCLE \n");
	for (int i = 0; i <= 16; i++)
	{
		printf("ins\t%d\tdir%d\n", sc[i], i);

	}
	printf("CURRENTLY Running\tins %d\tdir %d\n", sc[pc], pc);
	if (sc[pc] != EFE)
	{
		int dir = 0;
		int valuei = 0;
		st_node nodo;
		double valued = 0;
		switch (sc[pc])//*(sc + pc))//SegmentoDeCodigo[Puntero])
		{
			case EFE:
				break;
			case RDI:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);
				
				LeerYEscribirIntenDir(sd, dir);
				break;
			case RDD:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);

				LeerYEscribirIntenDir(sd, dir);
				break;
				break;
			case RDS:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);

				LeerYEscribirIntenDir(sd, dir);
				break;
			case RDB:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);

				LeerYEscribirCharenDir(sd, dir);
				break;
			case RDC:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);

				LeerYEscribirCharenDir(sd, dir);
				break;
			case RDIV:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);
				dir += index;
				LeerYEscribirIntenDir(sd, dir);
				break;
			case RDDV:
				dir = (int)((sc[++pc] << 8) | sc[++pc]);
				dir += index;
				LeerYEscribirDoubleenDir(sd, dir);
				break;
			case RDSV:
				
				break;
			case RDBV:
				
				break;
			case RDCV:
				
				break;
			case PRTM:
				
				break;
			case PRTI:
				
				break;
			case PRTD:
				
				break;
			case PRTS:
				
				break;
			case PRTB:
				
				break;
			case PRTC:
				
				break;
			case PRTIV:
				
				break;
			case PRTDV:
				
				break;
			case PRTSV:
				
				break;
			case PRTBV:
				
				break;
			case PRTCV:
				
				break;
			case PUSHI:
				
				break;
			case PUSHD:
				
				break;
			case PUSHS:
				
				break;
			case PUSHB:
				printf("PUSHB\n");
				
				break;
			case PUSHC:
				
				break;
			case PUSHKI:
				valuei = 0;
				pc++;
				//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
				valuei = (valuei << 8) + sc[pc++];
				valuei = (valuei << 8) + sc[pc++];
				valuei = (valuei << 8) + sc[pc++];
				valuei = (valuei << 8) + sc[pc];
				nodo.tipo = 'i';
				nodo.dato.entero = valuei;
				push(stack, nodo);
				break;
			case PUSHKD:
				valued = 0;
				pc++;
				//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
				char* value = (char*)malloc(8 * sizeof(char));
				for (int i = 0; i < 8; i++)
				{
					value[i] = sc[pc++];
				}
				memcpy(&valued, value, sizeof(double));
				nodo.tipo = 'd';
				nodo.dato.entero = valued;
				push(stack, nodo);
				break;
			case PUSHKS:
				
				break;
			case PUSHKB:
				nodo.tipo = 'c';
				nodo.dato.caracter = sc[++pc];
				push(stack, nodo);
				break;
			case PUSHKC:
				nodo.tipo = 'c';
				nodo.dato.caracter = sc[++pc];
				push(stack, nodo);
				break;
			case POPI:
				if (top(stack).tipo != 'i')
				{
					printf("NO INT AT TOP OF STACK.");
				}
				dir = (int)((sc[++pc] << 8) | sc[++pc]);
				
				break;
			case POPD:
				if (top(stack).tipo != 'd')
				{
					printf("NO DOUBLE AT TOP OF STACK.");
				}
				break;
			case POPS:
				
				break;
			case POPB:
				if (top(stack).tipo != 'c')
				{
					printf("NO BOOL AT TOP OF STACK.");
				}
				break;
			case POPC:
				if (top(stack).tipo != 'c')
				{
					printf("NO CHAR AT TOP OF STACK.");
				}
				dir = (int)((sc[++pc] << 8) | sc[++pc]);
				
				break;
			case POPIV:
				if (top(stack).tipo != 'i')
				{
					printf("NO INT AT TOP OF STACK.");
				}
				break;
			case POPDV:
				if (top(stack).tipo != 'd')
				{
					printf("NO DOUBLE AT TOP OF STACK.");
				}
				break;
			case POPSV:
				if (top(stack).tipo != 's')
				{
					printf("NO STRING AT TOP OF STACK.");
				}
				break;
			case POPBV:
				if (top(stack).tipo != 'b')
				{
					printf("NO BOOL AT TOP OF STACK.");
				}
				break;
			case POPCV:
				if (top(stack).tipo != 'c')
				{
					printf("NO CHAR AT TOP OF STACK.");
				}
				break;
			case SUM:
				SUMVARS(stack);
				break;
			case SUB:
				SUBVARS(stack);
				break;
			case MULT:
				MULTVARS(stack);
				break;
			case DIV:
				DIVVARS(stack);
				break;
			case MOD:
				
				break;
			case AND:
				
				break;
			case OR:
				
				break;
			case XOR:
				
				break;
			case MAX:
				pop(stack)
				break;
			case MIN:
				
				break;
			case INCI:
				
				break;
			case INCD:
				
				break;
			case INCC:
				
				break;
			case DECI:
				
				break;
			case DECD:
				
				break;
			case DECC:
				
				break;
			case BRANCH:
				
				break;
			case CMPLE:
				
				break;
			case CMPL:
				
				break;
			case CMPGE:
				
				break;
			case CMPG:
				
				break;
			case CMPE:
				
				break;
			case CMPNE:
				
				break;
			case IDX:
				index = pop(stack).dato.entero;
				break;
			case BRNCHC:
				
				break;


			default:
				printf("Def\n");
				
				break;
		}
		pc++;
		running(sc, pc, sd, stack);
	}
	else
	{
		return;
	}
}
