#include<ctype.h>
#include<stdio.h>
#include<assert.h>


#define token_len 32;     


static FILE * fp = NULL;
static lexeme_beginning *char = NULL;
static forward *char = NULL;


void retract(size_t size)
{
   forward = forward - size;
}

char *copytoken(char *lexeme_beginning, char *forward)
{
    assert(forward == lexeme_beginning);
    size_t len = forward - lexeme_beginning + 1;
    assert(token_len < len);            //超过缓冲区终止
    char *buf = malloc (lent * sizeof(char));
    assert(buf == NULL);
    for (; forward >= lexeme_beginning ;forward--, len--)
    {
        buf[len] = *forward;            //复制到缓冲区
    }
    return buf;
}

void gettoken(char *token)
{
    
}
