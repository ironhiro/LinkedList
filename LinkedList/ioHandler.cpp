#include "ioHandler.h"

void IOHandler::insertBook()
{
	string book_name, book_no;
	cout << "도서번호와 도서명을 입력하세요 : ";
	cin >> book_no;
	getline(cin, book_name);
	book_name = book_name.substr(1); //공백 제거
	Book b(book_no, book_name);
	list.insertNode(b);
}

void IOHandler::deleteBook()
{
	string book_no;
	cout << "도서번호를 입력하세요 : ";
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
				if (line[i] == ' ') //첫번째 공백을 만나면
				{
					book_no = line.substr(0, i);
					book_name = line.substr(i + 1);
					Book b(book_no, book_name);
					list.insertNode(b);
					break;//탈출
				}
			}

		}
	}
	else
		cout << "파일이 존재하지 않습니다. 프로그램을 종료합니다." << endl;
	
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
	cout << "(1) 새 도서 입력" << endl;
	cout << "(2) 도서 삭제" << endl;
	cout << "(3) 도서명 순으로 전체 출력" << endl;
	cout << "(4) 파일에 저장하고 종료" << endl;
	cout << "============================" << endl;

	while (select != EXIT)
	{
				
		cout << "원하는 기능을 선택하세요 : ";
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
			cout << "종료합니다." << endl;
			break;
		}
	}
}
