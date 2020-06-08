#include "SqList.h"



SqList::SqList()
{
}

Status SqList::init_list(SeqList & L, int size, int inc)
{
	L.elem_ = (ElemType*)malloc(size*sizeof(ElemType));
	if (L.elem_ == NULL)
		return OVERFLOW;
	L.size_ = size;
	L.length_ = 0;
	L.incrment_ = inc;
	return OK;
}

Status SqList::destroy_list(SeqList & L)
{
	if (L.elem_ == NULL)
		return OVERFLOW;

	free(L.elem_);
	return OK;
}

Status SqList::clear_list(SeqList & L)
{
	if (L.length_ != 0)
		L.length_ = 0;
	return OK;
}

Status SqList::empty_list(SeqList & L)
{
	if (L.length_ == 0)
		return TRUE;
	return FALSE;
}

int SqList::length_list(SeqList & L)
{
	return L.length_;
}

Status SqList::get_elem_list(SeqList & L, int i, ElemType & e)
{
	if (L.elem_ == NULL)
		return OVERFLOW;
	if (L.length_ < i)
		return OVERFLOW;

	e = L.elem_[--i];
	return OK;
}

int SqList::search_elem_list(SeqList & L, ElemType & e)
{
	if (L.elem_ == NULL)
		return OVERFLOW;

	for (int i = 0; i < L.length_; ++i)
		if (L.elem_[i] == e)
			return i;

	return OVERFLOW;
}

Status SqList::traverse_list(SeqList & L, Status(*visit)(ElemType e))
{
	if (L.elem_ == NULL || L.length_==0)
		return ERROR;

	for (int i = 0; i < L.length_; ++i)
		visit(L.elem_[i]);
	
	return OK;
}

Status SqList::alter_elem_list(SeqList & L, int i, ElemType e)
{
	if (L.elem_ == NULL || i > L.length_)
		return ERROR;

	L.elem_[--i] = e;
	return Status();
}

Status SqList::append_elem_list(SeqList & L, ElemType e)
{
	if (L.length_ >= L.size_) 
		return ERROR;

	L.elem_[L.length_] = e;
	L.length_++;

	return OK;
}

Status SqList::delete_elem_list(SeqList & L, ElemType & e)
{
	if (L.elem_ == NULL || L.length_ == 0)
		return FALSE;

	e = L.elem_[L.length_-1];
	L.length_--;

	//e=L.elem[--L.length]; ?

	return OK;
}

SqList::~SqList()
{
}
