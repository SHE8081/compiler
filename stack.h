/**
一个堆栈模块的接口

**/

#define STATCK_TYPE char /*堆栈所存储的值的类型*/

void push(STACK_TYPE value);

void pop(void);

/**
返回堆栈顶部元素的值，但不对堆栈进行修改
    
*/

STACK_TYPE top(void);

int is_empty(void);

int is_full(void);

/**
创建堆栈，参数指定堆栈可以保存多个元素
*/
void create_stack(size_t size);

/**
销毁堆栈，释放堆栈所有的内存
*/

void destroy_stack(void);
