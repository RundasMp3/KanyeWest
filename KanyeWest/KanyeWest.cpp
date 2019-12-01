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

void printbinchar(char c)
{
	for (int i = 7; i >= 0; --i)
	{
		putchar((c & (1 << i)) ? '1' : '0');
	}
	putchar('\n');
}


void lemmeSee()
{
	FILE* pFile;
	long lSize;
	char* buffer;
	size_t result;

	pFile = fopen("perhap.ye", "rb");
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }


	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (char*)malloc(sizeof(char) * lSize);
	if (buffer == NULL) { fputs("Memory error", stderr); exit(2); }

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("Reading error", stderr); exit(3); }

	/* the whole file is now loaded in the memory buffer. */
	fread(buffer, 1, 7, pFile);

	// terminate
	fclose(pFile);
	free(buffer);

	typedef unsigned char uint8;
	std::ifstream source("perhap.ye", std::ios_base::binary);

	while (source) {
		std::ios::pos_type before = source.tellg();
		unsigned char x;
		x = source.get();
		int int8 = 0;
		int8 = x;
		std::cout << int8 << "\t";
		printbinchar(x);
		std::ios::pos_type after = source.tellg();
	}
}

#pragma region stack uwu
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

void _stackprintEverything(st_stack* stack)
{
	if (!isEmpty(stack))
	{
		printNodeContent(pop(stack));
		return _stackprintEverything(stack);
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

	_stackprintEverything(stack);
	//printf("%d popped from stack\n", pop(stack).dato.doble);

	return 0;
}
#pragma endregion

#pragma region Variables
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

int main(int argc, char** argv)
{
	printf("\nBINARY VALUES\n");

	lemmeSee();
	printf("\n");
	FILE* fp;
	char* buffer = NULL;// [131081];
	char* sc;
	char* sd;
	//errno_t err;
	st_stack* stack = createStack(100); //struct st_stack stack;
	long filend;

	fopen_s(&fp, "C:\\Users\\beto_\\Downloads\\zoinksWhileImprimirBuenPointer.ye", "rb");

	//char i = fread(buffer, 1, 11, fp);
	fseek(fp, 0, SEEK_END);
	filend = ftell(fp);
	rewind(fp);
	buffer = (char*)malloc((filend + 1) * sizeof(char)); // Enough memory for file + \0
	fread(buffer, filend, 1, fp); // Read in the entire file
	fclose(fp); // Close the file
	buffer[filend] = '\0';

	//
	if (!verificarHeader(buffer))
	{
		printf("INVALID HEADER\n");
	}
	else
	{
		printf("VALID FILE\n");
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
	printf("DATA SEGMENT\n");
	for (int i = 0; i < TSD; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}

	
}


//11 bytes header





#define MAX_STACK 100
short int TOS;
st_node STACK[MAX_STACK];


int ConvertirShortInt(char* a)
{
	return atoi(a);//	No convierte short a int, sino que lo trata de leer char como int desde el principio, checa si sirve despues
}

bool loadFile()
{
	return true;
}

int verificarHeader(char* s)
{
	return compareTo("ICC2020", s);
}


int compareTo(const char* a, char* b)
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
	/*printf("DATA SEGMENT\n");
	for (int i = 0; i < 4; i++)
	{
		printf("ins\t%d\tdir%d\n", sd[i], i);
	}*/
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


	
	
}


void EscribirIntenDir(unsigned int n, char* sd, int dir)
{
	unsigned char bytes[4];
	//unsigned int n;
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
	//double n;
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
	st_node nodo2 = pop(stack);
	st_node aux;
	if (nodo.tipo == 's')
	{
		switch (nodo2.tipo)
		{
		case 'i':
		{
			char* integer_string = (char*)malloc(10 * sizeof(char));
			sprintf(integer_string, "%d", nodo2.dato.entero);
			aux.dato.apuntador = (char*)malloc(sizeof(nodo.dato.apuntador) + sizeof(integer_string));
			strcpy(aux.dato.apuntador, nodo.dato.apuntador);
			strcat(aux.dato.apuntador, integer_string);
			aux.tipo = 's';
		}
		break;
		case 'd':
		{
		char* double_string = (char*)malloc(255*sizeof(char) - sizeof(nodo.dato.apuntador));
		if(sizeof(nodo))
		sprintf(double_string, "%.10G", nodo2.dato.doble);
		aux.dato.apuntador = (char*)malloc(sizeof(nodo.dato.apuntador) + sizeof(double_string));
		strcpy(aux.dato.apuntador, nodo.dato.apuntador);
		strcat(aux.dato.apuntador, double_string);
		aux.tipo = 's';
		}
			break;
		case 'c':
			aux.dato.apuntador = (char*)malloc(sizeof(nodo.dato.apuntador) + sizeof(nodo2.dato.caracter));
			aux.dato.apuntador[sizeof(nodo.dato.apuntador)] = nodo2.dato.caracter;
			aux.tipo = 's';
			break;
		case 's':
			aux.dato.apuntador = (char*)malloc(sizeof(nodo.dato.apuntador) + sizeof(nodo2.dato.apuntador));
			strcpy(aux.dato.apuntador, nodo.dato.apuntador);
			strcat(aux.dato.apuntador, nodo2.dato.apuntador);
			aux.tipo = 's';
			
			//TODO: SUM string
			break;
		
		default:
			break;
		}
	}
	else if (nodo2.tipo == 's')
	{
		switch (nodo.tipo)
		{
		case 'i':
		{
			char* integer_string = (char*)malloc(10 * sizeof(char));
			sprintf(integer_string, "%d", nodo.dato.entero);
			aux.dato.apuntador = (char*)malloc(sizeof(nodo2.dato.apuntador) + sizeof(integer_string));
			strcpy(aux.dato.apuntador, nodo2.dato.apuntador);
			strcat(aux.dato.apuntador, integer_string);
			aux.tipo = 's';
		}
			break;
		case 'd':
		{
			char* double_string = (char*)malloc(10 * sizeof(char));
			sprintf(double_string, "%.10G", nodo.dato.doble);
			aux.dato.apuntador = (char*)malloc(sizeof(nodo2.dato.apuntador) + sizeof(double_string));
			strcpy(aux.dato.apuntador, nodo2.dato.apuntador);
			strcat(aux.dato.apuntador, double_string);
			aux.tipo = 's';
		}
			break;
		case 'c':
			aux.dato.apuntador = (char*)malloc(sizeof(nodo2.dato.apuntador) + sizeof(nodo.dato.caracter));
			strcpy(aux.dato.apuntador, nodo2.dato.apuntador);
			aux.dato.apuntador[sizeof(nodo2.dato.apuntador)] = nodo.dato.caracter;
			aux.tipo = 's';
			break;

		default:
			break;
		}
	
	}
	else if (nodo.tipo == 'd')
	{
		if (nodo2.tipo == 'i')
		{
			aux.dato.doble = nodo.dato.doble + (double)nodo2.dato.entero;
			aux.tipo = 'd';
		}
		else if (nodo2.tipo == 'd')
		{
			aux.dato.doble = nodo.dato.doble + nodo2.dato.doble;
		}
		else if (nodo2.tipo == 'c')
		{
			aux.dato.doble = nodo.dato.doble + (double)nodo2.dato.caracter;
		}

	}
	else if (nodo2.tipo == 'd')
	{
		if (nodo.tipo == 'i')
		{
			aux.dato.doble = nodo2.dato.doble + (double)nodo.dato.entero;
			aux.tipo = 'd';
		}
		else if (nodo.tipo == 'd')
		{
			aux.dato.doble = nodo2.dato.doble + nodo.dato.doble;
			aux.tipo = 'd';
		}
		else if (nodo.tipo == 'c')
		{
			aux.dato.doble = nodo2.dato.doble + (double)nodo.dato.caracter;
			aux.tipo = 'd';
		}
	}
	else if (nodo.tipo == 'i')
	{
		if(nodo2.tipo == 'i')
		{
			aux.tipo = 'i';
			aux.dato.entero = nodo.dato.entero + nodo2.dato.entero;
		}
		else if (nodo2.tipo == 'c')
		{
			aux.tipo = 'i';
			aux.dato.entero = nodo.dato.entero + (int)nodo2.dato.caracter;
		}
	}
	else if (nodo2.tipo == 'i')
	{
		aux.tipo = 'i';
		aux.dato.entero = (int)nodo.dato.caracter + nodo2.dato.entero;
	}
	else
	{
		aux.tipo = 'c';
		aux.dato.caracter = nodo.dato.caracter + nodo2.dato.caracter;
	}
	
	push(stack, aux);
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

void MINVAR(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero < node2.dato.entero)
		{
			push(stack, node1);
		}
		else
		{
			push(stack, node2);
		}
		break;
	case 'd':
		if (node1.dato.doble < node2.dato.doble)
		{
			push(stack, node1);
		}
		else
		{
			push(stack, node2);
		}
		break;
	case 'c':
		if (node1.dato.caracter < node2.dato.caracter)
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

void INCVARI(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.entero++;
	printf("SUMVALUE:\t%d", nodo.dato.entero);
	push(stack, nodo);
}

void INCVARD(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.doble++;
	printf("SUMVALUE:\t%f", nodo.dato.doble);
	push(stack, nodo);
}

void INCVARC(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.caracter++;
	printf("SUMVALUE:\t%a", nodo.dato.doble);
	push(stack, nodo);
}

void DECVARI(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.entero--;
	printf("SUMVALUE:\t%d", nodo.dato.entero);
	push(stack, nodo);
}

void DECVARD(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.doble--;
	printf("SUMVALUE:\t%f", nodo.dato.doble);
	push(stack, nodo);
}

void DECVARC(st_stack* stack)
{
	st_node nodo = pop(stack);
	nodo.dato.caracter--;
	printf("SUMVALUE:\t%a", nodo.dato.doble);
	push(stack, nodo);
}

void CMPVARLE(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	bool value = false;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero <= node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble <= node2.dato.doble)
		{
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter <= node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf goes here
		break;
	}
}

void CMPVARL(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero < node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble < node2.dato.doble)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter < node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf goes here
		break;
	}
}

void CMPVARGE(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero >= node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble >= node2.dato.doble)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter >= node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf goes here
		break;
	}
}

void CMPVARG(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero > node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble > node2.dato.doble)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter > node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf goes here
		break;
	}
}

void CMPVARE(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero == node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble == node2.dato.doble)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter == node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf goes here
		break;
	}
}

void CMPVARNE(st_stack* stack)
{
	st_node node1;
	st_node node2;
	node1 = pop(stack);
	node2 = pop(stack);

	st_node result;
	result.tipo = 'c';
	switch (node1.tipo)
	{
	case 'i':
		if (node1.dato.entero != node2.dato.entero)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'd':
		if (node1.dato.doble != node2.dato.doble)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 'c':
		if (node1.dato.caracter != node2.dato.caracter)
		{
			//result = true;
			result.dato.caracter = true;
			push(stack, result);
		}
		else
		{
			//result = false;
			result.dato.caracter = false;
			push(stack, result);
		}
		break;
	case 's':
		//wtf 
		break;
	}
}

void PRTVAR(int dir, char* sd, char type)
{
	switch (type)
	{
	case 'i':
	{
		int valuei = 0;
		valuei = (valuei << 8) + sd[dir++];
		valuei = (valuei << 8) + sd[dir++];
		valuei = (valuei << 8) + sd[dir++];
		valuei = (valuei << 8) + sd[dir];
		printf("%d", valuei);
	}
		break;
	case 'd':
	{
		double valued = 0;
		//pc++;
		//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
		char* value = (char*)malloc(8 * sizeof(char));
		for (int i = 0; i < 8; i++)
		{
			value[i] = sd[++dir];
		}
		memcpy(&valued, value, sizeof(double));
		printf("%f", valued);
	}
		break;
	case 'c':
		printf("%a", sd[dir]);
		break;
	case 's':
	{
		char* str = (char*)malloc(255 * sizeof(char));
		for (int i = 0; i < 256; i++)
		{
			str[i] = sd[i + dir];
		}
		printf("%a", str);
	}
		break;
	default:
		break;
	}
}

void running(char* sc, int pc, char* sd, st_stack* stack)
{
	printf("CURRENTLY RUNNING:\t%d\tdir %d\n", sc[pc], pc);
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
			dir += index * 4;
			LeerYEscribirIntenDir(sd, dir);
			break;
		case RDDV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index * 8;
			LeerYEscribirDoubleenDir(sd, dir);
			break;
		case RDSV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index * 256;
			LeerYEscribirCharenDir(sd, dir);
			break;
		case RDBV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index * 1;
			LeerYEscribirCharenDir(sd, dir);
			break;
		case RDCV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index * 1;
			
			LeerYEscribirCharenDir(sd, dir);
			break;
		case PRTM:
			dir = (int)(sc[++pc]); //Aqui se usa para ver el tamaño del string
			for (int i = 0; i < dir; i++)
			{
				printf("%a", sc[++pc]);
			}
			break;
		case PRTI:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			PRTVAR(dir, sd, 'i');
			break;
		case PRTD:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			PRTVAR(dir, sd, 'd');
			break;
		case PRTS:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			PRTVAR(dir, sd, 's');
			break;
		case PRTB:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			PRTVAR(dir, sd, 'c');
			break;
		case PRTC:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			PRTVAR(dir, sd, 'c');
			break;
		case PRTIV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += 4 * index;
			PRTVAR(dir, sd, 'i');
			break;
		case PRTDV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += 8 * index;
			PRTVAR(dir, sd, 'd');
			break;
		case PRTSV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += 255 * index;
			PRTVAR(dir, sd, 's');
			break;
		case PRTBV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index;
			PRTVAR(dir, sd, 'c');
			break;
		case PRTCV:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index;
			PRTVAR(dir, sd, 'c');
			break;
		case PUSHI:
			valuei = 0;
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
			valuei = (valuei << 8) + sd[dir++];
			valuei = (valuei << 8) + sd[dir++];
			valuei = (valuei << 8) + sd[dir++];
			valuei = (valuei << 8) + sd[dir];
			nodo.tipo = 'i';
			nodo.dato.entero = valuei;
			push(stack, nodo);
			break;
		case PUSHD:
		{
			valued = 0;
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			//pc++;
			//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
			char* value = (char*)malloc(8 * sizeof(char));
			for (int i = 0; i < 8; i++)
			{
				value[i] = sd[++dir];
			}
			memcpy(&valued, value, sizeof(double));
			nodo.tipo = 'd';
			nodo.dato.doble = valued;
			push(stack, nodo);
		}
			break;
		case PUSHS:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			nodo.tipo = 's';
			nodo.dato.apuntador = (char*)malloc(255 * sizeof(char));
			push(stack, nodo);
			for (int i = 0; i < 255; i++)
			{
				nodo.dato.apuntador[i] = sd[dir++];
			}
			push(stack, nodo);
			break;
		case PUSHB:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);

			nodo.tipo = 'c';
			nodo.dato.caracter = sd[dir];
			push(stack, nodo);

			break;
		case PUSHC:
			dir = (int)((sc[++pc] << 8) | sc[++pc]);

			nodo.tipo = 'c';
			nodo.dato.caracter = sd[dir];
			push(stack, nodo);
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
		{
			valued = 0;
			//pc++;
			//value = value | sc[pc++] | sc[pc++] | sc[pc++] | sc[pc];
			char* value = (char*)malloc(8 * sizeof(char));
			for (int i = 0; i < 8; i++)
			{
				value[i] = sc[++pc];
			}
			memcpy(&valued, value, sizeof(double));
			nodo.tipo = 'd';
			nodo.dato.doble = valued;
			push(stack, nodo);
		}
			break;
		case PUSHKS:
			nodo.tipo = 's';
			nodo.dato.apuntador = (char*)malloc(255 * sizeof(char));
			push(stack, nodo);
			for (int i = 0; i < 255; i++)
			{
				nodo.dato.apuntador[i] = sc[++pc];
			}
			push(stack, nodo);
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
			nodo = pop(stack);
			EscribirIntenDir(nodo.dato.entero, sd, dir);
			break;
		case POPD:
			if (top(stack).tipo != 'd')
			{
				printf("NO DOUBLE AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			nodo = pop(stack);
			EscribirDoubleenDir(nodo.dato.doble, sd, dir);
			break;
		case POPS:
			if (top(stack).tipo != 's')
			{
				printf("NO BOOL AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			nodo = pop(stack);
			//EscribirIntenDir(nodo.dato.apuntador, sd, dir); //TODO: POP STRING
			break;
		case POPB:
			if (top(stack).tipo != 'c')
			{
				printf("NO BOOL AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			nodo = pop(stack);
			EscribirCharenDir(nodo.dato.caracter, sd, dir);
			break;
		case POPC:
			if (top(stack).tipo != 'c')
			{
				printf("NO CHAR AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			nodo = pop(stack);
			EscribirCharenDir(nodo.dato.caracter, sd, dir);
			break;
		case POPIV:
			if (top(stack).tipo != 'i')
			{
				printf("NO INT AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index * 4;
			nodo = pop(stack);
			EscribirIntenDir(nodo.dato.entero, sd, dir);
			break;
		case POPDV:
			if (top(stack).tipo != 'd')
			{
				printf("NO DOUBLE AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += 8 * index;
			nodo = pop(stack);
			EscribirDoubleenDir(nodo.dato.doble, sd, dir);
			break;
		case POPSV:
			if (top(stack).tipo != 's')
			{
				printf("NO STRING AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += 255 * index;
			nodo = pop(stack);
			//EscribirDoubleenDir(nodo.dato.doble, sd, dir);
			break;
		case POPBV:
			if (top(stack).tipo != 'b')
			{
				printf("NO BOOL AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index;
			nodo = pop(stack);
			EscribirCharenDir(nodo.dato.caracter, sd, dir);
			break;
		case POPCV:
			if (top(stack).tipo != 'c')
			{
				printf("NO CHAR AT TOP OF STACK.");
			}
			dir = (int)((sc[++pc] << 8) | sc[++pc]);
			dir += index;
			nodo = pop(stack);
			EscribirCharenDir(nodo.dato.caracter, sd, dir);
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
		{
			nodo.tipo = 'c';
			nodo.dato.caracter = pop(stack).dato.caracter & pop(stack).dato.caracter;
			if (nodo.dato.caracter == true)
			{
				printf("true");
			}
			else if (nodo.dato.caracter == false)
			{
				printf("false");
			}
			push(stack, nodo);
		}
			break;
		case OR:
			nodo.tipo = 'c';
			nodo.dato.caracter = pop(stack).dato.caracter | pop(stack).dato.caracter;
			if (nodo.dato.caracter == true)
			{
				printf("true");
			}
			else if (nodo.dato.caracter == false)
			{
				printf("false");
			}
			push(stack, nodo);
			break;
		case XOR:

			break;
		case MAX:
			MAXVAR(stack);
			break;
		case MIN:
			MINVAR(stack);
			break;
		case INCI:
			INCVARI(stack);
			break;
		case INCD:
			INCVARD(stack);
			break;
		case INCC:
			INCVARC(stack);
			break;
		case DECI:
			DECVARI(stack);
			break;
		case DECD:
			DECVARD(stack);
			break;
		case DECC:
			DECVARD(stack);
			break;
		case BRANCH:

			break;
		case CMPLE:
			CMPVARLE(stack);
			break;
		case CMPL:
			CMPVARL(stack);
			break;
		case CMPGE:
			CMPVARGE(stack);
			break;
		case CMPG:
			CMPVARG(stack);
			break;
		case CMPE:
			CMPVARE(stack);
			break;
		case CMPNE:
			CMPVARNE(stack);
			break;
		case IDX:
			index = pop(stack).dato.entero;
			break;
		case BRNCHC:
			dir = (int)((sc[++pc]) | sc[++pc]);;
			nodo = pop(stack);
			if (nodo.dato.caracter == true)
			{
				pc = dir;
				pc--;
			}
			break;


		default:
			printf("UNKNOWN INS\n");

			break;
		}
		pc++;
		running(sc, pc, sd, stack);
	}
	else
	{
		printf("STACK CONTENT\n");
		_stackprintEverything(stack);
		printf("\n");
		return;
		
	}
}
