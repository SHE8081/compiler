#include"token_scan_main.h"
#include<assert.h>


void init_scan()
{
    fp = fopen("","r");
    assert(fp == NULL);
    lexeme_beginning = ftell(fp);
    forward = lexeme_beginning;
}


void close_scan()
{

    
}

token token_scan()
{
    char ch;
    char* token;
    ch = getchar(fp) ;
    while(isspace(ch)){
        ch = getchar(fp) ;
        lexeme_beginning++;
    }
    if(isalpha(ch)){
        ch = getchar(fp) ;
        while (isalnum(ch))
            ch = getchar(fp) ;
        retract(1);
        token = copytoken();
        return (gettoken(token), install_id(token));
    }
    else if(isdigit(ch)){
        ch = getchar(fp) ;
        while(isdigit(ch))
            ch = getchar(fp) ;
        retract(1);
        token = copytoken();
        return (INT, install_num(token));
    }
    else
    switch(chr)
    {
        case '*': ch = getchar(fp) ;
                  if(ch == '*') return (EXP,0);
                  else{
                    retract(1);
                    return(MULTI,0);
                  }break;
        case ':': ch = getchar(fp) ;
                  if(ch == '=') return (ASSIGN,0):
                  else {
                    retract(1);
                    return(COLON,0);
                    }break;
         case '<' : ch = getchar(fp) ;
                    if (ch == '=') return (LE,0);
                    else if (ch == '>') return (NE,0)；
                    else{
                        retract(1);
                        return(LT,0);
                    }break;
        case '=' : return(EQ, 0);
                    break;
        case '>' : ch = getchar(fp) ;
                    if(ch == '=') return (GE,0):
                    else {
                        retract(1);
                        return(GT,0);
                    }break;
         case '+' : return(PLUS,0); break;
         case '-' : return(MINUS,0);break;
         case '/' : return(RDIV,0);break;
         case ',' : return(COMMA,0);break;
         case ';' : return(SEMIC,0);break;
         default : error_handle(); break;          
    }
    return;
}
