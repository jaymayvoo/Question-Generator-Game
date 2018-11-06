#include "DArray.h"

DArray::DArray()
{
	capacity = NUM_OF_Q;
	a = new QType[capacity]; 
	numOfElem = 0;
	numPrinted = 0;
}

int DArray::getNumOfElem() const
{
	return numOfElem;
}

int DArray::getNumPrinted() const
{
	return numPrinted;
}

void DArray::addQuestion(string newQ)
{
	QType *newQType = new QType(0, newQ);

	if (numOfElem < capacity)
	{
		a[numOfElem] = *newQType;
		++numOfElem;
	}

	else
		cerr << "DArray is full!";

}

void DArray::printRandomQ()
{
	int idx = 0;
	bool printed = 0;

	unsigned seed = time(0);
	srand(seed);

	idx = rand() % (capacity + 1);

	if (numPrinted < capacity)
	{
		while (!printed)
		{
			if (a[idx].getVisited() == 0)
			{
				cout << "\n" << a[idx].getQuestion() << endl;
				a[idx].setVisited(1);
				++numPrinted;
				printed = 1;

			}

			else
			{
				if (idx = capacity)
					idx = 0;
				else
					++idx;

			}
		}
	}

}

void DArray::createDArray(const string& fileName)
{
	ifstream infile;
	string question;
	int idx = 0;

	infile.open(fileName);

	if (!infile)
	{
		cerr << "Cannot open the input file." << endl;
		system("pause"); //to check the error message
		exit(1);
	}


		
		//Read a file until reaches end
		while(!infile.eof())
		{
			getline(infile, question);
			addQuestion(question);
		}


		infile.close();
}

DArray::~DArray() 
{
	delete[] a;
}