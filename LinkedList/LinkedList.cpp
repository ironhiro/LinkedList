#include "LinkedList.h"

template <typename T>
void LinkedList<T>::printAll()
{
	Node<T>* cur = first;
	while (cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

template<typename T>
void LinkedList<T>::insertNode(T& data)
{
	if (first)
	{
		Node<T>* cur=first;
		Node<T>* prev=cur;
		
		Node<T>* node = new Node<T>(data);
		if (size == 1)
		{
			if (cur->data < node->data)
			{
				cur->next = node;
			}
			else
			{
				node->next = cur;
				cur = node;
			}
			size++;
		}
		else
		{
			while (cur)
			{
				if (cur->data < node->data)
				{
					if (cur->next == 0)
					{
						cur->next = node;
						size++;
						break;
					}
				}
				else
				{
					if (cur == first)
					{
						node->next = first;
						first = node;
						size++;
						break;
					}
					else
					{
						node->next = cur;
						prev->next = node;
						size++;
						break;
					}
		
				}
				prev = cur;
				cur = cur->next;
			}
		}
	}
	else
	{
		first = new Node<T>(data);
		size++;
	}
}

template<typename T>
void LinkedList<T>::deleteNode(T& data)
{
	if (size == 0)
		cout << "제거할 요소가 없습니다." << endl;
	else if (search(data) == -1)
		cout << "해당 요소는 존재하지 않습니다." << endl;
	else
	{
		if (search(data) == 0)
		{
			Node<T>* temp = getNode(search(data));
			first = first->next;
		}
		else
		{
			Node<T>* prev = getNode(search(data) - 1);
			Node<T>* temp = prev->next;
			prev->next = temp->next;
		}
		size--;
	}
}



template<typename T>
int LinkedList<T>::search(T & data)
{
	Node<T>* cur = first;
	int index = 0;
	while (cur)
	{
		if (data == cur->data)
			return index;
		index++;
		cur = cur->next;
	}
	return -1;
}

template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}



template<typename T>
Node<T>* LinkedList<T>::getNode(int n)
{
	if (n == -1)
		return nullptr;
	Node<T>* cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	return cur;
}

template<typename T>
T& LinkedList<T>::getData(int n)
{
	Node<T>* cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	return cur->data;
}



template<typename T>
LinkedList<T>::LinkedList()
{
	first = 0;
	size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* cur = first;
	Node<T>* next;
	while (cur)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
}
