#pragma once


/*
本文件用于编写关于 常规算法的实现方式
*/
#include<iostream>
#include<vector>


using namespace std;

class Algorithm
{
public:
	Algorithm();

	//查找方法
	/*
	 * (1) 二分查找  1.递归查找， 2,非递归查找
	 * (2)顺序查找 
	 * (3) 插值查找
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
	int BinarySearchWhile(vector<int>&v, int value);
	int BinarySearchRecur(vector<int>&v, int value, int low, int high);

	//顺序查找
	/*
	v 待查找的容器
	value 查找的值
	return 查找值的下标
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
*/
	int SequeuetiaSearch(vector<int> &v, int value);

	//插值插值


	//排序方法
	/*
	* (1)冒泡排序
	* (2) 
	*/



	~Algorithm();
};

