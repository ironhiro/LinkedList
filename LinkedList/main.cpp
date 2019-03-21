#include "ioHandler.h"

enum 
{
	INSERT=1, DELETE, PRINT, EXIT
};

int main(int argc, char *argv[])
{
	
	if (argc != 1)
	{
		int select = 0;
		IOHandler fileHandler;

		fileHandler.loadFile(argv[1]);
		fileHandler.printMenu();

		while (select != EXIT)
		{
			string book_name, book_no;
			cout << "원하는 기능을 선택하세요 : ";
			cin >> select;
			switch (select)
			{
			case INSERT:
				cout << "도서번호와 도서명을 입력하세요 : ";
				cin >> book_no;
				getline(cin,book_name); 
				book_name = book_name.substr(1); //공백 제거
				fileHandler.insertBook(book_no, book_name);
				break;
			case DELETE:
				cout << "도서번호를 입력하세요 : ";
				cin >> book_no;
				fileHandler.deleteBook(book_no);
				break;
			case PRINT:
				fileHandler.printList();
				break;
			case EXIT:
				fileHandler.saveFile(argv[1]);
				cout << "종료합니다." << endl;
				break;
			}
		}
	}
	
	

	return 0;
}