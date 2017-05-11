/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    NUM = 259,
    REAL = 260,
    STRING_LITERAL = 261,
    INT = 262,
    FLOAT = 263,
    STRING = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    POW_OP = 271,
    UMINUS = 272,
    POST_INC_OP = 273,
    PRE_INC_OP = 274,
    POST_DEC_OP = 275,
    PRE_DEC_OP = 276,
    AND_OP = 277,
    OR_OP = 278,
    MUL_ASSIGN = 279,
    DIV_ASSIGN = 280,
    MOD_ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    AND_ASSIGN = 284,
    XOR_ASSIGN = 285,
    OR_ASSIGN = 286,
    NEW_LINE = 287,
    INPUT = 288,
    PRINT = 289,
    END = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    FOR = 294,
    REPEAT = 295,
    UNTIL = 296,
    CONTINUE = 297,
    BREAK = 298,
    RETURN = 299,
    TO = 300
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define NUM 259
#define REAL 260
#define STRING_LITERAL 261
#define INT 262
#define FLOAT 263
#define STRING 264
#define INC_OP 265
#define DEC_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define POW_OP 271
#define UMINUS 272
#define POST_INC_OP 273
#define PRE_INC_OP 274
#define POST_DEC_OP 275
#define PRE_DEC_OP 276
#define AND_OP 277
#define OR_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define AND_ASSIGN 284
#define XOR_ASSIGN 285
#define OR_ASSIGN 286
#define NEW_LINE 287
#define INPUT 288
#define PRINT 289
#define END 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define FOR 294
#define REPEAT 295
#define UNTIL 296
#define CONTINUE 297
#define BREAK 298
#define RETURN 299
#define TO 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "pseudo.grm" /* yacc.c:1909  */

	int iValue;
	float fValue;
	char *sValue;
	char sIndex;
	struct nodeType *nptr;

#line 152 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
