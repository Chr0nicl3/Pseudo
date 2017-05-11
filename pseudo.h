#include "y.tab.h"
typedef enum {typeInt, typeFloat, typeString, typeId, typeOpr } nodeEnum; 

/*strings*/
typedef struct{
	char *value;				/*value of string*/
} stringNodeType;

/*floats*/
typedef struct{
	float value;				/*value of integer*/
} floatNodeType;

/* integers */ 
typedef struct { 
	int value;                  /* value of integer */ 
} intNodeType; 

/* identifiers */ 
typedef struct { 
	int i;                      /* subscript to sym array */ 
} idNodeType; 

/* operators */ 
typedef struct { 
	int oper;                   /* operator */ 
	int nops;                   /* number of operands */ 
	struct nodeType *op[1];  /* operands, extended at runtime */ 
} oprNodeType; 

typedef struct nodeType { 
	nodeEnum type;              /* type of node */ 
	union { 
		stringNodeType str;		/*strings*/
		floatNodeType flt;		/*floats*/
		intNodeType con;        /* integers */ 
		idNodeType id;          /* identifiers */ 
		oprNodeType opr;        /* operators */ 
	}; 
} nodeType; 

typedef struct {
		enum{undef_type, int_type, float_type, string_type}type;
		
		union{
			int iValue;
			float fValue;
			char *sValue;
		};
}data ;

data sym[26];

void runtimeError(char *s){
	fprintf(stderr, "RunTime Error : %s %i:%i\n", s, lineCount, colCount);
}