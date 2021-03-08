#pragma once

#include"data_config.h"

//链表的类型
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

/*说明：本程序实现了一个单链表*/
class List
{
public:
	List();
	~List();

public:
	Status init_list(LinkList&L);
	Status destory_list(LinkList&L);
};

