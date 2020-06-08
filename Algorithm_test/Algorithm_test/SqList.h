#pragma once
#include "data_config.h"

/*本程序实现了一个顺序表。
	实现功能：初始化，销毁，清空，判空，长度，获取数据，遍历，更改，添加，删除
*/
//顺序表是在计算机内存中以数组的形式保存的线性表
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#include <iostream>
#include <memory>
using namespace std;
typedef struct {
	ElemType * elem_; /*顺序表信息*/
	int length_;	/*表长*/	
	int size_;		/*大小*/
	int incrment_;

}SeqList;


class SqList
{
public:
	SqList();
	Status init_list(SeqList& L, int size,int inc);		/*初始化顺序表 L*/
	Status destroy_list(SeqList &L);					/*销毁顺序表 L */
	Status clear_list(SeqList &L);						/*清空顺序表 L */
	Status empty_list(SeqList &L);						/*判断顺序表是否为空， 空则返回true 不同则返回false*/
	int length_list(SeqList &L);						/*请求顺序表的长度*/
	Status get_elem_list(SeqList & L, int i, ElemType&e); /*获取顺序表 L 中的第i个元素*/
	int search_elem_list(SeqList& L, ElemType&e);	/*查找顺序表L顺序查找元素e，成功时返回该元素在表中第一次出现的位置，否则返回-1*/
	Status traverse_list(SeqList &L, Status(*visit)(ElemType e));  //遍历顺序表L，依次对每个元素调用函数visit()
	Status alter_elem_list(SeqList&L, int i, ElemType e);	/*将顺序表L的第i个元素改为e*/
	Status append_elem_list(SeqList &L, ElemType e);		/*给顺序表L表尾添加元素e*/
	Status delete_elem_list(SeqList &L, ElemType &e);	 /*删除顺序表L的表尾元素，返回参数e其值*/
	~SqList();
};




