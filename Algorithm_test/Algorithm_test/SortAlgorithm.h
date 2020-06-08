#pragma once

#include<iostream>
#include<vector>


using namespace std;

//Ͱ���������
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

	//���򷽷�
	/*
	*��1)ѡ������
	* (2)ð������
	* (3)��������
	*��4)��������
	*��5)ϣ������
	* (6)�鲢����
	*��7)��������
	* (8)Ͱ����
	* (9)������
	*��10)��������
	*/

	//ѡ������
	/*
		
	��������������������������������һ����С��Ԫ�ظ����������ĺ��档�����飺�Ƚϵö࣬�����١�

	ѡ������˼·��
		1. ��δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
		2. ��ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
		3. �Դ����ƣ�ֱ������Ԫ�ؾ��������

	ʱ�临�Ӷ� O(n2)
	*/
	void selection_sort(vector<int> &v);
	/*��ģ�� ѡ������*/
	template<typename T>
	void selection_sort_t(vector<T> & v);

	//ð������
	/*
	����������������������������ͨ�������ҳ����Ԫ�طŵ�������ǰ�ˡ�

	ѡ������˼·��
		1. �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
		2. ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
		3. ������е�Ԫ���ظ����ϵĲ��裬�������һ����
		4. ����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
	*/
	void bubble_sort(vector<int> & v);
	void bubble_sort_insert(vector<int> &v);
	template<typename T>
	void bubble_sort_t(vector<T> & v);


	//��������

/*
	�����������������������������ĵ�һ��Ԫ�ز��뵽�������ĺ��ʵ�λ�á������飺�Ƚϵ��٣����öࡣ
	��������˼·��
	1. �ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
	2. ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
	3. �����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ��
	4. �ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
	5. ����Ԫ�ز��뵽��λ�ú�
	6. �ظ�����2~5
*/
	void insert_sort(vector<int>& v);

	//��������

	/*
	����ô������ǰ���.


��С������׼Ԫ�أ����������������������ѡһ��Ԫ������׼����С�ڻ�׼��Ԫ�ط��ڻ�׼֮ǰ�����ڻ�׼��Ԫ�ط��ڻ�׼֮���ٷֱ��С�������������������

	��������˼·��
	1. ѡȡ��һ����Ϊ��׼
	2. ���Ȼ�׼С����������ǰ�棬�Ȼ�׼���������������
	3. �����������ظ��ڶ�����ֱ��������ֻ��һ����

	���������㷨�Ļ�������
	ʱ�临�Ӷȣ�O��n*lgn��
	���O��n^2��
	�ռ临�Ӷȣ�O��n*lgn�� ���ȶ���

	������⣺https://blog.csdn.net/MoreWindows/article/details/6684558

	*/
	void quick_sort_recur(vector<int> & v,int low, int high);
	template<typename T>
	void quick_sort_recur_t(vector<int>&v, T low, T high);


	//ϣ������
	/*
	ϣ������ÿһ�ְ������Ⱦ����ļ�����в������򣬼����������С�����һ��һ��Ҫ��1��

	��������T(n) = O(nlogn)��������T(n) = O(n)��ƽ�������T(n) = O(nlogn)��
	*/
	template<typename T>
	void shell_sort(vector<T>&v);

	//�鲢����
	/*
	 �鲢���򣺰����ݷ�Ϊ���Σ������������ѡ��С��Ԫ�����������ݶε�ĩβ���ɴ��ϵ��»���µ��Ͻ��С�

	ƽ��ʱ�临�Ӷȣ�O(nlogn)
	���ʱ�临�Ӷȣ�O(n)
	���ʱ�临�Ӷȣ�O(nlogn)
	�ռ临�Ӷȣ�O(n)
	����ʽ��In-place
	�ȶ��ԣ��ȶ�
	*/
	void merge_sort_while(vector<int> & v);
	template<typename T>
	void merge_sort_recur(vector<T> &a, vector<T>&b, int start, int end);


	//��������
	/*
		��������ͳ��С�ڵ��ڸ�Ԫ��ֵ��Ԫ�صĸ���i�����Ǹ�Ԫ�ؾͷ���Ŀ�����������iλ��i��0����

			�����������һ�����裬���������е���������Ϊ�������ҳ����ڣ�0��k��������֮�ڡ�
			��� k��������������ֵ�� �����������ϴ�Ŀռ临�Ӷȣ�һ������������ 0 �� 100 ֮������ֵ���õ��㷨�����������ʺϰ���ĸ˳������������
			���������ǱȽ�����������ٶȿ����καȽ������㷨��
			ʱ�临�Ӷ�Ϊ O��n+k�����ռ临�Ӷ�Ϊ O��n+k��

		�㷨�Ĳ������£�

		1. �ҳ��������������������С��Ԫ��
		2. ͳ��������ÿ��ֵΪ i ��Ԫ�س��ֵĴ������������� C �ĵ� i ��
		3. �����еļ����ۼӣ��� C �еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ�
		4. �������Ŀ�����飺��ÿ��Ԫ�� i ����������ĵ� C[i] �ÿ��һ��Ԫ�ؾͽ� C[i] ��ȥ 1
	*/
	void count_sort(vector<int> & v);


	//Ͱ����

	/*
		Ͱ���򣺽�ֵΪi��Ԫ�ط���i��Ͱ��������ΰ�Ͱ���Ԫ�ص�������
		����������A[1...n]�ڵ�Ԫ��������ֲ���[0,1)�����ڵĵĸ�����.
		������������B[0....n-1]��ÿһ��Ԫ�ض�����һ������.
		��A��ÿ��Ԫ�س���N(�����ģ)ȡ��,���Դ�Ϊ��������(��������)����B�Ķ�Ӧλ�õ�������. ������е���������������������������.
	Ͱ������˼·��
		1. ����һ�����������鵱����Ͱ�ӡ�
		2. Ѱ�����У����Ұ���Ŀһ��һ���ŵ���Ӧ��Ͱ��ȥ��
		3. ��ÿ�����ǿյ�Ͱ�ӽ�������
		4. �Ӳ��ǿյ�Ͱ�������Ŀ�ٷŻ�ԭ���������С�

		�������ݷֲ���[0��100)֮�䣬��������Ͱ��ͬʱ��������Ȼ��Ѹ���Ͱ�е����ݺϲ���


	*/
	void bucket_sort(vector<int> &v);


	//���� ��Ӧ���������
	ListNode * insert(ListNode* head, int value);
	//�ں϶�������
	ListNode * merge(ListNode * headl, ListNode * head2);

	//������


	/*

	�����򣺣����ѣ������������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ��ѡ�
			�����������й����һ���󶥶ѣ�
			��ʱ���������е����ֵ���ǶѶ��ĸ��ڵ㡣
			������ĩβԪ�ؽ��н�������ʱĩβ��Ϊ���ֵ��
			Ȼ��ʣ��n-1��Ԫ�����¹����һ���ѣ�
			������õ�n��Ԫ�صĴ�Сֵ��
			��˷���ִ�У����ܵõ�һ������������

	���裺
		a.���������й�����һ���ѣ���������������ѡ��󶥶ѻ�С����;
		b.���Ѷ�Ԫ����ĩβԪ�ؽ����������Ԫ��"��"������ĩ��;
		c.���µ����ṹ��ʹ������Ѷ��壬Ȼ����������Ѷ�Ԫ���뵱ǰĩβԪ�أ�����ִ�е���+�������裬ֱ��������������

�������Ǿ����������ʵ���ȫ��������
		ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶ѣ�
		ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ����ΪС���ѡ�

	���������ã�ƽ��ʱ�临�ӶȾ�ΪO(nlogn)����Ҳ�ǲ��ȶ�����
	*/
	void heap_sort(vector<int> & v);

	void max_heapify(vector<int>& v_arr, int start, int end);

	//��������:��ؼ��ֵ������㷨������Ͱ����ʵ�֡�
	/*

	��������(Radix Sort)��Ͱ�������չ�����Ļ���˼���ǣ���������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ�

	���������ǣ������д��Ƚ���ֵͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油�㡣Ȼ�󣬴����λ��ʼ�����ν���һ������
		���������λ����һֱ�����λ��������Ժ�, ���оͱ��һ���������С�

	���ӣ�
		1. ���ո�λ����������
		2. ����ʮλ����������
		3. ���հ�λ����������
	*/
	void radix_sort(vector<int> &v_arr);
	/*��ȡ��������������λ��*/
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

	//�����һ��Ϊ��׼
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

	//�ж��м�ı�־λ �����һ��ֵ�ñȽ�
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
