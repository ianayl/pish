#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tokens.h"

struct tk_arr ta_new ()
{
	struct tk_arr res;

	res.len = 0;
	res.arr = 0;

	return res;
}

void ta_push (struct tk_arr *dest, char* val , enum tk_type type)
{
	if (dest->len == 0)
		dest->arr = malloc(sizeof(struct token));
	else
		dest->arr = realloc(dest->arr, (dest->len + 1)
					  * sizeof(struct token));
	
	/* assuming sizeof(char) = 1 */
	dest->arr[dest->len].val = malloc(strlen(val) + 1);
	strcpy(dest->arr[dest->len].val, val);
	dest->arr[dest->len].type = type;

	dest->len ++;
}

struct token ta_get_token (struct tk_arr *src, unsigned index)
{
	if (index >= src->len || index < 0) {
		struct token null;
		return null;
	}
	return src->arr[index];
}

char* ta_get_val (struct tk_arr *src, unsigned index)
{
	if (index >= src->len || index < 0)
		return 0;
	return src->arr[index].val;
}

enum tk_type ta_get_type (struct tk_arr *src, unsigned index)
{
	if (index >= src->len || index < 0) {
		enum tk_type null;
		return null;
	}
	return src->arr[index].type;
}

void ta_destroy (struct tk_arr *dest)
{
	for (int i = (dest->len - 1); i >= 0; i--)
		free(dest->arr[i].val);
	free(dest->arr);
}

/* 
 * just testing code, pls ignore lol
 *
 * int main ()
 * {
 *         struct tk_arr test = ta_new();
 *         ta_push(&test, "abc");
 *         ta_push(&test, "def");
 *         ta_push(&test, "ghi");
 *         for (int i = 0; i<test.len; i++)
 *      	   printf("%s\n", ta_get_val(&test, i));
 *         ta_destroy(&test);
 * }
 */
