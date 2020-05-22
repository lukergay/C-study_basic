#include <iostream>
#include<memory>
#include"Algorithm.h"
using namespace std;

int main() {

	auto_ptr<Algorithm> p(new Algorithm());
	vector<int> a = { 1, 2, 3, 4, 5, 6 };
	int key = 5;
	printf("%d\n", p.get()->BinarySearchWhile(a,3));

	system("pause");
	return 0;
}
