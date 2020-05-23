#pragma once


/*
本文件用于编写关于 查找算法的实现方式
*/
#include<iostream>
#include<vector>


using namespace std;

class SearchAlgorithm
{
public:
	SearchAlgorithm();
	~SearchAlgorithm();
	//查找方法
	/*
	 * (1) 二分查找  1.递归查找， 2,非递归查找
	 * (2)顺序查找 
	 * (3) 插值查找
	   (4) 二叉树查找
	   (5)斐波那契查找法
	*/

	//二份查找
	/* 
	 * 前提条件--> 要求待查找的容器已经排好序

		v 待查找的容器
		value 查找的值
		return 查找值的下标

	 * 时间复杂度 O(log2n)
	 * 空间复杂度 O(2)
	*/
	int binary_search_while(vector<int>&v, int value);
	int binary_search_recur(vector<int>&v, int value, int low, int high);

	//顺序查找
	/*
	v 待查找的容器
	value 查找的值
	return 查找值的下标
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
*/
	int sequeuetia_search(vector<int> &v, int value);

	//插值插值
	/*
		插值算法是由折半算法转换， 适用于  对于数据量较大，关键字分布比较均匀的查找表来说，采用插值查找, 速度较快.

	核心算法
	 mid= low+ [(value - v[low])/(v[high]-a[low])* (high-low)]

	  同样分为递归，循环
	*/
	int insertion_search(vector<int> &v, int value,int low,int high);

	// 二叉树查找  
	/*
	* 用于二叉搜索树的插值算法算法

	在二叉搜索树b中查找x的过程为：

	1. 若b是空树，则搜索失败，否则：
	2. 若x等于b的根节点的数据域之值，则查找成功；否则：
	3. 若x小于b的根节点的数据域之值，则搜索左子树；否则：
	4. 查找右子树。
	*/


	//斐波那契查找法
	/*

	仅使用加法减法实现二分查找
	 核心算法：
	 f（1）=1;  f(2)=1 ; f(n)=f(n-1)+f(n-2);
		f(n-1) 表示数组前半段， 中间值的左边
		f(n-2) 表示数组后判断，中间值的右边
	时间复杂度 O(log2n)，
	*/

	#define max_size  20//斐波那契数组的长度
	void fibonacci(int * F);
	/*构造一个斐波那契数组*/

	int fibonacci_search(vector<int> & v, int key);
	/*
		v 为待查找的函数
		n 为待查找的数组长度
		key 为要查找的关键字
	*/





};

