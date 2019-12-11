#pragma once
#include "Book.h"

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	friend class LinkedList<T>;
public:
	Node(const T& data) { this->data = data; }
private:
	T data;
	Node<T> *next;
};


template <typename T>
class LinkedList
{
private:
	Node<T>* first;
	int size;
public:
	LinkedList();
	~LinkedList();
	void printAll();
	void insertNode(T& data);
	void deleteNode(T& data);
	int search(T& data);
	int getSize();
	Node<T>* getNode(int n);
	T& getData(int n);
};


