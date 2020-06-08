#pragma once
#include "data_config.h"
#include<malloc.h>
//顺序栈的类型
//实现功能：初始化，销毁，判空，获取数据，添加，删除
typedef struct {
	ElemType *elem;  /*栈的数组指针*/
	int top;		/*栈头所在的位置*/
	int size;
	int increment;
} SeqSrack;

class SqStack
{
public:
	SqStack();
	Status init_stack(SeqSrack &S, int size, int inc);  //初始化顺序栈
	Status destroy_stack(SeqSrack &S);                  //销毁顺序栈
	Status empty_stack(SeqSrack S);                     //判断S是否空，若空则返回TRUE，否则返回FALSE
	void clear_stack(SeqSrack &S);                      //清空栈S
	Status push_stack(SeqSrack &S, ElemType e);         //元素e压入栈S
	Status pop_stack(SeqSrack &S, ElemType &e);         //栈S的栈顶元素出栈，并用e返回
	Status get_top_stack(SeqSrack S, ElemType &e);      //取栈S的栈顶元素，并用e返回

	~SqStack();
};

