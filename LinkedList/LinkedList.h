#pragma once

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	friend class LinkedList<T>;
public:
	Node(T& item) { data = item; next = 0; }
private:
	T data;
	Node<T> *next;
};


template <typename T>
class LinkedList
{
private:
	Node<T> *first, *last;
public:
	LinkedList();
	void printAll();
	void insertLast(T& e);
	void insertFirst(T& e);
	void insertAfter(T& e, Node<T>* node);
	void deleteFirst();
	void deleteAfter(Node<T>* node);
	
};


