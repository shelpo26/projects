#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "order_class.h" //interface of the order_class class

order_class::order_class()
{
	ifstream in;
	in.open("purchase_data_Assignment11.txt");
	count = 0;
	size = 10;
	INV = new order_record[size];

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			order_record rec;
			in >> rec.cell_number;
			in >> rec.item_number;
			in >> rec.quantity;
			in >> rec.price;
			in >> rec.processing_plant;
			if (is_full())
			{
				double_size();
			}
			INV[count] = rec;
			count++;
		}	cout << "The default constructor has been called\n";
	}
	in.close();
}

/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: waits for program to run before making copy
//Postcondition: once program runs will make a copy of the order record
//Decription: performs a deep copy.
/************************************************************************************************************************************/
order_class::order_class(const order_class& org)
{
	size = org.size;
	count = org.count;
	INV = new order_record[size];
	for (int i = 0; i < count; i++) {
		INV[i] = org.INV[i];
	}
}

/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition: count is not = to 0
//Postcondition: if class is empty the value will be equal to 0
//Decription: returns true if INV is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: : function is here in case of class being filled 
//Postcondition: will double the size of memory being used through double size function
//Decription: returns true if INV is full
/*********************************************************************************************************************************/
bool order_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: function is here to search through the string input 
//Postcondition: once user has entered a string function will run through and see if input matches with the data
//Decription: locates key in INV if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
{
	for (int i = 0; i < count; ++i)
	{
		if (INV[i].cell_number == key)
			return i;
	}
	return -1;

}

/*********************************************************************************************************************************/
//Name: add
//Precondition: function is here in case of extra memory being needed
//Postcondition: : if size reaches maximum amount then will go to double size function and then contuinue user input process
//Decription: adds a call_record to INV; if INV is full, double_size is called to increase the size of INV. The user 
//            is prompted to enter the cell number, item, quantity, price, and processing plant.
/********************************************************************************************************************************/
void order_class::add()
{
	if (is_full()) // if array is full, double its size
	{
		double_size();
	}

	// input the plant name, county name, plant cost and quantity at the end of STR
	cout << "Enter cell_number: ";
	cin >> INV[count].cell_number;
	cout << "Enter item_number: ";
	cin >> INV[count].item_number;
	cout << "Enter quantity: ";
	cin >> INV[count].quantity;
	cout << "Enter price: ";
	cin >> INV[count].price;
	cout << "Enter processing plant: ";
	cin >> INV[count].processing_plant;
	count++;
	process(); // call process to calculate the other fields for all the records
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: function awaits for size to be filled
//Postcondition: once sized is filled will perform this function to increase memory slots
//Decription: doubles the size (capacity) of INV
/******************************************************************************************************************************/
void order_class::double_size()
{
	size *= 2;
	order_record* temp = new order_record[size];

	for (int i = 0; i < count; i++)
	{
		temp[i] = INV[i];
	}

	delete[] INV;
	INV = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: function is here to process the mathmatical calculations of our parameters set
//Postcondition: function will apply values and do calculations based upon each of the purchase_data.txt information 
//Decription: calculate the tax rate, order tax, net cost, total order cost for every call record in INV.
/*****************************************************************************************************************************/
void order_class::process()
{
	for (int i = 0; i < count; ++i)
	{
		int processing = INV[i].processing_plant;
		if (processing <= 50) INV[i].tax_rate = 6;
		else if (processing <= 110) INV[i].tax_rate = 7;
		else if (processing <= 200) INV[i].tax_rate = 8;
		else if (processing <= 500) INV[i].tax_rate = 9;
		else INV[i].tax_rate = 10;
		INV[i].order_tax = INV[i].quantity * INV[i].price * INV[i].tax_rate / 100.0;
		INV[i].net_cost = INV[i].quantity * INV[i].price;
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: waits for proggram to run, will be there to de-allocate memory
//Postcondition: will de-allocate memory allocated to the STR
//Decription: de-allocates all memory allocated to INV.  This will be the last function to be called (automatically by the compiler)
//Decription: de-allocates all memory allocated to INV.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	cout << "The destructor has been called\n";
	delete[]INV;
	size = 0;
	count = 0;
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: checks to see if memory has been overloaded
//Operator "-" has been overloaded.
//Decription: removes all order records in INV with a cell number field that matches key, if it is there. Chain was
//            implemented.
/*******************************************************************************************************************************/
order_class& order_class::operator-(const string key) //removes an item from the list
{
	int i = search(key); // get the first index of key in STR
	if (i == -1) // key not found
		cout << "No record with key : " << key << " exists" << endl;
	else
	{
		while (i != -1)
		{
			for (int h = i; h < count - 1; h++)
				INV[j] = INV[j + 1];
			count--; // decrement the count
			i = search(key); // search for key
		}
	}
	return *this; // return the updated object
}

/****************************************************************************************************************************/
//Name: operator<<
//Precondition: waits for program to run and makes sure that file will outputted in correcet format
//Postcondition: will print the outputs of the call records in STR in the format we have provided
//Decription: prints every field of every call_record in INV formatted to the screen.
/***************************************************************************************************************************/
ostream& operator<<(ostream& out, order_class& Org) //prints all the elements in INV to the screen
{
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	static int run = 1;
	for (int i = 0; i < Org.count; i++)
	{
		out << left << setw(20) << Org.INV[i].cell_number
			<< left << setw(10) << Org.INV[i].item_number
			<< right << setw(10) << Org.INV[i].quantity
			<< right << setw(10) << Org.INV[i].price
			<< right << setw(10) << Org.INV[i].processing_plant
			<< right << setw(10) << (Org.INV[i].tax_rate / 100)
			<< right << setw(10) << Org.INV[i].order_tax
			<< right << setw(10) << Org.INV[i].net_cost
			<< right << setw(10) << Org.INV[i].total_cost << endl;
	}
	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;
	return out;//returning object that invoked the function
}