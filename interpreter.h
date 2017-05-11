#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "y.tab.h"

regex_t regex;
regmatch_t matches[1];
data re; 				//return variable
data temp;				//temporary variable
int status, numchars; // regex variables
char *tempLog; 		//strchr variable (used in print-string)
char stmt[100];		//undefined identifiers error statement used variable in identifier type
char *in;
data ex(nodeType *p){
	char *match = malloc(sizeof(char));		//regex variable
	char *dest = malloc(sizeof(char));		//regex variable
	data d1, d2;
	re.type = int_type;
	re.iValue = 0;
	if(!p){
		return re;
	}
	switch(p->type){

		/*identifiers*/
		case typeId:
			temp.type = sym[p->id.i].type;
			switch(temp.type){
				case int_type:
					temp.iValue = sym[p->id.i].iValue;
					break;
				case float_type:
					temp.fValue = sym[p->id.i].fValue;
					break;
				case string_type:
					temp.sValue = sym[p->id.i].sValue;
					break;
				case undef_type:
					snprintf(stmt, 100, "Variable '%c' used but not defined :", p->id.i+'a');
					runtimeError(stmt);
					exit(1);
			} 
			return temp;

		/*integer numbers*/
		case typeInt:
			temp.type = int_type;
			temp.iValue = p->con.value;
			return temp;

		/*floating point numbers*/
		case typeFloat:
			temp.type = float_type;
			temp.fValue = p->flt.value;
			return temp;

		/*strings*/
		case typeString:
			/* used regex to match only the part of string between " & " */
			memset(match, '\0', sizeof(match));
			memset(dest, '\0', sizeof(dest));
			status = regcomp(&regex, "\"[^\"\n]*[\"]", 0);
			status = regexec(&regex,p->str.value,1,matches,0);
			numchars = (int)matches[0].rm_eo - (int)matches[0].rm_so;
			match = realloc(match, numchars*sizeof(char));
			dest = realloc(dest, numchars*sizeof(char));
            strncpy(match,p->str.value+matches[0].rm_so,numchars);
            match[numchars] = '\0';
            strncpy(dest, 1+match, strlen(match)-2);
			temp.type = string_type;
			temp.sValue = dest;
			return temp;

		/*operators*/
		case typeOpr:
			switch(p->opr.oper){

				case NEW_LINE:
					ex(p->opr.op[0]);
					return ex(p->opr.op[1]);

				/*IO Statements*/

				case PRINT:
					d1 = ex(p->opr.op[0]);
					switch(d1.type){
						case int_type:
							printf("%i", d1.iValue);
							return re;
						case float_type:
							printf("%f", d1.fValue);
							return re;
						case string_type:
							/* since '/' and 'n' are matched as separate tokens in lexer
								find the location of '\'&'n' usign strchr() and 
								replace them with ' '&'\n'*/ 
							tempLog = strchr(d1.sValue, '\\n');
							while(tempLog!=NULL){
								if((tempLog=strchr(d1.sValue,'\\'))){
								    if(*++tempLog=='n'){
								        *tempLog='\n';
								        *(tempLog-1)=' ';
								    }
								}
							}
							printf("%s", d1.sValue);
							return re;
					}

				case INPUT:
					if(p->opr.op[0]->str.value=="int"){
						sym[p->opr.op[1]->id.i].type = int_type;
						scanf("%i", &sym[p->opr.op[1]->id.i].iValue);
					}
					else if(p->opr.op[0]->str.value=="float"){
						sym[p->opr.op[1]->id.i].type = float_type;
						scanf("%f", &sym[p->opr.op[1]->id.i].fValue);
					}
					else if(p->opr.op[0]->str.value=="string"){
						int ch;
						while ((ch=getchar()) != EOF && ch != '\n');
						sym[p->opr.op[1]->id.i].type = string_type;
						sym[p->opr.op[1]->id.i].sValue = malloc(1);
						int i=0; int c;
						while((c = getchar())!='\n'){
							sym[p->opr.op[1]->id.i].sValue[i++] = c;
							sym[p->opr.op[1]->id.i].sValue = realloc(sym[p->opr.op[1]->id.i].sValue, i+1); // Add space for another character to be read.
						}
						sym[p->opr.op[1]->id.i].sValue[i] = '\0';
						// scanf("%s", &sym[p->opr.op[1]->id.i].sValue);
						// puts("reached here");
					}
					return re;

				/*IO Statemtents end*/

				/*basic constructs*/

				case WHILE:
					d1 = ex(p->opr.op[0]);
					switch(d1.type){
						case int_type:
							// printf("%i\n", d1.iValue);
							while(ex(p->opr.op[0]).iValue)
								ex(p->opr.op[1]);
							return re;
						case float_type:
							while(ex(p->opr.op[0]).fValue)
								ex(p->opr.op[1]);
							return re;
						case string_type:
							while(ex(p->opr.op[0]).sValue)
								ex(p->opr.op[1]);
							return re;	
					}

				case FOR:
				 	d1 = ex(p->opr.op[1]);
				 	d2 = ex(p->opr.op[2]);
				 	int t1, t2;
				 	t1 = d1.iValue;
				 	t2 = d2.iValue;
					sym[p->opr.op[0]->id.i].type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						if(t1<t2)
							for(sym[p->opr.op[0]->id.i].iValue=t1; sym[p->opr.op[0]->id.i].iValue<t2; ++sym[p->opr.op[0]->id.i].iValue){
								ex(p->opr.op[3]);
							}
						else
							for(sym[p->opr.op[0]->id.i].iValue=t1; sym[p->opr.op[0]->id.i].iValue>t2; --sym[p->opr.op[0]->id.i].iValue)
								ex(p->opr.op[3]);
					}
					return re;

				case IF:
					d1 = ex(p->opr.op[0]);
					if(d1.iValue){
						ex(p->opr.op[1]);
						return re;
					}
					if(p->opr.nops>2){
						ex(p->opr.op[2]);
						return re;
					}

				/*constructs end*/

				case BREAK:
					if(p->opr.op[0]>0)
						printf("%s\n", "valid");
					return re;

				case CONTINUE:
					if(p->opr.op[0]>0)
						printf("%s\n", "valid");
					return re;

				/*arithmetic operators*/

				case '+':
					if(p->opr.nops>1){
						d1 = ex(p->opr.op[0]);
						d2 = ex(p->opr.op[1]);
						if(d1.type==float_type && d2.type==int_type){
							temp.type = float_type;
							temp.fValue = d1.fValue + d2.iValue;
						}
						else if(d1.type==int_type && d2.type==float_type){
							temp.type = float_type;
							temp.fValue = d1.iValue + d2.fValue;
						}
						else if(d1.type==float_type && d2.type==float_type){
							temp.type = float_type;
							temp.fValue = d1.fValue + d2.fValue;
						}
						else if(d1.type==int_type && d2.type==int_type){
							temp.type = int_type;
							temp.iValue = d1.iValue + d2.iValue;
						}
						// printf("%i------%i-------%i\n", temp.iValue, d1.iValue, d2.iValue);
						return temp;
					}
					else
						return ex(p->opr.op[0]);

				case '-':
					if(p->opr.nops>1){
						d1 = ex(p->opr.op[0]);
						d2 = ex(p->opr.op[1]);
						if(d1.type==float_type && d2.type==int_type){
							temp.type = float_type;
							temp.fValue = d1.fValue - d2.iValue;
						}
						else if(d1.type==int_type && d2.type==float_type){
							temp.type = float_type;
							temp.fValue = d1.iValue - d2.fValue;
						}
						else if(d1.type==float_type && d2.type==float_type){
							temp.type = float_type;
							temp.fValue = d1.fValue - d2.fValue;
						}
						else if(d1.type==int_type && d2.type==int_type){
							temp.type = int_type;
							temp.iValue = d1.iValue - d2.iValue;
						}
						return temp;
					}
					else{
						d1 = ex(p->opr.op[0]);
						switch(d1.type){
							case int_type:
								temp.type = int_type;
								temp.iValue = -d1.iValue;
								return temp;

							case float_type:
								temp.type = float_type;
								temp.fValue = -d1.fValue;
								return temp;

							default:
								runtimeError("Wrong data type with unary operator '-' :");
								exit(1);
								break;
						}
					}

				case '*':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					if(d1.type==float_type && d2.type==int_type){
						temp.type = float_type;
						temp.fValue = d1.fValue * d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.type = float_type;
						temp.fValue = d1.iValue * d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.type = float_type;
						temp.fValue = d1.fValue * d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.type = int_type;
						temp.iValue = d1.iValue * d2.iValue;
					}
					return temp;

				case '/':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					switch(d2.type){
						case int_type:
							if(d2.iValue==0){
								runtimeError("Divide by 0 :");
								exit(1);
							}
							break;

						case float_type:
							if(d2.fValue==0){
								runtimeError("Divide by 0 :");
								exit(1);
							}
							break;							
					}
					if(d1.type==float_type && d2.type==int_type){
						temp.type = float_type;
						temp.fValue = d1.fValue / d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.type = float_type;
						temp.fValue = d1.iValue / d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.type = float_type;
						temp.fValue = d1.fValue / d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						if(d1.iValue%d2.iValue!=0){
							temp.type = float_type;
							temp.fValue = d1.iValue / d2.iValue;
						}
						else{
							temp.type = int_type;
							temp.iValue = d1.iValue / d2.iValue;
						}
					}
					return temp;

				case '%':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue % d2.iValue;
					}
					else{
						runtimeError("Wrong data type with '\%' operator :");
						exit(1);
					}
					return temp;

				/*arithmetic operators end*/

				/*assignment operators*/

				case '=':
					d1 = ex(p->opr.op[1]);
					switch(d1.type){
						case int_type:
							sym[p->opr.op[0]->id.i].type = int_type;
							sym[p->opr.op[0]->id.i].iValue = d1.iValue;
							// printf("%i\n", temp.iValue);
							return re;

						case float_type:
							sym[p->opr.op[0]->id.i].type = float_type;
							sym[p->opr.op[0]->id.i].fValue = d1.fValue;
							return re;

						case string_type:
							// printf("%s--------\n", d1.sValue);
							sym[p->opr.op[0]->id.i].type = string_type;
							sym[p->opr.op[0]->id.i].sValue = d1.sValue;
							return re;
					}

				case ADD_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					if(d1.type==float_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue + d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.iValue + d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue + d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = int_type;
						sym[p->opr.op[0]->id.i].iValue = d1.iValue + d2.iValue;
					}
					return re;

				case SUB_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					if(d1.type==float_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue - d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.iValue - d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue - d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = int_type;
						sym[p->opr.op[0]->id.i].iValue = d1.iValue - d2.iValue;
					}
					return re;

				case MUL_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					if(d1.type==float_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue * d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.iValue * d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue * d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = int_type;
						sym[p->opr.op[0]->id.i].iValue = d1.iValue * d2.iValue;
					}
					return re;

				case DIV_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					switch(d2.type){
						case int_type:
							if(d2.iValue==0){
								runtimeError("Divide by 0 :");
								exit(1);
							}
							break;

						case float_type:
							if(d2.fValue==0){
								runtimeError("Divide by 0 :");
								exit(1);
							}
							break;							
					}
					if(d1.type==float_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue / d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.iValue / d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						sym[p->opr.op[0]->id.i].type = float_type;
						sym[p->opr.op[0]->id.i].fValue = d1.fValue / d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].type = int_type;
						sym[p->opr.op[0]->id.i].iValue = d1.iValue / d2.iValue;
					}
					return re;

				case MOD_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					sym[p->opr.op[0]->id.i].type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].iValue = d1.iValue % d2.iValue;
					}
					else{
						runtimeError("Wrong data type with '\%' operator :");
						exit(1);
					}
					return re;

				case OR_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					sym[p->opr.op[0]->id.i].type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].iValue = d1.iValue | d2.iValue;
					}
					else{
						runtimeError("Wrong data type with '|' operator :");
						exit(1);
					}
					return re;

				case AND_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					sym[p->opr.op[0]->id.i].type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].iValue = d1.iValue & d2.iValue;
					}
					else{
						runtimeError("Wrong data type with '&' operator :");
						exit(1);
					}
					return re;

				case XOR_ASSIGN:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					sym[p->opr.op[0]->id.i].type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						sym[p->opr.op[0]->id.i].iValue = d1.iValue ^ d2.iValue;
					}
					else{
						runtimeError("Wrong data type with '^' operator :");
						exit(1);
					}
					return re;

				/*assignment operators end*/

				/*relatinal operators*/

				case '>':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue > d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue > d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue > d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue > d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue > *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '>' operator :");
						exit(1);
					}
					return temp;

				case '<':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue < d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue < d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue < d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue < d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue < *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '<' operator :");
						exit(1);
					}
					return temp;

				case LE_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue <= d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue <= d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue <= d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue <= d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue <= *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '<=' operator :");
						exit(1);
					}
					return temp;

				case GE_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue >= d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue >= d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue >= d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue >= d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue >= *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '>=' operator :");
						exit(1);
					}
					return temp;

				case EQ_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue == d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue == d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue == d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue == d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue == *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '==' operator :");
						exit(1);
					}
					return temp;

				case NE_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==float_type && d2.type==int_type){
						temp.iValue = d1.fValue != d2.iValue;
					}
					else if(d1.type==int_type && d2.type==float_type){
						temp.iValue = d1.iValue != d2.fValue;
					}
					else if(d1.type==float_type && d2.type==float_type){
						temp.iValue = d1.fValue != d2.fValue;
					}
					else if(d1.type==int_type && d2.type==int_type){
						temp.iValue = d1.iValue != d2.iValue;
					}
					else if(d1.type==string_type && d2.type==string_type){
						temp.iValue = *d1.sValue != *d2.sValue;
					}
					else{
						runtimeError("incompatible data type for '!=' operator :");
						exit(1);
					}
					return temp;

				/*relational operators end*/

				/*unary operators*/

				case PRE_INC_OP:
					switch(sym[p->opr.op[0]->id.i].type){
						case int_type:
							sym[p->opr.op[0]->id.i].iValue += 1;
							break; 
						case float_type:
							sym[p->opr.op[0]->id.i].fValue += 1;
							break;
						case string_type:
							sym[p->opr.op[0]->id.i].sValue += 1;
							break;
					}
					return re;

				case PRE_DEC_OP:
					switch(sym[p->opr.op[0]->id.i].type){
						case int_type:
							sym[p->opr.op[0]->id.i].iValue -= 1;
							break; 
						case float_type:
							sym[p->opr.op[0]->id.i].fValue -= 1;
							break;
						case string_type:
							sym[p->opr.op[0]->id.i].sValue -= 1;
							break;
					}
					return re;

				case POST_INC_OP:
					return re;

				case POST_DEC_OP:
					return re;

				case '!':
					temp.type = int_type;
					temp.iValue  = 0;
					temp.sValue = NULL;
					temp.fValue = 0;
					return temp;


				/*unary operators end*/

				/* logical operators */

				case AND_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					temp.iValue = d1 && d2;
					return temp;

				case OR_OP:
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					temp.iValue = d1||d2;
					return temp;
				/*logical operators end*/

				/*bitwise operators */

				case '|':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						return d1|d2;
					}
					else
						runtimeError("Invalid operands to binary '|' ");
					return re;

				case '^':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						return d1^d2;
					}
					else
						runtimeError("Invalid operands to binary '^' ");
					return re;

				case '&':
					d1 = ex(p->opr.op[0]);
					d2 = ex(p->opr.op[1]);
					temp.type = int_type;
					if(d1.type==int_type && d2.type==int_type){
						return d1&d2;
					}
					else
						runtimeError("Invalid operands to binary '&' ");
					return re;

				default:
					runtimeError("Undefined Operator : ");
					exit(1);

			}
	}
	return re;
}