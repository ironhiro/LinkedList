#include "Book.h"

Book::Book(string book_id, string book_name)
{
	this->book_id = book_id;
	this->book_name = book_name;
}

string Book::getBookId()
{
	return book_id;
}

string Book::getBookName()
{
	return book_name;
}
