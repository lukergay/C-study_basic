#pragma once

#include"data_config.h"

//���������
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

/*˵����������ʵ����һ��������*/
class List
{
public:
	List();
	~List();

public:
	Status init_list(LinkList&L);
	Status destory_list(LinkList&L);
};

