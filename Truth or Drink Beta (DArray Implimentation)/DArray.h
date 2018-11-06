#ifndef DARRAY_H
#define DARAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<fstream>

using namespace std;

const int NUM_OF_Q = 63;

class QType
{
public:
	QType() : visited(0), question() {}
	QType(string theQ) : visited(0), question(theQ) {}
	QType(bool wasVisited, string theQ) : visited(wasVisited), question(theQ) {}
	string getQuestion() const { return question; }
	bool getVisited() const { return visited; }
	void setQuestion(string theQ) { question = theQ; }
	void setVisited(bool wasVisited) { visited = wasVisited; }
	~QType() {};

private:
	bool visited;
	string question;

};

class DArray
{
	
public:
	//initializes array to NUM_OF_Q
		DArray();

	//Inserts new element in the array
		void addQuestion(string newQ);

		int getNumOfElem() const;
		int getNumPrinted() const;

	//Returns number of elements in the array
		//int getNumOfElem() const;

	//Prints questions 
		void printRandomQ();

	//Adds questions to array
		void createDArray(const string& fileName);

	//Destructor
		~DArray();


private:
	QType *a;
	int capacity;
	int numOfElem;
//Keeps track of number of questions printed
	int numPrinted;
};

#endif