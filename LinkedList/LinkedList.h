#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	friend class LinkedList<T>;
public:
	Node(const T& data1,const T& data2) { book_no = data1; book_name = data2; next = 0; }
private:
	T book_no;
	T book_name;
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
	void printAll();
	void insertNode(const T& data1, const T& data2);
	void deleteNode(const T& data);
	
	
	int search(const T& data);
	int getSize();
	T getBookNo(int n);
	T getBookName(int n);
	Node<T>* getNode(int n);
};


