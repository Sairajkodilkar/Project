#ifndef _PARSE
#define _PARSE

#include <stdio.h>
#include <stdlib.h>
#include <limit.h>
#include <string.h>
#include "num.h"

enum states {START, OPERATOR, NUMBER, FRAC, SPACE, END, ERR};

typedef struct token{
	int type;
	union{
		num number;
		char op;
	}data;
}token;

void inittok(token *t);
token getnext(char *string);

#endif 