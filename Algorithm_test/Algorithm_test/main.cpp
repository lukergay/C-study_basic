#include <iostream>
#include<memory>
#include"SearchAlgorithm.h"
#include "SortAlgorithm.h"
using namespace std;

int main() {

	//auto_ptr<SearchAlgorithm> p(new SearchAlgorithm());
	auto_ptr<SortAlgorithm> p(new SortAlgorithm());
	vector<int> a = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	vector<int> b;
	b.resize(a.size());
 	p.get()->heap_sort(a);


	for (size_t i = 0; i < a.size(); ++i)
		cout << " " << a[i];

	system("pause");
	return 0;
}
