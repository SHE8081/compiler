#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
  结构体符号表
    
**/
#define LINE_SIZE 256   //按行读取文件时，每行的最大长度byte
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
Rec *create_item_record(Rec *, char *);


int initial_symbol_table(){
    int exit_status = EXIT_SUCCESS;
    char buf[LINE_SIZE];
    FILE *p = NULL;
    p = fopen("wordtable","r");
    if(p != NULL){
        if(fgets(buf,LINE_SIZE-1,p)!= NULL)             //生成链表节点
        {
            head = create_head_record();
            
        }
        while(fgets(buf,LINE_SIZE-1,p)!= NULL){         //生成链表内容
            head = create_item_record(head, buf);        
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

//ITEM * add_item(char *b, ITEM *l){      //读取每一行数据，初始化节点。传入以行缓存数据和连接头指针
//   static char whitespace[] = " \t\f\r\v\n";
//   char *token = NULL;
//   int count=1;                         //符号表3列标记1-3 1:alias 2:type  3:address
//   ITEM *newl = malloc(sizeof(ITEM));
//   for ( token = strtok(b ,whitespace); token != NULL; token = strtok(NULL, whitespace))
//    {
//      switch(count){
//      case 1:
//            newl->alias = malloc((token+1)*sizeof(char));    //分配alias指向的空间
//            for( ; token > 0；token--){                 //复制内容到alia指定的空间内
//                newl->alias[token] = b[token];
//            }
//      case 2:
//            newl->type = b[token]; 
//      case 3:
//            newl-type->address = 0;
//      default : count = count + 1;
//     }
//    }
//   newl->next = l->netx->next;                 //头部插入
//   l->next = newl; 
//   return l;                     //返回增加表项后的连表头地址
//}
//

Rec *create_head_record(){
    Rec *h = (Rec *)malloc(sizeof(Rec));
    if(h != NULL)
    {
        h->type = HEAD;
        h->next = h;            //头指针的next默认指自己
        h->info.head = malloc(sizeof(Headinfo));
        if(h->info.head != NULL){
            h->info.head->name="单词符号";
            h->info.head->type="种别编码";
            h->info.head->address="内部地址";

        }
        return h;
    }
     printf("Out of memory!");
     return NULL;
}


Rec *creat_item_record(Rec *head, char *buf){       //head:链表的头指针; buf:文件的行指针
    Rec *i = (Rec *)malloc(sizeof(Rec));
    unsigned int t = 0;                              //种别编码
    if(i != NULL)
    {   
       i->type = BODY;
       i->info.item = malloc(sizeof(Iteminfo));
       if(i->info.item != NULL)
       {
        while((*i->info.item->alias++ = *buf++) != '\0')
        ;                                           //从buf中拷贝字符串直到/0到item->alias中
        i->info.item->type = t++;
        i->info.item->address = 0;                  //内码暂定为0
       }
        i->next = head->next;                            //头部插入新结点    ;
        head->next = i;
        return head;
      }
    printf("Out of memory!");
    return NULL;
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



int initial_symbol_table();
int main()
{
    initial_symbol_table();
}
