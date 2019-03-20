#include "FileHandler.h"


enum 
{
	INSERT=1, DELETE, PRINT, EXIT
};

int main(int argc, char *argv[])
{
	int select = 0;
	FileHandler fileHandler;
	LinkedList<Book> list;
	fileHandler.loadFile(argv[1]);
	fileHandler.printMenu();
	while (select != EXIT)
	{
		cout << "원하는 기능을 선택하세요 : ";
		cin >> select;
		switch (select)
		{
		case INSERT:
			cout << "도서번호와 도서명을 입력하세요 : ";
			break;
		case DELETE:
			cout << "도서번호를 입력하세요 : ";
			break;
		case PRINT:
			list.printAll();
			break;
		case EXIT:
			cout << "종료합니다." << endl;
			fileHandler.saveFile(argv[1]);
			break;
		}
	}

	return 0;
}