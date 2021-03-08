#include <iostream>
#include<memory>
#include"SearchAlgorithm.h"
#include "SortAlgorithm.h"
#include "SqList.h"
#include"SqStack.h"

using namespace std;

/*˳����������*/
void test_seqList();
Status visit_print(ElemType e) { printf("%d \t", e); return OK; }

/*˳��ջ��������*/
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

	//����˳���
	test_seqList();

	//����˳��ջ
	test_seq_stack();

	system("pause");
	return 0;
}


void test_seqList()
{
	auto_ptr<SqList> list_sq(new SqList());
	//�����L
	SeqList L;

	//�������ֵ
	int size, increment, i, len = 5;


	//��ʼ������ֵ
	size = len;
	increment = 5;
	ElemType e = 0, eArray[5] = { 1,2,3,4,5 };

	//��ʾ����ֵ
	printf("---��˳��ջ��---\n");
	printf("��L��sizeΪ��%d\n��L��incrementΪ��%d\n", size, increment);
	printf("������Ԫ��Ϊ��\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//��ʼ��˳���
	if (!list_sq.get()->init_list(L, size, increment)) {
		printf("��ʼ��˳���ʧ��\n");
		exit(0);
	}
	printf("�ѳ�ʼ��˳���\n");

	//�п�
	if (TRUE == list_sq.get()->empty_list(L))
		printf("�˱�Ϊ�ձ�����\n");
	else
		printf("�˱��ǿձ�\n");


	//�������
	printf("������Ԫ�����\n");

	for (i = 0; i < len; ++i) {
		if (ERROR == list_sq.get()->append_elem_list(L, eArray[i])) {
			printf("���ʧ�� \n");
		}
	}
	printf(" ���ɹ� \n");

	//����������
	printf("��ʱ����Ԫ��Ϊ��\n");
	list_sq.get()->traverse_list(L, visit_print);

	//����
	printf("\n����βԪ�����e��\n");
	if (ERROR == list_sq.get()->delete_elem_list(L, e))
		printf("����ʧ��\n");
	printf("����ɹ�\n����Ԫ��Ϊ%d\n", e);

	//����������
	printf("��ʱ����Ԫ��Ϊ��\n");
	list_sq.get()->traverse_list(L, visit_print);


	//����˳���
	printf("\n����˳���\n");
	if (OK == list_sq.get()->clear_list(L) &OK == list_sq.get()->destroy_list(L))
		printf("���ٳɹ�\n");
	else
		printf("����ʧ��\n");

	return;
}

void test_seq_stack()
{
	auto_ptr<SqStack> stack_sq(new SqStack());
	//�����L
	SeqSrack S;

	//�������ֵ
	int size, increment, i, len = 5;


	//��ʼ������ֵ
	size = len;
	increment = 5;
	ElemType e = 0, eArray[5] = { 1,2,3,4,5 };

	//��ʾ����ֵ
	printf("---��˳��ջ��---\n");
	printf("ջL��sizeΪ��%d\nջL��incrementΪ��%d\n", size, increment);
	printf("������Ԫ��Ϊ��\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//��ʼ��˳��ջ
	if (!stack_sq.get()->init_stack(S, size, increment)) {
		printf("��ʼ��˳��ջʧ��\n");
		exit(0);
	}
	printf("�ѳ�ʼ��˳��ջ\n");

	//�п�
	if (TRUE == stack_sq.get()->empty_stack(S))
		printf("��ջΪ��ջ������\n");
	else
		printf("��ջ���ǿ�ջ��\n");


	//�������
	printf("������Ԫ����ջ��\n");

	for (i = 0; i < len; ++i) {
		if (ERROR == stack_sq.get()->push_stack(S, eArray[i])) {
			printf("��ջʧ�� \n");
		}
	}
	printf(" ��ջ�ɹ� \n");

	//�жϷǿ�
	if (stack_sq.get()->empty_stack(S)) printf("SջΪ��\n");
	else printf("Sջ�ǿ�\n");

	//ȡջS��ջ��Ԫ��    
	printf("ջS��ջ��Ԫ��Ϊ��\n");
	printf("%d\n", stack_sq.get()->get_top_stack(S, e));

	//ջSԪ�س�ջ
	printf("ջSԪ�س�ջΪ��\n");
	for (i = 0, e = 0; i < S.size; i++) {
		printf("%d\t  --> %d  \n", stack_sq.get()->pop_stack(S, e),e);
	}
	printf("\n");

	//���ջS
	stack_sq.get()->clear_stack(S);
	printf("�����ջS\n");

	return;
}
