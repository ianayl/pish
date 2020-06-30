#ifndef TOKENS_H
#define TOKENS_H

/* Types for tokens */
/* TODO document crap better */
enum tk_type
{

    NULL_TYPE, /* This is so that a type of 0 represents null */

    /* TODO consider renaming this, this could be misleading */
    TOKEN, /* Generic token type, before distinguishing token types */

    /* The following are specified token types */
    WORD,
    ASSIGNMENT_WORD,
    NAME,

    /* Misc. types */
    NEWLINE,
    IO_NUMBER,

    /* Operators */
    OP_ANDIF, /* &&, AND logic */
    OP_AMPERSAND, /* &, asynchronous execution */
    OP_ANDOR, /* ||, OR logic */
    OP_PIPE, /* |, and uh... it's a pipe, idk what else to tell you */
    OP_DSEMI, /* ;;, I think it's only for case conditional constructs */
    OP_SEMICOLON, /* ;, do something, wait til its done, do next thing */
    OP_DLESSDASH, /* <<- */
    OP_DLESS, /* << */
    OP_LESSAND, /* <& */
    OP_LESSGREAT, /* <> */
    OP_LESS, /* < */
    OP_CLOBBER, /* >| */
    OP_DGREAT, /* >> */
    OP_GREATAND, /* >& */
    OP_GREAT /* > */

} tk_type;

/* Stores a single token and it's type */
struct token
{
	char* val;
    enum tk_type type;

} token;

/* An array of tokens */
struct tk_arr
{
	struct token* arr;
	unsigned len;
	/* 
     * Was the lexer currently in quotes before the end of the input? 
     *
     * in_quotes can be either:
     * - the value 0, indicating lexer is currently not in quotes
     * - the ascii value of the quotes that the lexer is currently in
     */
    unsigned short in_quotes;

    /* Was there a line continuation? */
    unsigned short in_line_cont;

} tk_arr;

/* Initializes new tk_arr */
struct tk_arr ta_new ();

/* Pushes a new token onto dest */
void ta_push (struct tk_arr *dest, char* val, enum tk_type type);

/* Sets the status variables for dest. tk_arr */
void ta_set_status (struct tk_arr *dest,
                    unsigned short is_in_quotes);

/* Gets the token struct at index */
struct token ta_get_token (struct tk_arr *src, unsigned index);

/* Gets the string value of the token at index */
char* ta_get_val (struct tk_arr *src, unsigned index);

/* Gets the tk_type of the token at index */
enum tk_type ta_get_type (struct tk_arr *src, unsigned index);

/* Properly destroys and cleans up a tk_arr */
void ta_destroy (struct tk_arr *dest);

#endif
