#include "ioHandler.h"


int main(int argc, char *argv[])
{
	
	if (argc != 1)
	{	
		IOHandler fileHandler;

		fileHandler.loadFile(argv[1]);
		fileHandler.printMenu();
	}
	
	

	return 0;
}