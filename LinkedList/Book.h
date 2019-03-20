#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
private:
	string book_id;
	string book_name;
public:
	Book(string book_id, string book_name);
	string getBookId();
	string getBookName();
};

