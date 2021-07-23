#include<stdio.h>

/*
  结构体符号表
    
**/
#define LINE_SIZE 256   //按行读取文件时，每行的最大长度byte
#define FILEPATH "worldtable"

typedef struct ITEM{
    char *alias;             //单词名称
    unsigned int type;          //单词类型
    unsigned int address;       //单词的值
} ITEM;

typedef struct SYMBOL_TABLE{    //符号表
    struct ITEM  *prior;
     ITEM  data;
    struct ITEM *next; 
}SYMBOL_TABLE;


int initial_symbol_table(){
    char *buf[LINE_SIZE];  
    FILE *p = NULL;
    p = fopen(FILEPATH,"r");
    if(p== NULL){
        printf("ERROR:open file failure!");
        return 0;
    }
    
    while(fgets(buf,LINE_SIZE-1,p)!= NULL){
        printf ("%s",buf);
    }
    fclose(p);
}

int initial_symbol_table(void);
int main()
{
    initial_symbol_table();
}
