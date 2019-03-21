#include "LinkedList.h"

template <typename T>
void LinkedList<T>::printAll()
{
	Node<T>* cur = first;
	while (cur)
	{
		cout << cur->book_name << " [" << cur->book_no << "]" << endl;
		cur = cur->next;
	}
}

template<typename T>
void LinkedList<T>::insertNode(const T& data1, const T& data2)
{
	if (first)
	{
		Node<T>* cur=first;
		Node<T>* prev=cur;
		
		Node<T>* node = new Node<T>(data1, data2);
		if (size == 1)
		{
			if (cur->book_name < data2)
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
				if (cur->book_name < data2)
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
		first = new Node<T>(data1, data2);
		size++;
	}
}

template<typename T>
void LinkedList<T>::deleteNode(const T& data)
{
	if (size == 0)
		throw "제거할 요소가 없습니다.";
	else if (search(data) == -1)
		throw "해당 요소는 존재하지 않습니다.";
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
int LinkedList<T>::search(const T & data)
{
	Node<T>* cur = first;
	int index = 0;
	while (cur)
	{
		if (data == cur->book_no)
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
T LinkedList<T>::getBookNo(int n)
{
	Node<T>* cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	return cur->book_no;
}

template<typename T>
T LinkedList<T>::getBookName(int n)
{
	Node<T>* cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	return cur->book_name;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int n)
{
	Node<T>* cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	return cur;
}



template<typename T>
LinkedList<T>::LinkedList()
{
	first = 0;
	size = 0;
}
