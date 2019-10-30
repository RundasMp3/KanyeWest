#include "x69.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <array>

//struct variable {
//public:
//	char type;
//	uint16_t size;
//	uint16_t dir;
//	variable(char Type)
//	{
//		if (Type == 'I')
//			size = 4;
//		else if (Type == 'D')
//			size = 8;
//		else if (Type == 'C' || Type == 'B')
//			size = 1;
//		size = 1;
//		type = Type;
//		dir = CDP;
//		CDP += size;
//	}
//	variable(char Type, std::string value)
//	{
//		size = value.length;
//		dir = CDP;
//		type = Type;
//		CDP += size;
//	}
//};

uint16_t CDP = 0; //Current Data pointer
uint16_t CPP = 0; //Current Program Counter
char value[255];
uint16_t valueTop = 0; //Value that will tell us when to stop reading the variable.
//std::list<variable> Variables;

//bool FindVariable(char* name[], std::list<variable> list, int currentPos = 0)
//{
//	//if(name == list	)
//	if (currentPos >= list.size)
//		return false;
//		
//}
struct tb_Variable {
	tb_Variable* Next;
	short dir;
	uint16_t size;
	char type;
	char* name;

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




void convert(std::ifstream* owo, char type) {

	switch (type) //Conversion de variable
	{
	case 'I': //Integer 
		unsigned char value[4];
		for (int i = 0; i < 4; i++)
		{
			value[i] = owo->get();
		}

		break;
	case 'S':  //Short
		break;
	case 'C': //Char
		break;
	case 'B': //Bool
		break;
	case 'D': //Double
		break;

		break;
	default:
		break;
	}
}

void ConvertIntToByte(unsigned int n, std::ofstream& outfile)
{
	unsigned char bytes[4];
	//Get each byte value from int.
	bytes[0] = (n >> 24) & 0xFF;
	bytes[1] = (n >> 16) & 0xFF;
	bytes[2] = (n >> 8) & 0xFF;
	bytes[3] = n & 0xFF;

	int Int32 = 0;

	Int32 = (Int32 << 8) + bytes[3];
	Int32 = (Int32 << 8) + bytes[2];
	Int32 = (Int32 << 8) + bytes[1];
	Int32 = (Int32 << 8) + bytes[0];
	outfile << bytes[0];
	outfile << bytes[1];
	outfile << bytes[2];
	outfile << bytes[3];

}

void ConvertShortToByte(unsigned int n, std::ofstream& outfile)
{
	unsigned char bytes[2];
	//Get each byte value from short.
	bytes[0] = (n >> 8) & 0xFF;
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

void verify(char word[], std::ofstream& outfile)
{
	//std::string ins = word;
	uint8_t id;
	uint16_t dir;
	std::string Word(word);
	if (Word == "EFE")
	{
		id = HALT;
		outfile << id;
		CPP += 1;
	}
	else if (Word == "RDI")
	{
		id = RDI;
		dir = atoi(value);
		outfile << id;
		ConvertIntToByte(dir, outfile);
		CPP += 3;
	}
	else if (Word == "RDD")
	{
		id = RDD;
		char* pEnd;
		double d1;
		d1 = strtod(value, &pEnd);
		outfile << id;
		ConvertDoubleToByte(&d1, outfile);
		CPP += 3;
	}

	else if (Word == "RDS")
	{
		id = RDS;
	}

	else if (Word == "RDB")
	{
		id = RDB;
	}

	else if (Word == "RDC")
	{
		id = RDC;
	}

	else if (Word == "RDIV")
	{
		id = RDIV;
	}

	else if (Word == "RDDV")
	{
		id = RDDV;
	}

	else if (Word == "RDSV")
	{
		id = RDSV;
	}

	else if (Word == "RDBV")
	{
		id = RDBV;
	}

	else if (Word == "RDCV")
	{
		id = RDCV;
	}

	else if (Word == "PRTM")
	{
		id = PRTM;
	}

	else if (Word == "PRTI")
	{
		id = PRTI;
	}

	else if (Word == "PRTD")
	{
		id = PRTD;
	}

	else if (Word == "PRTS")
	{
		id = PRTS;
	}

	else if (Word == "PRTB")
	{
		id = PRTB;
	}

	else if (Word == "PRTC")
	{
		id = PRTC;
	}

	else if (Word == "PRTIV")
	{
		id = PRTIV;
	}

	else if (Word == "PRTDV")
	{
		id = PRTDV;
	}

	else if (Word == "PRTSV")
	{
		id = PRTSV;
	}

	else if (Word == "PRTBV")
	{
		id = PRTBV;
	}

	else if (Word == "PRTCV")
	{
		id = PRTCV;
	}

	else if (Word == "PUSHI")
	{
		id = PUSHI;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "PUSHD")
	{
		id = PUSHD;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "PUSHS")
	{
		id = PUSHS;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "PUSHB")
	{
		id = PUSHB;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "PUSHC")
	{
		id = PUSHC;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "PUSHKI")
	{
		id = PUSHKI;
		outfile << id;
		uint32_t val = atoi(value);
		ConvertIntToByte(val, outfile);
		CPP += 5;
	}

	else if (Word == "PUSHKD")
	{
		id = PUSHKD;
		char* pEnd;
		double d1;
		outfile << id;
		d1 = strtod(value, &pEnd);
		ConvertDoubleToByte(&d1, outfile);
		CPP += 5;
	}

	else if (Word == "PUSHKS")
	{
		id = PUSHKS;
		char* pEnd;
		double d1;
		outfile << id;
		outfile << valueTop;
		std::string message = std::string(value);
		outfile << message;
		CPP += 3 + valueTop;
	}

	else if (Word == "PUSHKB")
	{
		id = PUSHKB;
		outfile << id;
		uint8_t boolean;
		if (value[0] == '0')
			boolean = 0;
		else
			boolean = 255;
		outfile << boolean;
		CPP += 2;
	}

	else if (Word == "PUSHKC")
	{
		id = PUSHKC;
		id = PUSHKB;
		outfile << id;
		outfile << value[0];
		CPP += 2;
	}

	else if (Word == "POPI")
	{
		id = POPI;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPD")
	{
		id = POPD;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPS")
	{
		id = POPS;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPB")
	{
		id = POPB;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPC")
	{
		id = POPC;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPIV")
	{
		id = POPIV;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPDV")
	{
		id = POPDV;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPSV")
	{
		id = POPSV;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPBV")
	{
		id = POPBV;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPCV")
	{
		id = POPCV;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}

	else if (Word == "POPIDI")
	{
		id = POPIDI;
	}

	else if (Word == "POPIDD")
	{
		id = POPIDD;
	}

	else if (Word == "POPIDS")
	{
		id = POPIDS;
	}

	else if (Word == "POPIDB")
	{
		id = POPIDB;
	}

	else if (Word == "POPIDC")
	{
		id = POPIDC;
	}

	else if (Word == "SUM")
	{
		id = SUM;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "SUB")
	{
		id = SUB;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "MULT")
	{
		id = MULT;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "DIV")
	{
		id = DIV;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "MOD")
	{
		id = MOD;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "AND")
	{
		id = AND;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "OR")
	{
		id = OR;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "XOR")
	{
		id = XOR;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "MAX")
	{
		id = MAX;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "MIN")
	{
		id = MIN;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "INCI")
	{
		id = INCI;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "INCD")
	{
		id = INCD;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "INCC")
	{
		id = INCC;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "DECI")
	{
		id = DECI;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "DECD")
	{
		id = DECD;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "DECC")
	{
		id = DECC;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "NEGB")
	{
		id = NEGB;
		outfile << id;
		dir = CDP;
		CPP += 1;
	}

	else if (Word == "BRANCH")
	{
		id = BRANCH;
		outfile << id;
		dir = CDP;
		outfile << dir;
		CPP += 3;
	}


}

void skere(std::ifstream* owo, uint8_t ins, std::ofstream uwu)
{
	switch (ins)
	{
	case HALT:
		uwu << "HALT ";
		break;
	case RDI:
		uwu << "RDI \n";
		break;
	case RDD:
		uwu << "RDD ";
		break;
	case RDS:
		uwu << "RDS ";
		break;
	case RDB:
		uwu << "RDB ";
		break;
	case RDC:
		uwu << "RDC ";
		break;
	case RDIV:
		uwu << "RDIV ";
		break;
	case RDDV:
		uwu << "RDDV ";
		break;
	case RDSV:
		uwu << "RDSV ";
		break;
	case RDBV:
		uwu << "RDBV ";
		break;
	case RDCV:
		uwu << "RDCV ";
		break;
	case PRTM:
		uwu << "PRTM ";
		break;
	case PRTI:
		uwu << "PRTI ";
		break;
	case PRTD:
		uwu << "PRTD ";
		break;
	case PRTS:
		uwu << "PRTS ";
		break;
	case PRTB:
		uwu << "PRTB ";
		break;
	case PRTC:
		uwu << "PRTC ";
		break;
	case PRTIV:
		uwu << "PRTIV ";
		break;
	case PRTDV:
		uwu << "PRTDV ";
		break;
	case PRTSV:
		uwu << "PRTSV ";
		break;
	case PRTBV:
		uwu << "PRTBV ";
		break;
	case PRTCV:
		uwu << "PRTCV ";
		break;
	case VARI:
		uwu << "VARI ";
		break;
	case VARD:
		uwu << "VARD ";
		break;
	case VARS:
		uwu << "VARS ";
		break;
	case VARB:
		uwu << "VARB ";
		break;
	case VARC:
		uwu << "VARC ";
		break;
	case VARIV:
		uwu << "VARIV ";
		break;
	case VARDV:
		uwu << "VARDV ";
		break;
	case VARSV:
		uwu << "VARSV ";
		break;
	case VARBV:
		uwu << "VARBV ";
		break;
	case VARCV:
		uwu << "VARCV ";
		break;
	case PUSHI:
		uwu << "PUSHI ";
		break;
	case PUSHD:
		uwu << "PUSHD ";
		break;
	case PUSHS:
		uwu << "PUSHS ";
		break;
	case PUSHB:
		uwu << "PUSHB ";
		break;
	case PUSHC:
		uwu << "PUSHC ";
		break;
	case PUSHKI:
		uwu << "PUSHKI ";
		break;
	case PUSHKD:
		uwu << "PUSHKD ";
		break;
	case PUSHKS:
		uwu << "PUSHKS ";
		break;
	case PUSHKB:
		uwu << "PUSHKB ";
		break;
	case PUSHKC:
		uwu << "PUSHKC ";
		break;
	case POPI:
		uwu << "POPI ";
		break;
	case POPD:
		uwu << "POPD ";
		break;
	case POPS:
		uwu << "POPS ";
		break;
	case POPB:
		uwu << "POPB ";
		break;
	case POPC:
		uwu << "POPC ";
		break;
	case POPIV:
		uwu << "POPIV ";
		break;
	case POPDV:
		uwu << "POPDV ";
		break;
	case POPSV:
		uwu << "POPSV ";
		break;
	case POPBV:
		uwu << "POPBV ";
		break;
	case POPCV:
		uwu << "POPCV ";
		break;
	case POPIDI:
		uwu << "POPIDI ";
		break;
	case POPIDD:
		uwu << "POPIDD ";
		break;
	case POPIDS:
		uwu << "POPIDS ";
		break;
	case POPIDB:
		uwu << "POPIDB ";
		break;
	case POPIDC:
		uwu << "POPIDC ";
		break;
	case SUM:
		uwu << "SUM ";
		break;
	case SUB:
		uwu << "SUB ";
		break;
	case MULT:
		uwu << "MULT ";
		break;
	case DIV:
		uwu << "DIV ";
		break;
	case MOD:
		uwu << "MOD ";
		break;
	case AND:
		uwu << "AND ";
		break;
	case OR:
		uwu << "OR ";
		break;
	case XOR:
		uwu << "XOR ";
		break;
	case MAX:
		uwu << "MAX ";
		break;
	case MIN:
		uwu << "MIN ";
		break;
	case INCI:
		uwu << "INCI ";
		break;
	case INCD:
		uwu << "INCD ";
		break;
	case INCC:
		uwu << "INCC ";
		break;
	case DECI:
		uwu << "DECI ";
		break;
	case DECD:
		uwu << "DECD ";
		break;
	case DECC:
		uwu << "DECC ";
		break;
	case NEGB:
		uwu << "NEGB ";
		break;
	case BRANCH:
		uwu << "BRANCH ";
		break;
	}
}

int BakeItBaby() //ensamblador
{
	FILE* pFile;
	long lSize;
	char* buffer;
	size_t result;

	pFile = fopen("Test.qki", "rb");
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
	std::ifstream source("test.qki", std::ios_base::binary);
	std::stack <char> header;
	char instruction[6];
	char bufferedChar = ' ';
	for (int i = 0; i < 6; i++)
		instruction[i] = NULL;
	unsigned char instructioncount = 0;
	std::ofstream outfile("test.ye");
	bool ReadingIns = true;	//Bool to check if an instruction is being read or a value.
	//outfile << 1;
	uint8_t cont = 0;
	while (source) {
		std::ios::pos_type before = source.tellg();
		unsigned char x;
		x = source.get();
		std::ios::pos_type after = source.tellg();
		std::cout << (x);
		if (cont < 9) {
			cont++;
			if (cont < 8)
				outfile << (x);
			continue;
		}
		if (x == ' ')
		{
			ReadingIns = false;
			continue;
			//verify(instruction, outfile);
			//for (int i = 0; i < 6; i++)
			//	instruction[i] = NULL;
			//instructioncount = 0;

		}
		if (ReadingIns) {
			instruction[instructioncount] = x;
			instructioncount++;
		}
		else
		{
			//Logica para leer valor.
			if (bufferedChar != '\r' && x != '\n')
			{
				if (x == '\r')
					continue;
				value[valueTop] = x;
				valueTop++;
			}
			else
			{
				verify(instruction, outfile);
				for (int i = 0; i < 6; i++)
					instruction[i] = NULL;
				instructioncount = 0;
				for (int i = 0; i < valueTop; i++)
				{
					value[i] = NULL;
				}
				valueTop = 0;
				ReadingIns = true;
			}
		}

		if (bufferedChar == 10 && x == 13) //End of line reached
		{

		}
		bufferedChar = x;
	}

	outfile.close();


	return 0;
}

int OhShitGoBack() //desensamblador
{
	FILE* pFile;
	long lSize;
	char* buffer;
	size_t result;

	pFile = fopen("Test.qki", "rb");
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
	std::ifstream source("test.qki", std::ios_base::binary);
	char instruction[6];
	char bufferedChar = ' ';
	for (int i = 0; i < 6; i++) {
		instruction[i] = NULL;
	}
	std::ofstream outfile("test.ye");
	bool ReadingIns = true;	//Bool to check if an instruction is being read or a value.
	//outfile << 1;
	uint8_t cont = 0;
	while (source) {
		std::ios::pos_type before = source.tellg();
		unsigned char x;
		x = source.get();
		std::ios::pos_type after = source.tellg();
		std::cout << (x);
		if (cont < 11) {
			cont++;
			continue;
		}


		bufferedChar = x;
	}

	outfile.close();


	return 0;
}

#pragma region owo
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

int main()
{
	Test();
}





