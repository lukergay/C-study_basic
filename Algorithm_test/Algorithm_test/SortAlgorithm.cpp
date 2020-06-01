#include "SortAlgorithm.h"
#include <stdlib.h>

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


