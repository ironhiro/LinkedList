#include "ioHandler.h"

void IOHandler::insertBook()
{
	string book_name, book_no;
	cout << "������ȣ�� �������� �Է��ϼ��� : ";
	cin >> book_no;
	getline(cin, book_name);
	book_name = book_name.substr(1); //���� ����
	Book b(book_no, book_name);
	list.insertNode(b);
}

void IOHandler::deleteBook()
{
	string book_no;
	cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> book_no;
	Book b;
	b.setBookId(book_no);
	list.deleteNode(b);
}

void IOHandler::printList()
{
	list.printAll();
}

void IOHandler::loadFile(string s)
{
	fileName = s;
	string book_no, book_name, line, token;
	ifstream fin(fileName);
	if (fin)
	{
		while (getline(fin, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ') //ù��° ������ ������
				{
					book_no = line.substr(0, i);
					book_name = line.substr(i + 1);
					Book b(book_no, book_name);
					list.insertNode(b);
					break;//Ż��
				}
			}

		}
	}
	else
		cout << "������ �������� �ʽ��ϴ�. ���α׷��� �����մϴ�." << endl;
	
	fin.close();
}

void IOHandler::saveFile(string s)
{
	ofstream fout(s);
	for (int i = 0; i < list.getSize(); i++)
	{
		fout << list.getData(i) << endl;
	}
	fout.close();
}

void IOHandler::printMenu()
{
	int select = 0;
	
	cout << "============================" << endl;
	cout << "(1) �� ���� �Է�" << endl;
	cout << "(2) ���� ����" << endl;
	cout << "(3) ������ ������ ��ü ���" << endl;
	cout << "(4) ���Ͽ� �����ϰ� ����" << endl;
	cout << "============================" << endl;

	while (select != EXIT)
	{
				
		cout << "���ϴ� ����� �����ϼ��� : ";
		cin >> select;
		switch (select)
		{
		case INSERT:
			insertBook();
			break;
		case DELETE:
			deleteBook();
			break;
		case PRINT:
			printList();
			break;
		case EXIT:
			saveFile(fileName);
			cout << "�����մϴ�." << endl;
			break;
		}
	}
}
