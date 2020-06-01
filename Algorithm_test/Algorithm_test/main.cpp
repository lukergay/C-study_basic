#include <iostream>
#include<memory>
#include"SearchAlgorithm.h"
#include "SortAlgorithm.h"
using namespace std;

int main() {

	//auto_ptr<SearchAlgorithm> p(new SearchAlgorithm());
	auto_ptr<SortAlgorithm> p(new SortAlgorithm());
	vector<int> a = { 14, 12, 33, 54, 5, 6 };
	vector<int> b;
	b.resize(a.size());
 	p.get()->merge_sort_recur(a,b,0,a.size()-1);


	for (size_t i = 0; i < a.size(); ++i)
		cout << " " << a[i];

	system("pause");
	return 0;
}
