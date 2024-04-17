#pragma once


template <typename T>
class mNode
{
public:
	T data;
	mNode<T>;

	mNode();
	~mNode();
};

template <typename T>
class mList
{
public:
	mNode<T>* head;
	mNode<T>* tail;

	mList();
	~mList();
	void push_back(T value);
	int get_Size();

private:
	int size;
};
