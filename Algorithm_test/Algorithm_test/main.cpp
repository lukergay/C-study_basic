#include <iostream>
#include<memory>
#include"SearchAlgorithm.h"
using namespace std;

int main() {

	auto_ptr<SearchAlgorithm> p(new SearchAlgorithm());
	vector<int> a = { 1, 2, 3, 4, 5, 6 };
	int key = 5;
	printf("%d\n", p.get()->binary_search_while(a,3));

	system("pause");
	return 0;
}
