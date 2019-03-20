#include "LinkedList.h"

template <typename T>
void LinkedList<T>::printAll()
{

}

template<typename T>
void LinkedList<T>::insertLast(T & e)
{
	if (first)
	{
		last->next = new Node<T>(e);
		last = last->next;
	}
	else
		first = last = new Node<T>(e);
}

template<typename T>
void LinkedList<T>::insertFirst(T & e)
{
	Node<T>* a = new Node<T>(e);
	a->next = first->next;
	first->next = a;
}

template<typename T>
void LinkedList<T>::insertAfter(T & e, Node<T>* node)
{
	Node<T>* a = new Node<T>(e);
	a->next = node->next;
	node->next = a;
}

template<typename T>
void LinkedList<T>::deleteFirst()
{
	if (first->next == 0)
		throw "제거할 연결리스트가 없습니다.";
	Node<T>* temp = first->next;
	first->next = temp->next;
	delete[] temp;
}

template<typename T>
void LinkedList<T>::deleteAfter(Node<T>* node)
{
	if (p == nullptr) throw "널값입니다.";
	Node<T>* temp = node->next;
	node->next = temp->next;
	delete[] temp;
}

template<typename T>
LinkedList<T>::LinkedList()
{
	first = 0;
}
