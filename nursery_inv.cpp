/****SAMPLE PROGRAM HEADER*******************************************************
Name:               Brandon Denardo
Z-Number:           Z23596879
Total Points:	    10
Due Date:           1/26/2022
Course:             C0P3014
Assignment:         Assignment 1
Professor:          Dr. Lofton Bullard

Description: In this program we will calculate the tax, net cost, discount, and total cost on a purchase.
			 It will also take the purchase details and print them on the screen.

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <iomanip> //library that contain stream manipulators
using namespace std;


int main()
{
	//**********MAGIC FORMULA	WILL EXPLAIN************************** 
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//*************************************************************** 
	//declare and comment your user variable here
	string user_name;
	//declare and comment your user variables here
	string user_variables;
	string pname;	//string that holds the plant name string pname;	
	string cname;     //string that holds the county name
	double plant_cost; //double that hold the cost of a plant;
	int quantity; //int that hold the number of plants purchased;
	double purchase_tax = 0;
	double tax_rate = 0;
	double net_cost = 0;
	double discount_rate = 0;
	double discount = 0;
	double total_cost = 0;
	string user_response = "y";

	while (user_response == "y" || user_response == "Y")
	{
		//The code to get the user's input if given in the following
		//Input Statements
		cout << "Enter the Plant Name: ";
		cin >> pname;
		cout << "Enter the County Name: ";
		cin >> cname;
		//Logic ...if else statements for tax rate
		if (cname == "dade")
		{
			tax_rate = .055;
		}
		else if (cname == "broward")
		{
			tax_rate = .05;
		}
		else if (cname == "palm")
		{
			tax_rate = .06;
		}
		else
		{
			cout << "Error - Improper County Name\n" << endl;
			exit(1);
		}
		cout << "Enter the Plant Cost: ";
		cin >> plant_cost;
		cout << "Enter the Quantity: ";
		cin >> quantity;


		//Calculation for net cost
		net_cost = quantity * plant_cost;

		//Logic ...if else statements for discount rate
		if (quantity <= 0)
		{
			discount_rate = 0;
		}
		else if (quantity >= 1 && quantity <= 6)
		{
			discount_rate = .02;
		}
		else if (quantity >= 7 && quantity <= 13)
		{
			discount_rate = .04;
		}
		else if (quantity >= 14 && quantity <= 25)
		{
			discount_rate = .07;
		}
		else if (quantity >= 26 && quantity <= 60)
		{
			discount_rate = .09;
		}
		else
		{
			discount_rate = .14;
		}

		//Calculations for purchase tax and total cost
		purchase_tax = (net_cost * tax_rate) / 100;
		discount = net_cost * discount_rate;
		total_cost = (net_cost + purchase_tax) - discount;

		//Print Results to screen here
		cout << endl << endl;
		//print Plant Name
		cout << "The plant name is: " << pname;
		//print County Name
		cout << "\nThe county name is : " << cname;
		//print Plant Cost
		cout << "\nThe plant cost is: " << plant_cost;
		//print Quantity 
		cout << "\nThe quantity is: " << quantity;
		//print Tax Rate
		cout << "\nThe tax rate is: " << tax_rate;
		//print Net Cost 
		cout << "\nThe net cost is: " << net_cost;
		//print Discount Rate
		cout << "\nThe discount rate is: " << discount_rate;
		//print Discount 
		cout << "\nThe discount is: " << discount;
		//print Purchase Tax
		cout << "\nThe purchase tax is: " << purchase_tax;
		//print Total Cost
		cout << "\nThe total cost is: " << total_cost;

		cout << "\nWould you like to do another calculation (Y or N): ";
		cin >> user_response;
		if (user_response == "n" || user_response == "N")
		{
			cout << "\nThank you for using the program. Goodbye!\n";
		}
	}

	return	0;
}