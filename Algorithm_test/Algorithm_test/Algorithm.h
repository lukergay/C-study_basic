#pragma once


/*
���ļ����ڱ�д���� �����㷨��ʵ�ַ�ʽ
*/
#include<iostream>
#include<vector>


using namespace std;

class Algorithm
{
public:
	Algorithm();

	//���ҷ���
	/*
	 * (1) ���ֲ���  1.�ݹ���ң� 2,�ǵݹ����
	 * (2)˳����� 
	 * (3) ��ֵ����
	*/

	//���ݲ���
	/* 
	 * ǰ������--> Ҫ������ҵ������Ѿ��ź���

		v �����ҵ�����
		value ���ҵ�ֵ
		return ����ֵ���±�

	 * ʱ�临�Ӷ� O(log2n)
	 * �ռ临�Ӷ� O(2)
	*/
	int BinarySearchWhile(vector<int>&v, int value);
	int BinarySearchRecur(vector<int>&v, int value, int low, int high);

	//˳�����
	/*
	v �����ҵ�����
	value ���ҵ�ֵ
	return ����ֵ���±�
 * ʱ�临�Ӷ� O(n)
 * �ռ临�Ӷ� O(1)
*/
	int SequeuetiaSearch(vector<int> &v, int value);

	//��ֵ��ֵ


	//���򷽷�
	/*
	* (1)ð������
	* (2) 
	*/



	~Algorithm();
};

