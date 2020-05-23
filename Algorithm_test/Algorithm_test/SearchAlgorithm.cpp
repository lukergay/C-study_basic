#include "SearchAlgorithm.h"


SearchAlgorithm::SearchAlgorithm()
{
}

/*
非递归
*/
int SearchAlgorithm::binary_search_while(vector<int> &v, int value)
{
	if (v.empty())
		return -1;

	int low = 0;
	int high = v.size() - 1;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (v[mid] == value) {
			return mid;
		}
		else if (v[mid] > value) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;
}

/*
 * 递归查找
 * 递归查找存在风险
*/
int SearchAlgorithm::binary_search_recur(vector<int>& v, int value, int low, int high)
{
	if (low > high)
		return -1;

	int mid = (high + low) / 2;
	if (v[mid] == value) {
		return mid;
	}
	else if (v[mid] > value) {
		return binary_search_recur(v, value, low, mid - 1);
	}
	else {
		return binary_search_recur(v, value, mid + 1, high);
	}
}

int SearchAlgorithm::sequeuetia_search(vector<int>& v, int value)
{

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == value)
			return i;
	}

	return -1;
}

int SearchAlgorithm::insertion_search(vector<int>& v, int value, int low, int high)
{
	if (low >= high)
		return -1;

	int mid = low + (value - v[low] / v[high] - v[low]) *(high - low);
	if (v[mid] == value) {
		return mid;
	}
	else if (v[mid] < value) {
		return insertion_search(v, value, mid + 1, high);
	}
	else {
		return insertion_search(v, value, low, mid + 1);
	}
}

void SearchAlgorithm::fibonacci(int * F)
{
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i < max_size; ++i) {
		F[i] = F[i - 1] + F[i - 2];
	}
}

int SearchAlgorithm::fibonacci_search(vector<int>& v, int key)
{
	int low = 0;
	int high = v.size() - 1;
	int len = v.size();
	int F[max_size];
	/*构建一个斐波那契数组 F*/
	fibonacci(F);

	int k = 0;

	/*F[k]-1 是因为 数组有序表是从0开始*/
	while (F[k] - 1 > len)  //计算n位于斐波那契数列的位置
		k++;

	vector <int>temp(v); /*扩充数组至斐波那契数组 F[k]-1 的长度*/
	for (int i = len; i < F[k] - 1; ++i)
		temp.push_back(v[len - 1]);

	while (low < high)
	{
		int mid = low + F[k - 1] - 1;

		if (key > v[mid]) {
			low = mid + 1;
			k -= 2;
		}
		else if(key < v[mid]){
			high = mid - 1;
			k -= 1;
		}
		else {
			if (mid < len)
				return mid;
			else
				return len - 1;
			
		}
		
	}


	return -1;
}

SearchAlgorithm::~SearchAlgorithm()
{
}
