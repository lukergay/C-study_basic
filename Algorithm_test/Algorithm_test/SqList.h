#pragma once
#include "data_config.h"

/*������ʵ����һ��˳���
	ʵ�ֹ��ܣ���ʼ�������٣���գ��пգ����ȣ���ȡ���ݣ����������ģ���ӣ�ɾ��
*/
//˳������ڼ�����ڴ������������ʽ��������Ա�
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#include <iostream>
#include <memory>
using namespace std;
typedef struct {
	ElemType * elem_; /*˳�����Ϣ*/
	int length_;	/*��*/	
	int size_;		/*��С*/
	int incrment_;

}SeqList;


class SqList
{
public:
	SqList();
	Status init_list(SeqList& L, int size,int inc);		/*��ʼ��˳��� L*/
	Status destroy_list(SeqList &L);					/*����˳��� L */
	Status clear_list(SeqList &L);						/*���˳��� L */
	Status empty_list(SeqList &L);						/*�ж�˳����Ƿ�Ϊ�գ� ���򷵻�true ��ͬ�򷵻�false*/
	int length_list(SeqList &L);						/*����˳���ĳ���*/
	Status get_elem_list(SeqList & L, int i, ElemType&e); /*��ȡ˳��� L �еĵ�i��Ԫ��*/
	int search_elem_list(SeqList& L, ElemType&e);	/*����˳���L˳�����Ԫ��e���ɹ�ʱ���ظ�Ԫ���ڱ��е�һ�γ��ֵ�λ�ã����򷵻�-1*/
	Status traverse_list(SeqList &L, Status(*visit)(ElemType e));  //����˳���L�����ζ�ÿ��Ԫ�ص��ú���visit()
	Status alter_elem_list(SeqList&L, int i, ElemType e);	/*��˳���L�ĵ�i��Ԫ�ظ�Ϊe*/
	Status append_elem_list(SeqList &L, ElemType e);		/*��˳���L��β���Ԫ��e*/
	Status delete_elem_list(SeqList &L, ElemType &e);	 /*ɾ��˳���L�ı�βԪ�أ����ز���e��ֵ*/
	~SqList();
};




