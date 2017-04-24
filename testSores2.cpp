/*
	Chad Fry ITSE 2421  | Prof. Welch
	4/18/2017
	Chapter 10, Program 1.  -- Test Scores Array
	Notes: written using sublime! (my first time programming on linux!)
	Lessons Learned: VS reaaaaly spoiled us. but, sublime does quite a lot for us, too!
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function prototypes

struct student
{
	public:

	string firstName;

	double testScore;

};



void clearScreen();

void sortScores(student* ary, int size);
void displayAry(student* ary, int size, ofstream& fout); //takes in a double-pointer, and size.
double calcAverage(student* ary, int size);
void fillArray(student* ary, int size);

//begin main********************************************************************
int main()
{
	ofstream fout;   //creating a filestream object for output, called fout.
	fout.open("results.txt"); //output will go to results.txt

	int size;
	student* aryPtr; //creating a pointer (to students!) called aryPtr.


	clearScreen();


	cout << "How many test-scores would you like to enter? :";

	cin >> size;

	if(size < 0) //size input-validation. make sure user is aware.
	{
		size = 0;

		cout << endl << endl << "an invalid size was entered, so the size has been set to 0 instead." << endl;
		cout << "Program Closing..." << endl;
	}


	aryPtr = new student[size]; //create a new array of [size] many students.
	// do note thsat aryPtr is now pointing at this ary!	







	fillArray(aryPtr, size);
	sortScores(aryPtr,    size); //sorts the scores
	displayAry(aryPtr, size, fout); //displays the array, and also writes same output to file
	

fout.close();
}

//function Definitions ***************************************************
void fillArray(student* ary, int size)
{

	for (int i = 0; i < size; i++) // populate the array.
	{
		cout << "Enter Student " << (i+1) << "'s First Name: ";
		cin >> (ary + i)->firstName;

		cout << "Enter " << (ary + i)->firstName << "'s Test Score: ";
		cin >> (ary + i)->testScore; //the + i is incredibly importante!

		if( (ary + i)->testScore < 0)
		{
			cout << "An invalid number was entered for this test-score, so it has been set to 0 instead." << endl;
			(ary + i)->testScore = 0;

		}
	}

}



	


void displayAry(student* ary, int size, ofstream& fout)
{
	//this first half outputs to teminal.

	clearScreen(); 	

	cout << "Test Scores: " << endl;
	cout << "===================" << endl;
  	cout << "  Name  |  Grade  " << endl << endl;
	cout << endl << endl;
 	for(int i = 0; i < size; i++)
	{

		cout << setw(8) << (ary + i)->firstName << "  ";
		cout << setw(8) << (ary + i)->testScore << endl;
	}

	cout << endl << endl << "Average Score: " << calcAverage(ary, size) << endl;
	//******************* this half prints the same output, but to a file.

	fout << endl << endl;
	fout << "Test Scores: " << endl;
	fout << "===================" << endl;
	fout << "Student Name  |  Grade  " << endl << endl;

	for(int i = 0; i < size; i++)
	{
		fout << setw(8) << (ary + i)->firstName << "  " << setw(8) << (ary + i)->testScore << endl;
	}

	fout << endl << endl << "Average Score: " << calcAverage(ary, size) << endl;

}

double calcAverage(student* ary, int size)
{
	double average = 0;
	double sum = 0;
	double numOfElements = 0;


	for(int i = 0; i < size; i++)
	{
		sum += (ary + i)->testScore; 
		numOfElements++;
	}


	average = (sum/numOfElements);
	return average;
}

void sortScores(student* ary, int size)
{
	student temp;
	bool madeSwap;
	do
	{
		madeSwap = false;

		for(int count = 0; count < (size - 1); count++)
		{

			if(  ( (ary + count)->testScore )  >   (  (ary + count +1 )->testScore )  )
			{

				//still doing this crud because I forgot how to swap
				//using pointers... :/  I'm dumb.
				temp = *(ary + count);
				*(ary + count) = *(ary + count + 1 );
				*(ary + count +1 ) = temp;
				madeSwap = true;
			}
		}
	} while (madeSwap); //loop again if a swap occured...
}

void clearScreen()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
}