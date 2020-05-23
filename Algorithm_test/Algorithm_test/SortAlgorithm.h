#pragma once

#include<iostream>
#include<vector>

using namespace std;

class SortAlgorithm
{
public:
	SortAlgorithm();
	~SortAlgorithm();

	//排序方法
	/*
	*（1)选择排序
	* (2)冒泡排序
	* (3)插入排序
	* (4)归并排序
	* (5)桶排序
	*（6)计数排序
	* (7)堆排序
	*（8）快速排序
	*（9）基数排序
	*（10）希尔排序
	*/

	//选择排序
	/*
		
	（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。

	选择排序思路：
		1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
		2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
		3. 以此类推，直到所有元素均排序完毕

	时间复杂度
	*/
	void selection_sort(vector<int> &v);

};

