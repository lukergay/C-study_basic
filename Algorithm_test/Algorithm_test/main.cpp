#include <iostream>
#include<memory>
#include"SearchAlgorithm.h"
#include "SortAlgorithm.h"
#include "SqList.h"
#include"SqStack.h"

using namespace std;

/*顺序表测试样例*/
void test_seqList();
Status visit_print(ElemType e) { printf("%d \t", e); return OK; }

/*顺序栈测试样例*/
void test_seq_stack();

int main() {

	//auto_ptr<SearchAlgorithm> p(new SearchAlgorithm());
	auto_ptr<SortAlgorithm> p(new SortAlgorithm());
	//vector<int> a = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	vector<int> a = { 12,5,2,56,2,1,25 };
	vector<int> b;
	b.resize(a.size());
 	p.get()->radix_sort(a);


	for (size_t i = 0; i < a.size(); ++i)
		cout << " " << a[i];

	//测试顺序表
	test_seqList();

	//测试顺序栈
	test_seq_stack();

	system("pause");
	return 0;
}


void test_seqList()
{
	auto_ptr<SqList> list_sq(new SqList());
	//定义表L
	SeqList L;

	//定义测量值
	int size, increment, i, len = 5;


	//初始化测试值
	size = len;
	increment = 5;
	ElemType e = 0, eArray[5] = { 1,2,3,4,5 };

	//显示特殊值
	printf("---【顺序栈】---\n");
	printf("表L的size为：%d\n表L的increment为：%d\n", size, increment);
	printf("待测试元素为：\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//初始化顺序表
	if (!list_sq.get()->init_list(L, size, increment)) {
		printf("初始化顺序表失败\n");
		exit(0);
	}
	printf("已初始化顺序表\n");

	//判空
	if (TRUE == list_sq.get()->empty_list(L))
		printf("此表为空表！！！\n");
	else
		printf("此表不是空表啊\n");


	//添加数据
	printf("将待测元素入表：\n");

	for (i = 0; i < len; ++i) {
		if (ERROR == list_sq.get()->append_elem_list(L, eArray[i])) {
			printf("入表失败 \n");
		}
	}
	printf(" 入表成功 \n");

	//遍历表内容
	printf("此时表内元素为：\n");
	list_sq.get()->traverse_list(L, visit_print);

	//出表
	printf("\n将表尾元素入表到e：\n");
	if (ERROR == list_sq.get()->delete_elem_list(L, e))
		printf("出表失败\n");
	printf("出表成功\n出表元素为%d\n", e);

	//遍历表内容
	printf("此时表内元素为：\n");
	list_sq.get()->traverse_list(L, visit_print);


	//销毁顺序表
	printf("\n销毁顺序表\n");
	if (OK == list_sq.get()->clear_list(L) &OK == list_sq.get()->destroy_list(L))
		printf("销毁成功\n");
	else
		printf("销毁失败\n");

	return;
}

void test_seq_stack()
{
	auto_ptr<SqStack> stack_sq(new SqStack());
	//定义表L
	SeqSrack S;

	//定义测量值
	int size, increment, i, len = 5;


	//初始化测试值
	size = len;
	increment = 5;
	ElemType e = 0, eArray[5] = { 1,2,3,4,5 };

	//显示特殊值
	printf("---【顺序栈】---\n");
	printf("栈L的size为：%d\n栈L的increment为：%d\n", size, increment);
	printf("待测试元素为：\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//初始化顺序栈
	if (!stack_sq.get()->init_stack(S, size, increment)) {
		printf("初始化顺序栈失败\n");
		exit(0);
	}
	printf("已初始化顺序栈\n");

	//判空
	if (TRUE == stack_sq.get()->empty_stack(S))
		printf("此栈为空栈！！！\n");
	else
		printf("此栈不是空栈啊\n");


	//添加数据
	printf("将待测元素入栈：\n");

	for (i = 0; i < len; ++i) {
		if (ERROR == stack_sq.get()->push_stack(S, eArray[i])) {
			printf("入栈失败 \n");
		}
	}
	printf(" 入栈成功 \n");

	//判断非空
	if (stack_sq.get()->empty_stack(S)) printf("S栈为空\n");
	else printf("S栈非空\n");

	//取栈S的栈顶元素    
	printf("栈S的栈顶元素为：\n");
	printf("%d\n", stack_sq.get()->get_top_stack(S, e));

	//栈S元素出栈
	printf("栈S元素出栈为：\n");
	for (i = 0, e = 0; i < S.size; i++) {
		printf("%d\t  --> %d  \n", stack_sq.get()->pop_stack(S, e),e);
	}
	printf("\n");

	//清空栈S
	stack_sq.get()->clear_stack(S);
	printf("已清空栈S\n");

	return;
}
