#include "ioHandler.h"

void IOHandler::insertBook(string no, string name)
{
	list.insertNode(no, name);
}

void IOHandler::deleteBook(string no)
{
	list.deleteNode(no);
}

void IOHandler::printList()
{
	list.printAll();
}

void IOHandler::loadFile(string s)
{
	string book_no, book_name, line, token;
	ifstream fin(s);
	
	
	while (getline(fin,line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ') //ù��° ������ ������
			{
				book_no = line.substr(0, i);
				book_name = line.substr(i + 1);
				list.insertNode(book_no, book_name);
				break;//Ż��
			}
		}
		
	}
	fin.close();
}

void IOHandler::saveFile(string s)
{
	ofstream fout(s);
	for (int i = 0; i < list.getSize(); i++)
	{
		fout << list.getBookNo(i) << " " << list.getBookName(i) << endl;
	}
	fout.close();
}

void IOHandler::printMenu()
{
	cout << "============================" << endl;
	cout << "(1) �� ���� �Է�" << endl;
	cout << "(2) ���� ����" << endl;
	cout << "(3) ������ ������ ��ü ���" << endl;
	cout << "(4) ���Ͽ� �����ϰ� ����" << endl;
	cout << "============================" << endl;
}
