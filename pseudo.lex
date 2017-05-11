%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char *);
int lineCount=1;
int colCount = 0;
char buffer[1024];

void count();
void copy();
%}

%x comments

newLine		[\n]
space		[ \t]
letter		[a-zA-Z]
digit		[0-9]
id 			({letter})({letter}|{digit}|_)*
number 		{digit}+
real		{digit}+(\.{digit}+)?([Ee][-+]?{digit}+)?
relOp		(<|>|<=|>=|==|!=|&&|\|\|)
constBegin	(if)|(else)|(while)|(for)|(repeat)
constEnd	(endif)|(endwhile)|(endfor)|(until)

%%

"continue"						{count();copy();return(CONTINUE);}
"to"							{count();copy();return(TO);}
"if"							{count();copy();return(IF);}
"else"							{count();copy();return(ELSE);}
"end"							{count();copy();return(END);}
"for"							{count();copy();return(FOR);}
"repeat"						{count();copy();return(REPEAT);}
"until"							{count();copy();return(UNTIL);}
"while"							{count();copy();return(WHILE);}
"return"						{count();copy();return(RETURN);}
"break"							{count();copy();return(BREAK);}
"input"							{count();copy();return(INPUT);}
"print"							{count();copy();return(PRINT);}
"int"							{
									count();copy();
									yylval.sValue="int";
									return(INT);
								}
"float"							{
									count();copy();
									yylval.sValue="float";
									return(FLOAT);
								}
"string"						{
									count();copy();
									yylval.sValue="string";
									return(STRING);
								}
{newLine}+						{
									colCount=0;
									lineCount++;
									return(NEW_LINE);
								}
{space}							{count();copy();}
{id}							{
									count();copy();
									yylval.sIndex = *yytext - 'a';
									return(IDENTIFIER);
								}
{number}						{
									count();copy();
									yylval.iValue=atoi(yytext);
									return(NUM);
								}
{real}							{
									count();copy();
									yylval.fValue=atof(yytext);
									return(REAL);
								}
\"[^"\n]*["]					{
									count();copy();
									yylval.sValue=yytext;
									return(STRING_LITERAL);
								}
"<"								{count();copy();return('<');}
">"								{count();copy();return('>');}
"&"								{count();copy();return('&');}
"|"								{count();copy();return('|');}
"^"								{count();copy();return('^');}
"~"								{count();copy();return('~');}
"!"								{count();copy();return('!');}
"+"								{count();copy();return('+');}
"-"								{count();copy();return('-');}
"/"								{count();copy();return('/');}
"%"								{count();copy();return('%');}
"="								{count();copy();return('=');}
"("								{count();copy();return('(');}
")"								{count();copy();return(')');}
"["								{count();copy();return('[');}
"]"								{count();copy();return(']');}
"?"								{count();copy();return('?');}
":"								{count();copy();return(':');}
"=="							{count();copy();return(EQ_OP);}
"!="							{count();copy();return(NE_OP);}
"++"							{count();copy();return(INC_OP);}
"--"							{count();copy();return(DEC_OP);}
"<="							{count();copy();return(LE_OP);}
">="							{count();copy();return(GE_OP);}
"**"							{count();copy();return(POW_OP);}
"&&"							{count();copy();return(AND_OP);}
"||"							{count();copy();return(OR_OP);}
"+="							{count();copy();return(ADD_ASSIGN);}
"-="							{count();copy();return(SUB_ASSIGN);}
"*="							{count();copy();return(MUL_ASSIGN);}
"/="							{count();copy();return(DIV_ASSIGN);}
"%="							{count();copy();return(MOD_ASSIGN);}
"&="							{count();copy();return(AND_ASSIGN);}
"^="							{count();copy();return(XOR_ASSIGN);}
"|="							{count();copy();return(OR_ASSIGN);}


%{
/*dealing whith comments*/
%}
\/\*																{BEGIN(comments);}
<comments>{newLine}+												{lineCount++;}
<comments>({letter}|{number}|{real}|{space}|{relOp})+	 			{;}
<comments>\*+/[^\/]													{;}
<comments>\*\/														{BEGIN(INITIAL);}

%{
/*comments section over*/
%}

%%

int yywrap(void){
	return 1;
}

void copy(){
	strncpy(buffer, yytext, sizeof(buffer));
}

void count(){
	colCount+=yyleng;
}