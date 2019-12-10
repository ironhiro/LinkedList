#include "Book.h"

Book::Book()
{
	book_id = "";
	book_name = "";
}

Book::Book(Book& b)
{
	this->book_id = b.book_id;
	this->book_name = b.book_name;
}

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

void Book::setBookId(string book_id)
{
	this->book_id = book_id;
}

void Book::setBookName(string book_name)
{
	this->book_name = book_name;
}

bool Book::operator>(Book& b)
{
	if (book_name > b.book_name)
		return true;
	return false;
}

bool Book::operator>=(Book& b)
{
	if (book_name > b.book_name)
		return true;
	return false;
}

bool Book::operator<(Book& b)
{
	return !(*this >= b);
}

bool Book::operator<=(Book& b)
{
	return !(*this > b);
}

bool Book::operator==(Book& b)
{
	if (book_id == b.book_id)
		return true;
	return false;
}

bool Book::operator!=(Book& b)
{
	return !(*this==b);
}


ostream& operator<<(ostream& os, Book& b)
{
	os << b.book_id << " [" << b.book_name << "]";
	return os;
}

ofstream& operator<<(ofstream& os, Book& b)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	os << b.book_id << " " << b.book_name;
	return os;
}
