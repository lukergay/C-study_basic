#pragma once
#include "data_config.h"
#include<malloc.h>
//˳��ջ������
//ʵ�ֹ��ܣ���ʼ�������٣��пգ���ȡ���ݣ���ӣ�ɾ��
typedef struct {
	ElemType *elem;  /*ջ������ָ��*/
	int top;		/*ջͷ���ڵ�λ��*/
	int size;
	int increment;
} SeqSrack;

class SqStack
{
public:
	SqStack();
	Status init_stack(SeqSrack &S, int size, int inc);  //��ʼ��˳��ջ
	Status destroy_stack(SeqSrack &S);                  //����˳��ջ
	Status empty_stack(SeqSrack S);                     //�ж�S�Ƿ�գ������򷵻�TRUE�����򷵻�FALSE
	void clear_stack(SeqSrack &S);                      //���ջS
	Status push_stack(SeqSrack &S, ElemType e);         //Ԫ��eѹ��ջS
	Status pop_stack(SeqSrack &S, ElemType &e);         //ջS��ջ��Ԫ�س�ջ������e����
	Status get_top_stack(SeqSrack S, ElemType &e);      //ȡջS��ջ��Ԫ�أ�����e����

	~SqStack();
};

