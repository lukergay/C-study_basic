#include "Algorithm.h"


Algorithm::Algorithm()
{
}

/*
�ǵݹ�
*/
int Algorithm::BinarySearchWhile(vector<int> &v, int value)
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
 * �ݹ����
 * �ݹ���Ҵ��ڷ���
*/
int Algorithm::BinarySearchRecur(vector<int>& v, int value, int low, int high)
{
	if (low > high)
		return -1;

	int mid = (high + low) / 2;
	if (v[mid] == value) {
		return mid;
	}
	else if (v[mid] > value) {
		return BinarySearchRecur(v, value, low, mid - 1);
	}
	else {
		return BinarySearchRecur(v, value, mid + 1, high);
	}
}

int Algorithm::SequeuetiaSearch(vector<int>& v, int value)
{

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == value)
			return i;
	}

	return -1;
}

Algorithm::~Algorithm()
{
}
