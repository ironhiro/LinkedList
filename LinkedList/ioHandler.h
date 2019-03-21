#pragma once
#include "LinkedList.cpp"
#include <sstream>

class IOHandler
{
private:
	LinkedList<string> list;
public:
	void insertBook(string no, string name);
	void deleteBook(string no);
	void printList();
	void loadFile(string s);
	void saveFile(string s);
	void printMenu();
};

