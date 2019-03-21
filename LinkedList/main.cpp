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
			cout << "���ϴ� ����� �����ϼ��� : ";
			cin >> select;
			switch (select)
			{
			case INSERT:
				cout << "������ȣ�� �������� �Է��ϼ��� : ";
				cin >> book_no;
				getline(cin,book_name); 
				book_name = book_name.substr(1); //���� ����
				fileHandler.insertBook(book_no, book_name);
				break;
			case DELETE:
				cout << "������ȣ�� �Է��ϼ��� : ";
				cin >> book_no;
				fileHandler.deleteBook(book_no);
				break;
			case PRINT:
				fileHandler.printList();
				break;
			case EXIT:
				fileHandler.saveFile(argv[1]);
				cout << "�����մϴ�." << endl;
				break;
			}
		}
	}
	
	

	return 0;
}