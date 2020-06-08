#pragma once

#include<iostream>
#include<vector>


using namespace std;

//桶排序的链表
struct ListNode
{
	explicit ListNode(int i = 0) :mData_(i), mNext_(NULL) {}
	ListNode* mNext_;
	int mData_;
};


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
	*（7)计数排序
	* (8)桶排序
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


	//计数排序
	/*
		计数排序：统计小于等于该元素值的元素的个数i，于是该元素就放在目标数组的索引i位（i≥0）。

			计数排序基于一个假设，待排序数列的所有数均为整数，且出现在（0，k）的区间之内。
			如果 k（待排数组的最大值） 过大则会引起较大的空间复杂度，一般是用来排序 0 到 100 之间的数字的最好的算法，但是它不适合按字母顺序排序人名。
			计数排序不是比较排序，排序的速度快于任何比较排序算法。
			时间复杂度为 O（n+k），空间复杂度为 O（n+k）

		算法的步骤如下：

		1. 找出待排序的数组中最大和最小的元素
		2. 统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
		3. 对所有的计数累加（从 C 中的第一个元素开始，每一项和前一项相加）
		4. 反向填充目标数组：将每个元素 i 放在新数组的第 C[i] 项，每放一个元素就将 C[i] 减去 1
	*/
	void count_sort(vector<int> & v);


	//桶排序

	/*
		桶排序：将值为i的元素放入i号桶，最后依次把桶里的元素倒出来。
		待排序数组A[1...n]内的元素是随机分布在[0,1)区间内的的浮点数.
		辅助排序数组B[0....n-1]的每一个元素都连接一个链表.
		将A内每个元素乘以N(数组规模)取底,并以此为索引插入(插入排序)数组B的对应位置的连表中. 最后将所有的链表依次连接起来就是排序结果.
	桶排序序思路：
		1. 设置一个定量的数组当作空桶子。
		2. 寻访序列，并且把项目一个一个放到对应的桶子去。
		3. 对每个不是空的桶子进行排序。
		4. 从不是空的桶子里把项目再放回原来的序列中。

		假设数据分布在[0，100)之间，在数据入桶的同时插入排序，然后把各个桶中的数据合并。


	*/
	void bucket_sort(vector<int> &v);


	//插入 对应链表的数据
	ListNode * insert(ListNode* head, int value);
	//融合二个链表
	ListNode * merge(ListNode * headl, ListNode * head2);

	//堆排序


	/*

	堆排序：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆。
			将待排序序列构造成一个大顶堆，
			此时，整个序列的最大值就是堆顶的根节点。
			将其与末尾元素进行交换，此时末尾就为最大值。
			然后将剩余n-1个元素重新构造成一个堆，
			这样会得到n个元素的次小值。
			如此反复执行，便能得到一个有序序列了

	步骤：
		a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
		b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
		c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。

　　堆是具有以下性质的完全二叉树：
		每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；
		每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

	它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序
	*/
	void heap_sort(vector<int> & v);

	void max_heapify(vector<int>& v_arr, int start, int end);

	//基数排序:多关键字的排序算法，可用桶排序实现。
	/*

	基数排序(Radix Sort)是桶排序的扩展，它的基本思想是：将整数按位数切割成不同的数字，然后按每个位数分别比较。

	具体做法是：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。
		这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。

	例子：
		1. 按照个位数进行排序。
		2. 按照十位数进行排序。
		3. 按照百位数进行排序。
	*/
	void radix_sort(vector<int> &v_arr);
	/*获取数组中最大的数的位数*/
	int  get_max_bit(vector<int> &v);

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
