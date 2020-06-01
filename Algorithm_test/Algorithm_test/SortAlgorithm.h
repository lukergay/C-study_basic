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
	*（4)快速排序
	*（5)希尔排序
	* (6)归并排序
	* (7)桶排序
	*（8)计数排序
	* (9)堆排序
	*（10)基数排序
	*/

	//选择排序
	/*
		
	（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。

	选择排序思路：
		1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
		2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
		3. 以此类推，直到所有元素均排序完毕

	时间复杂度 O(n2)
	*/
	void selection_sort(vector<int> &v);
	/*类模板 选择排序*/
	template<typename T>
	void selection_sort_t(vector<T> & v);

	//冒泡排序
	/*
	（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。

	选择排序思路：
		1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
		2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
		3. 针对所有的元素重复以上的步骤，除了最后一个。
		4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
	*/
	void bubble_sort(vector<int> & v);
	void bubble_sort_insert(vector<int> &v);
	template<typename T>
	void bubble_sort_t(vector<T> & v);


	//插入排序

/*
	（有序区，无序区）。把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多。
	插入排序思路：
	1. 从第一个元素开始，该元素可以认为已经被排序
	2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
	3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
	4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
	5. 将新元素插入到该位置后
	6. 重复步骤2~5
*/
	void insert_sort(vector<int>& v);

	//快速排序

	/*
	是怎么交换到前面的.


（小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

	快速排序思路：
	1. 选取第一个数为基准
	2. 将比基准小的数交换到前面，比基准大的数交换到后面
	3. 对左右区间重复第二步，直到各区间只有一个数

	快速排序算法的基本特性
	时间复杂度：O（n*lgn）
	最坏：O（n^2）
	空间复杂度：O（n*lgn） 不稳定。

	技术详解：https://blog.csdn.net/MoreWindows/article/details/6684558

	*/
	void quick_sort_recur(vector<int> & v,int low, int high);
	template<typename T>
	void quick_sort_recur_t(vector<int>&v, T low, T high);


	//希尔排序
	/*
	希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。

	最佳情况：T(n) = O(nlogn)。最坏情况：T(n) = O(n)。平均情况：T(n) = O(nlogn)。
	*/
	template<typename T>
	void shell_sort(vector<T>&v);

	//归并排序
	/*
	 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

	 平均时间复杂度：O(nlogn)
	最佳时间复杂度：O(n)
	最差时间复杂度：O(nlogn)
	空间复杂度：O(n)
	排序方式：In-place
	稳定性：稳定
	*/
	void merge_sort_while(vector<int> & v);

	template<typename T>
	void merge_sort_recur(vector<T> &a, vector<T>&b, int start, int end);

};



template<typename T>
inline void SortAlgorithm::selection_sort_t(vector<T>& v)
{
	int len = v.size();
	for (size_t i = 0; i < v.size(); ++i) {
		int min = i;
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (v[min] > v[j])
				min = j;
		}

		if (i != min)
			std::swap(v[i], v[min]);
	}
}

template<typename T>
inline void SortAlgorithm::bubble_sort_t(vector<T>& v)
{
	int len = v.size();
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - 1 - i; j++) {
				if (v[j] > v[j + 1])
					std::swap(v[j], v[j + 1]);
			}
		}
}

template<typename T>
inline void SortAlgorithm::quick_sort_recur_t(vector<int>& v, T  low, T high)
{
	if (low >= high)
		return;

	//以最后一个为基准
	T key = v[high];
	int first = low, last = high-1;

	while (first < last) {
		while (v[first] < key && first < last)
			first++;
		while (v[last] >= key && first < last)
			last--;

		if (first < last)
			std::swap(v[last], v[first]);
	}

	//判断中间的标志位 和最后一个值得比较
	if (v[first] >= v[high])
		std::swap(v[first], v[high]);
	else
		first++;
	
	quick_sort_recur_t(v, low, first - 1);
	quick_sort_recur_t(v, first + 1, high);

}

template<typename T>
inline void SortAlgorithm::shell_sort(vector<T>& v)
{
	int len = v.size();

	int h = 1;
	while (h < len / 3) {
		h = 3 * h + 1;
	}

	while (h >= 1) {
		for (size_t i = h; i < len; ++i) {
			for (size_t j = i; j >= h && v[j] < v[j - h]; j -= h) {
				std::swap(v[j], v[j - h]);
			}
		}

		h = h / 3;
	}


}

template<typename T>
inline void SortAlgorithm::merge_sort_recur(vector<T>& a, vector<T>& b, int start, int end)
{
	if (start >= end)
		return;

	int len = end - start, mid = (len>>1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;

	merge_sort_recur(a, b, start1, end1);
	merge_sort_recur(a, b, start2, end2);

	int k = start;
	while (start1 <= end1 && start2 <= end2)
		b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <=end1)
		b[k++] = a[start1++];
	while (start2 <= end2)
		b[k++] = a[start2++];

	for (k = start; k <= end; k++)
		a[k] = b[k];


}
