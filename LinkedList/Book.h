#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Book
{
private:
	string book_id;
	string book_name;
public:
	Book();
	Book(Book& b);
	Book(string book_id, string book_name);
	string getBookId();
	string getBookName();
	void setBookId(string book_id);
	void setBookName(string book_name);
	friend ostream& operator<<(ostream &os, Book& b);
	friend ofstream& operator<<(ofstream& os, Book& b);
	bool operator>(Book& b);
	bool operator >=(Book& b);
	bool operator<(Book& b);
	bool operator<=(Book& b);
	bool operator==(Book& b);
	bool operator!=(Book& b);
};

