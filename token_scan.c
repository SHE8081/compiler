#include<stdio.h>

/*
  结构体符号表
    
**/
#define LINE_SIZE 256   //按行读取文件时，每行的最大长度byte
#define FILEPATH "./worldtable"

typedef struct ITEM{
    char *alias;             //单词名称
    unsigned int type;          //单词类型
    unsigned int address;       //单词的值
    struct ITEM ;
} item, *linklist;


int initial_symbol_table(){
    char *buf[LINE_SIZE];  
    FILE *p = NULL;
    p = fopen("./wordtable","r");
    if(p != NULL){
        fgets(buf,LINE_SIZE-1,p)!= NULL;    //跳过文件第一行
        while(fgets(buf,LINE_SIZE-1,p)!= NULL){
            printf ("%s",buf);
        }
        fclose(p);
        return 1;
    }else{
       printf("ERROR:open file failure!");
        return 0;
    }
}

int initial_List(char *buf, ITEM *L){
         
}



int initial_symbol_table(void);
int main()
{
    initial_symbol_table();
}
