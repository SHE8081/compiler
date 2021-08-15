#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
  结构体符号表
    
**/
#define LINE_SIZE 256   //按行读取文件时，每行的最大长度byte
#define ALIAS_SIZE 20   //单词符号长度
#define FILEPATH "./worldtable"

typedef struct Item{
    char *alias;             //单词名称
    unsigned int type;          //单词类型
    unsigned int address;       //单词的值
}Iteminfo;

typedef struct Head{
    char *name;
    char *type;
    char *address;
}Headinfo;

typedef struct Rec_tag{
    enum {HEAD,BODY} type;
    union {
        Headinfo *head;
        Iteminfo *item; 
    }info;
    struct Rec_tag *next;
}Rec;


Rec *head;                                              //声明链表头指针
void discard_rec(Rec *);
Rec *create_head_record(void);
Rec *create_item_record(Rec *, char *,unsigned int);


int initial_symbol_table(){
    int exit_status = EXIT_SUCCESS;
    char buf[LINE_SIZE];
    FILE *p = NULL;
    p = fopen("wordtable","r");
    if(p != NULL){
        head = create_head_record();                    //生成链表头                        
        unsigned int code = 0;                          //初始化种别编码
        fgets(buf,LINE_SIZE-1,p);
        while(fgets(buf,LINE_SIZE-1,p)!= NULL){         //生成链表内容
            
            head = create_item_record(head, buf,code);
            code ++ ;
        }


    }else{
       perror("ERROR:open file failure!");
       exit_status = EXIT_FAILURE;
    }
    if(fclose(p) !=0 ){
        perror("fclose");
        exit(EXIT_FAILURE);
    }
    return exit_status;
}


Rec *create_head_record(){
    Rec *h = (Rec *)malloc(sizeof(Rec));
    if(h != NULL)
    {
        h->type = HEAD;
        h->next = NULL;            //头指针的next默认空
        h->info.head = malloc(sizeof(Headinfo));
        if(h->info.head != NULL){
            h->info.head->name="单词符号";
            h->info.head->type="种别编码";
            h->info.head->address="内部地址";

        }
        return h;
    }else{
        printf("Out of memory!");
        return NULL;
    }
}


Rec *create_item_record(Rec *head, char *buf, unsigned int num){       //head:链表的头指针; buf:文件的行指针;num:种别编码
    Rec *i = (Rec *)malloc(sizeof(Rec));
    if(i != NULL)
    {   
       i->type = BODY;
       i->info.item = malloc(sizeof(Iteminfo));
       i->info.item->alias = malloc(ALIAS_SIZE*sizeof(char));
       if((i->info.item != NULL) || (i->info.item->alias != NULL))
       {
        //while((*(i->info.item->alias)++ = *buf++) != '\0')   ;                                           //从buf中拷贝字符串直到/0到item->alias中
        char *tmp = i->info.item->alias;
        while(  *buf!= '|'){
            *tmp = *buf ;
            buf = buf + 1;
            tmp = tmp + 1;
        }
        i->info.item->type = num;
        i->info.item->address = 0;                  //内码暂定为0
        i->next = head->next;                            //头部插入新结点    ;
        head->next = i;
        return head;
       }
    }
    else
    {
        printf("Out of memory!");
        return NULL;
    }
}

void discard_rec(Rec *rec){                     //删除记录，释放空间
    switch (rec->type){
    case HEAD:
        free(rec->info.head);
        break;

    case BODY:
        free(rec->info.item);
        break;
    }

    free(rec);
}

void print_record(Rec *h)
{
    if(h != NULL)
    {
        while(h->next != NULL)
        {
            if(h->type == HEAD){
                printf("%s--%s--%s\n",h->info.head->name,h->info.head->type,h->info.head->address);
                h = h->next;
             }else if(h->type == BODY)   {
                    printf("%s--%d--%d\n",h->info.item->alias,h->info.item->type,h->info.item->address);
                    h = h->next;
             }else{
                   printf("Unkown link type");
                   exit(1);       
            }
        }
    }else{
        printf("Record is empty!");
        exit(1);
    }
}


int initial_symbol_table();
void print_record(Rec *);
int main()
{
    initial_symbol_table();
    print_record(head);
}
