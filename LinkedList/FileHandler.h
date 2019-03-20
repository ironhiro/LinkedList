#pragma once
#include "LinkedList.h"
#include "Book.h"
#include <fstream>
#include "Book.h"
class FileHandler
{
public:
	void loadFile(string s);
	void saveFile(string s);
	void printMenu();
};

