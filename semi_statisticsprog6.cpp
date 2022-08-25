/************************************************************************************************************************

Name:Brandon Denardo                              Z#:Z23596879
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  3/16/22                    Due Time:11:59PM
Total Points: 20
Assignment #: semi_statistics.cpp

Description:  This program will process monthy statistics for a sensor equipment company.
Will read the data stored in a data file into a static array of statistic
records, then process each statistic record in the array, and
finally print the array of statistics records to a datafile.

*************************************************************************************************************************/

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//Struct s_record
class stat_record
{
public:
	double item_1;
	double item_2;
	double item_3;
	double item_4;
	double item_5;
	double item_6;
	double row_average;
};

const int SIZE = 50;

//Function prototypes
void input(stat_record STR[SIZE], int& count);

void process(stat_record STR[SIZE], int count);

void output(stat_record STR[SIZE], int count);

void calculate_totals(stat_record STR[SIZE], int count);



//Function Definitions
void input(stat_record STR[SIZE], int& count)
{
	ifstream in;
	in.open("monthly_stats.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}

	else
	{

		while (!in.eof())
		{
			in >> STR[count].item_1;
			in >> STR[count].item_2;
			in >> STR[count].item_3;
			in >> STR[count].item_4;
			in >> STR[count].item_5;
			in >> STR[count].item_6;
			count++;
		}
	}

	in.close();
}


void process(stat_record STR[SIZE], int count)
{

	//row avg
	for (int i = 0; i < count; i++)
	{
		STR[i].row_average = (STR[i].item_1 + STR[i].item_2 + STR[i].item_3 + STR[i].item_4 + STR[i].item_5 + STR[i].item_6 / 6);
	}

}

void output(stat_record STR[SIZE], int count)
{
	ofstream out;
	//open file
	out.open("statistical_results.txt", ios::app);
	//magic formula
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);


	//print every field into the file
	for (int i = 0; i < count; i++)
	{
		out << STR[i].item_1 << setw(10) << right;
		out << STR[i].item_2 << setw(10) << right;
		out << STR[i].item_3 << setw(10) << right;
		out << STR[i].item_4 << setw(10) << right;
		out << STR[i].item_5 << setw(10) << right;
		out << STR[i].item_6 << setw(10) << right;
		out << STR[i].row_average << setw(10) << right;
		out << endl;
	}

	//close file
	out.close();
}

void calculate_totals(stat_record STR[SIZE], int count)
{


	double totals[7] = { 0,0,0,0,0,0,0 };

	for (int i = 0; i < count; i++)
	{
		totals[0] += STR[i].item_1;
		totals[1] += STR[i].item_2;
		totals[2] += STR[i].item_3;
		totals[3] += STR[i].item_4;
		totals[4] += STR[i].item_5;
		totals[5] += STR[i].item_6;
		totals[6] += STR[i].row_average;
	}

	//open file
	ofstream out;
	out.open("statistical_results.txt", ios::app);

	//magic formula
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	out << right << setw(10) << totals[0];
	out << right << setw(10) << totals[1];
	out << right << setw(10) << totals[2];
	out << right << setw(10) << totals[3];
	out << right << setw(10) << totals[4];
	out << right << setw(10) << totals[5];
	out << right << setw(10) << totals[6];
	out << endl;



}


int main()
{

	stat_record STR[SIZE];
	int count;

	input(STR, count);
	process(STR, count);
	output(STR, count);
	calculate_totals(STR, count);

	return 0;
}