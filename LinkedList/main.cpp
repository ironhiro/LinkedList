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
		cout << "���ϴ� ����� �����ϼ��� : ";
		cin >> select;
		switch (select)
		{
		case INSERT:
			cout << "������ȣ�� �������� �Է��ϼ��� : ";
			break;
		case DELETE:
			cout << "������ȣ�� �Է��ϼ��� : ";
			break;
		case PRINT:
			list.printAll();
			break;
		case EXIT:
			cout << "�����մϴ�." << endl;
			fileHandler.saveFile(argv[1]);
			break;
		}
	}

	return 0;
}