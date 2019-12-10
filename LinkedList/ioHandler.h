#pragma once
#include "LinkedList.cpp"
#include <sstream>

enum
{
	INSERT = 1, DELETE, PRINT, EXIT
};


class IOHandler
{
private:
	string fileName;
	LinkedList<Book> list;
public:
	void insertBook();
	void deleteBook();
	void printList();
	void loadFile(string s);
	void saveFile(string s);
	void printMenu();
};

