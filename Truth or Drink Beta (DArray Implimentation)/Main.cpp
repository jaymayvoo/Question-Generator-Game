#include "DArray.h"

const string FILE_NAME = "question_list.txt";

int main()
{
	DArray a1;
	a1.createDArray(FILE_NAME);
	char response;

	cout << "***WELCOME TO TRUTH OR DRINK***" << endl;
	cout << "To generate a question, enter y" << endl;
	cout << "To exit program, enter n" << endl;
	cin >> response;
	while (response == 'y')
	{ 
		a1.printRandomQ();
		cout << "\nTo generate a question, enter y" << endl;
		cout << "To exit program, enter n \n" << endl;
		cin >> response;

		if (a1.getNumPrinted() >= a1.getNumOfElem())
		{
			cout << "There are no more new questions to be generated." << endl;
			response = 'n';
		}
	}

	cout << "\nThank you for playing Truth or Drink :)" << endl;

	system("pause");
	return 0;
}