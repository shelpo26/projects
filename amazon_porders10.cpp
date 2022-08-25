/************************************************************************************************************************

Name:  Brandon Denardo        Z#: Z23596879
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  04/20/22           Due Time: 11:59 PM
Total Points: 20
Assignment #: amazon_porders10.cpp

Description:
Manage a dynamic array of purchase order records while also implementing overload and destructor functions. Input data from a file,
prompt the user and output data to the screen and create an output file.
*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};



class order_class
{
public:
	order_class();
	~order_class(); //de-allocates all memory allocate to INV by operator new.
	bool is_Empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key);//returns location if item in INV; otherwise return -1
	void add(); //adds a order record to INV
	order_class& operator-(const string key); //removes all items in INV with a cell number that matches key.
	void double_size();
	void process();
	friend ostream& operator<<(ostream& out, order_class& Org); //prints all the elements in INV to the screen
private:
	int count;
	int size;
	order_record* INV;
};




/************************************************************************************************************************************/
//Name: default constructor
//Precondition: 
//Postcondition: 
//Decription: Reads the data file of purchase order information (cell number, item, quantity, price, and processing plant) into the dynamic array of order records, 
//INV. If the count become equal to the size the function double_size is called and the memory allocated to INV is doubled.
/************************************************************************************************************************************/
order_class::order_class()
{

	cout << "The default constructor has been called\n";
	size = 10;
	count = 0;
	INV = new order_record[size];
	ifstream in("purchase_data10.txt");
	if (!in) {
		cout << "File not found!!\n";
		exit(0);
	}
	while (!in.eof()) {
		if (count < size) {
			in >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity >> INV[count].price >> INV[count].processing_plant;
			count++;
		}
		else {
			double_size();
			in >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity >> INV[count].price >> INV[count].processing_plant;
			count++;
		}
	}
	in.close();
	process();

}

/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition: 
//Postcondition: 
//Decription: returns true if INV is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if INV is full
/*********************************************************************************************************************************/
bool order_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in INV if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
{

	for (int i = 0; i < count; i++) {
		if (INV[i].cell_number == key)
		{
			return i;
		}
	}
	return -1;

}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds a call_record to INV; if INV is full, double_size is called to increase the size of INV. The user 
//            is prompted to enter the cell number, item, quantity, price, and processing plant.
/********************************************************************************************************************************/
void order_class::add()
{
	if (count < size) {
		cout << "Enter cell phone number: ";
		cin >> INV[count].cell_number;
		cout << "Enter item number: ";
		cin >> INV[count].item_number;
		cout << "Enter quantity: ";
		cin >> INV[count].quantity;
		cout << "Enter price: ";
		cin >> INV[count].price;
		cout << "Enter processing plant: ";
		cin >> INV[count].processing_plant;
		count++;
	}
	else {
		double_size();
		cout << "Enter cell phone number: ";
		cin >> INV[count].cell_number;
		cout << "Enter item number: ";
		cin >> INV[count].item_number;
		cout << "Enter quantity: ";
		cin >> INV[count].quantity;
		cout << "Enter price: ";
		cin >> INV[count].price;
		cout << "Enter processing plant: ";
		cin >> INV[count].processing_plant;
		count++;
	}
	process();
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
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
//Precondition: 
//Postcondition: 
//Decription: calculate the tax rate, order tax, net cost, total order cost for every call record in INV.
/*****************************************************************************************************************************/
void order_class::process()
{
	for (int i = 0; i < count; i++) {
		if (INV[i].processing_plant <= 0 && INV[i].processing_plant <= 50)
		{
			INV[i].tax_rate = .06;
		}
		else if (INV[i].processing_plant <= 51 && INV[i].processing_plant <= 110)
		{
			INV[i].tax_rate = .07;
		}
		else if (INV[i].processing_plant <= 111 && INV[i].processing_plant <= 200)
		{
			INV[i].tax_rate = .08;
		}
		else if (INV[i].processing_plant <= 201 && INV[i].processing_plant <= 500)
		{
			INV[i].tax_rate = .09;
		}
		else {
			INV[i].tax_rate = .11;
		}
		INV[i].order_tax = INV[i].price * INV[i].quantity * (INV[i].tax_rate);
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to INV.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	// Deallocates memory of INV
	cout << "The destructor has been called\n";
	delete[] INV;

	size = 0;
	count = 0;
}

/********************************************************************************************************************************/
//Name: operator-
//Preconyonedition: 
//Postcondition: 
//Decription: removes all order records in INV with a cell number field that matches key, if it is there. Chain was
//            implemented.
/*******************************************************************************************************************************/
order_class& order_class::operator-(const string key) //removes an item from the list
{
	int i = search(key);
	if (i == -1)
	{
		cout <<" Key of " << key << "doesnt exist" << endl;
	}            // Sends message for the repeated cell number removed
	else {
		while (i != -1)
		{
			for (int h = i; h < count - 1; h++)
			{
				INV[h] = INV[h + 1];
			}
			count--;
			i = search(key);
		}
	}
	return *this;
}

/****************************************************************************************************************************/
//Name: operator<<
//Precondition: 
//Postcondition: 
//Decription: prints every field of every call_record in INV formatted to the screen.
/***************************************************************************************************************************/
ostream& operator<<(ostream& out, order_class& Org) //prints all the elements in INV to the screen
{
	static int run = 1;
	for (int i = 0; i < Org.count; i++)
	{
		out << left << setw(15) << Org.INV[i].cell_number << left << setw(10) << Org.INV[i].item_number << left << setw(10)
			<< Org.INV[i].quantity << left << setw(10) << Org.INV[i].price << left << setw(10) << Org.INV[i].processing_plant
			<< left << setw(10) << Org.INV[i].tax_rate << left << setw(10) << Org.INV[i].order_tax << left << setw(10)
			<< Org.INV[i].net_cost << left << setw(10) << Org.INV[i].total_cost << endl;
	}
	out << "********************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "********************\n";
	run++;
	return out;
}

//Here is your driver to test the program
int main()
{

	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and print " << endl;
	myOrders.process();
	cout << myOrders;
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	myOrders.add();
	cout << myOrders;
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	//void remove(string key);
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << "Removing 954632155, 7877176590, and 3051234567\n";
	myOrders - "9546321555" - "7877176590" - "3051234567";
	cout << myOrders;
	cout << "Removing 9546321555 ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders - "9546321555";
	cout << myOrders;
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 4:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 4: Destructor called" << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}