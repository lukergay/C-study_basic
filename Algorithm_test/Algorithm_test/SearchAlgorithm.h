#pragma once


/*
���ļ����ڱ�д���� �����㷨��ʵ�ַ�ʽ
*/
#include<iostream>
#include<vector>


using namespace std;

class SearchAlgorithm
{
public:
	SearchAlgorithm();
	~SearchAlgorithm();
	//���ҷ���
	/*
	 * (1) ���ֲ���  1.�ݹ���ң� 2,�ǵݹ����
	 * (2)˳����� 
	 * (3) ��ֵ����
	   (4) ����������
	   (5)쳲��������ҷ�
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
	int binary_search_while(vector<int>&v, int value);
	int binary_search_recur(vector<int>&v, int value, int low, int high);

	//˳�����
	/*
	v �����ҵ�����
	value ���ҵ�ֵ
	return ����ֵ���±�
 * ʱ�临�Ӷ� O(n)
 * �ռ临�Ӷ� O(1)
*/
	int sequeuetia_search(vector<int> &v, int value);

	//��ֵ��ֵ
	/*
		��ֵ�㷨�����۰��㷨ת���� ������  �����������ϴ󣬹ؼ��ֲַ��ȽϾ��ȵĲ��ұ���˵�����ò�ֵ����, �ٶȽϿ�.

	�����㷨
	 mid= low+ [(value - v[low])/(v[high]-a[low])* (high-low)]

	  ͬ����Ϊ�ݹ飬ѭ��
	*/
	int insertion_search(vector<int> &v, int value,int low,int high);

	// ����������  
	/*
	* ���ڶ����������Ĳ�ֵ�㷨�㷨

	�ڶ���������b�в���x�Ĺ���Ϊ��

	1. ��b�ǿ�����������ʧ�ܣ�����
	2. ��x����b�ĸ��ڵ��������ֵ֮������ҳɹ�������
	3. ��xС��b�ĸ��ڵ��������ֵ֮��������������������
	4. ������������
	*/


	//쳲��������ҷ�
	/*

	��ʹ�üӷ�����ʵ�ֶ��ֲ���
	 �����㷨��
	 f��1��=1;  f(2)=1 ; f(n)=f(n-1)+f(n-2);
		f(n-1) ��ʾ����ǰ��Σ� �м�ֵ�����
		f(n-2) ��ʾ������жϣ��м�ֵ���ұ�
	ʱ�临�Ӷ� O(log2n)��
	*/

	#define max_size  20//쳲���������ĳ���
	void fibonacci(int * F);
	/*����һ��쳲���������*/

	int fibonacci_search(vector<int> & v, int key);
	/*
		v Ϊ�����ҵĺ���
		n Ϊ�����ҵ����鳤��
		key ΪҪ���ҵĹؼ���
	*/





};

