#include "SqStack.h"



SqStack::SqStack()
{
}

Status SqStack::init_stack(SeqSrack & S, int size, int inc)
{
	S.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (S.elem == NULL)
		return OVERFLOW;
	
	S.size = size;
	S.top = 0;
	S.increment = inc;

	return OK;
}

Status SqStack::destroy_stack(SeqSrack & S)
{
	if (S.elem != NULL)
		free(S.elem);
	S.elem = NULL;

	return OK;
}

Status SqStack::empty_stack(SeqSrack S)
{
	if (S.top == 0)
		return TRUE;
	return FALSE;
}

void SqStack::clear_stack(SeqSrack & S)
{
	if (0 == S.top) return;
	S.size = 0;
	S.top = 0;
}

Status SqStack::push_stack(SeqSrack & S, ElemType e)
{
	if (S.top >= S.size) {
		ElemType * new_base;
		new_base = (ElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == new_base)
			return OVERFLOW;

		S.elem = new_base;
		S.size += S.increment;
	}

	S.elem[S.top++] = e;

	return OK;
}

Status SqStack::pop_stack(SeqSrack & S, ElemType & e)
{
	if (S.elem == NULL || S.top == 0)
		return ERROR;
	
	e = S.elem[S.top - 1];
	S.top--;
	return OK;
}

Status SqStack::get_top_stack(SeqSrack S, ElemType & e)
{
	if (S.elem == NULL || S.top == 0)
		return ERROR;

	e = S.elem[S.top - 1];
	return OK;
}


SqStack::~SqStack()
{
}
