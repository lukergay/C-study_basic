#include "SortAlgorithm.h"
#include <stdlib.h> 
#include <algorithm>


SortAlgorithm::SortAlgorithm()
{
}

SortAlgorithm::~SortAlgorithm()
{
}

void SortAlgorithm::selection_sort(vector<int>& v)
{
	int min=0;
	int len = v.size();
	for (size_t i = 0; i < len; ++i) {
		min = i;
		for (size_t j = i + 1; j < len; ++j) {
			if (v[min] > v[j])
				min = j;
		}
		if(i !=min)
			std::swap(v[i], v[min]);
	}
}

void SortAlgorithm::bubble_sort(vector<int>& v)
{
	int len = v.size();
	for (size_t i = 0; i < len-1; ++i) {
		for (size_t j = 0; j < len - 1; ++j) {
			if (v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
		}
	}
}

void SortAlgorithm::bubble_sort_insert(vector<int>& v)
{
	int len = v.size();
	bool flag = false;

	for (size_t i = 0; i < len-1 && !flag; ++i) {
		flag = true;
		for (size_t j = 0; j < len - 1; ++j) {
			if (v[j] > v[j + 1]) {
				flag = false;
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

void SortAlgorithm::insert_sort(vector<int>& v)
{
	int len = v.size();
	for (size_t i = 1; i < len; ++i) {
		int tem = v[i];
		for (int j = i - 1; j >= 0; --j) {
			if (v[j] > tem) {
				v[j + 1] = v [j];
				v[j] = tem;
			}
			else
				break;
		}
	}

}

void SortAlgorithm::quick_sort_recur(vector<int>& v, int low, int high)
{
	if (high <= low)
		return;

	int first = low;
	int last = high;

	int key = v[first];

	while (first < last) {
		
		//小于第一个的值移到前方   如果大于则kast 下标自减1
		while (first < last && v[last] > key)
			last--;

		if (first < last)
			v[first++] = v[last];


		//大于第一个的移到后方  如果小于 则first 下标自加1
		while (first<last && v[first] < key)
			first++;

		if (first < last)
			v[last--] = v[first];
	}

	v[first] = key;

	// 前半递归
	quick_sort_recur(v, low, first - 1);
	// 后半递归
	quick_sort_recur(v, first + 1, high);

}

#define min(a,b) (((a) < (b)) ? (a) : (b))

void SortAlgorithm::merge_sort_while(vector<int>& v)
{
	vector<int> a = v;
	vector<int> b;
	b.resize(v.size());
	int len = v.size();

	for (size_t step = 1; step < len; step += step) {
		for (size_t start = 0; start < len; start += step + step) {
			int low = start,mid = min((start + step), len), high = min((start + step + step), len);

			int mark = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[mark++] = a[start1] < a[start2] ? a[start1++] : a[start2++];

			while (start1 < end1)
				b[mark++] = a[start1++];
			while (start2 < end2)
				b[mark] = a[start2++];
		}
		
		vector<int> tem = a;
		a = b;
		b = tem;
	
	}

	if (a != v) {
		v = a;
	}

}

void SortAlgorithm::count_sort(vector<int> &v)
{
	if (v.size() < 2)
		return;

	/*找到最大最小值 ，建立关于桶数组*/
	int min=*(std::min_element(v.begin(), v.end()));
	int max = *(std::max_element(v.begin(), v.end()));

	int len = max - min;

	vector<int> bucket;
	bucket.resize(len+1,0);

	/*以最小值为 基准*/
	for (size_t i = 0; i < v.size(); ++i) {
		bucket[(v[i]-min)]++;
	}

	for (size_t i = 0, j = 0; i < bucket.size(); ++i) {
		while (bucket[i] != 0) {
			v[j] = i + min;
			j++;
			bucket[i]--;
		}
	}

	bucket.clear();
}

ListNode* SortAlgorithm::insert(ListNode * head, int value)
{
	//创建一个新的节点
	ListNode * newNode = new ListNode(value);
	ListNode *pre, *cur;

	ListNode preNode;
	preNode.mNext_ = head;

	pre = &preNode;
	cur = head;

	//找到大于 value所在的位置
	while (nullptr != cur && cur->mData_ <= value) {
		pre = cur;
		cur=cur->mNext_;
	}

	newNode->mNext_ = cur;
	pre->mNext_ = newNode;

	return preNode.mNext_;
}

ListNode * SortAlgorithm::merge(ListNode * headl, ListNode * head2)
{
	ListNode mergeNode;
	ListNode* merge = &mergeNode;

	//循环遍历桶的内容 并且 指向下一个指针
	while (nullptr != headl && nullptr != head2) {
		if (headl->mData_ <= head2->mData_) {
			merge->mNext_ = headl;
			headl =headl->mNext_ ;

		}else{
			merge->mNext_ = head2;
			head2=head2->mNext_;
		}

		merge = merge->mNext_;
	}

	if (nullptr != headl)  //其中有一个链表已经指向NULL，而另一个还没有指向NULL
		merge->mNext_ = headl;
	if (nullptr != head2)
		merge->mNext_ = head2;


	//返回到头指针的地址
	return mergeNode.mNext_;
}

#define BUCKET_NUM 10
void SortAlgorithm::bucket_sort(vector<int>& v)
{
	int len = v.size();
	vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
	for (int i = 0; i < len; ++i) {
		int index = v[i] / BUCKET_NUM;
		ListNode *head = buckets.at(index);
		buckets.at(index) = insert(head, v[i]);
	}

	ListNode *head = buckets.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i) {
		head = merge(head, buckets.at(i));
	}

	for (int i = 0; i < len; ++i) {
		v[i] = head->mData_;
		head = head->mNext_;
	}

}

void SortAlgorithm::heap_sort(vector<int>& v)
{
	int len = v.size();
	//初始化 i从最后一个节点开始调整
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(v, i, len - 1);

	//先將第一個元素和已经排好的元素前一位做交換，再重新调整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		std::swap(v[0], v[i]);
		max_heapify(v, 0, i - 1);
	}

}

void SortAlgorithm::max_heapify(vector<int> &v_arr, int start, int end)
{
	//创建父节点下标和子节点下标
	int dat = start;
	int son = dat * 2 + 1;
	while (son <= end) {   //子节点下标在范围内
		if (son + 1 < end && v_arr[son] < v_arr[son + 1]) //比较相邻的节点
			son++;
		if (v_arr[dat] > v_arr[son])  //如果父节点大于子节点 调整完毕
			return;
		else {  //负责跳出循环
			std::swap(v_arr[dat], v_arr[son]); 
			dat = son;
			son = dat * 2 + 1;
		}
	}
}






