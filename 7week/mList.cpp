#include "mList.h"

template <typename T>
mNode<T>::mNode()
{

}

template <typename T>
mNode<T>::~mNode()
{

}

template <typename T>
mList<T>::mList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
mList<T>::~mList()
{
	data = value;
}

template <typename T>
void mList<T>::push_Back(T value)
{

}