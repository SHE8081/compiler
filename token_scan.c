#include<stdio.h>

/*
  结构体符号表
    
**/


typedef struct ITEM{
    char *alias;             //单词名称
    unsigned int type;          //单词类型
    unsigned int address;       //单词的值
} 

typedef struct SYMBOL_TABLE{    //符号表
    struct ITEM  *prior;
     ITEM  data;
    struct ITEM *next; 
}

int initial_symbol_table();    //初始化符号表：1成功；2失败

int initial_symbol_table(FLLE *p){

    
}
