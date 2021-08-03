#include<stdio.h>
#include<stdlib.h>
/*
  结构体符号表
    
**/
#define LINE_SIZE 256   //按行读取文件时，每行的最大长度byte
#define FILEPATH "./worldtable"

typedef struct ITEM{
    char *alias;             //单词名称
    unsigned int type;          //单词类型
    unsigned int address;       //单词的值
    struct ITEM *next ;
}ITEM;

ITEM item, *link;


int initial_symbol_table(){
    char *buf;
    FILE *p = NULL;
    p = fopen("./wordtable","r");
    if(p != NULL){
        fgets(buf,LINE_SIZE-1,p)!= NULL;    //跳过文件第一行
        while(fgets(buf,LINE_SIZE-1,p)!= NULL){
            printf ("%c",buf);
        }
        fclose(p);
        return 1;
    }else{
       printf("ERROR:open file failure!");
        return 0;
    }
}

ITEM * initial_table(char *b, ITEM *l){         //读取每一行数据，初始化节点
    link = malloc (sizeof(ITEM));
    return NULL;
}

void discard_table(ITEM *l){
    while(l->next != NULL){         //删除记录中第一个
        free(l->alias);
        l->next = l->next->next;        
    }
    free(l);
}



int initial_symbol_table(void);
int main()
{
    initial_symbol_table();
}
