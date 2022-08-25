/************************************************************************************************************************

Name:  Brandon Denardo       Z#: Z23596879
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  03/30/22           Due Time: 11:59 PM
Total Points: 10
Assignment #: amazon_porders8.cpp

Description:Implement a program to manage a dynamic array of purchase order records.
This program will process monthy statistics for a sensor equipment company.
Will read the data stored in a data file into a static array of statistic
records, then process each statistic record in the array, and
finally print the array of statistics records to a datafile.

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
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


void initialize(order_record*& INV, int& count, int& size);
bool is_Empty(int count);
bool is_full(int count, int size);
int search(order_record* INV, int count, string key);
void add(order_record*& INV, int& count, int& size);
void remove(order_record* INV, int& count, string key);
void double_size(order_record*& INV, int count, int& size);
void process(order_record* INV, int count);
void print(const order_record* INV, const int count);
void destroy_INV(order_record*& INV, int& count, int& size);
//The function will read the data from the file “purchase_data.txt”
//into the dynamic array INV.If INV becomes full, the function should call
//the function “double_Size” to double the size(capacity) of INV
void initialize(order_record*& INV, int& count, int& size)
{
    ifstream in;
    in.open("purchase_data8.txt");
    while (!in.eof())
    {
        if (count < size) {
            in >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity >> INV[count].price >> INV[count].processing_plant;
            count++;
        }
        else {
            double_size(INV, count, size);
            in >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity >> INV[count].price >> INV[count].processing_plant;
            count++;
        }
    }
    in.close();
}

//Boolean function If count == 0 then true is returned; otherwise false is
//returned.
bool is_Empty(int count)
{
    return count == 0;
}

//Boolean function  If count
//== size then true is return; otherwise false.The size is
//the capacity which is the total number of cells allocated to INV
bool is_full(int count, int size)
{
    return count == size;
}


//The function will return the location of key in INV if it is there; otherwise - 1 is returned
int search(order_record* INV, int count, string key)
{
    for (int i = 0; i < count; i++) {
        if (INV[i].cell_number == key) {
            return i;
        }
    }
    return -1;
}

//Adds inputs into dynamic array
void add(order_record*& INV, int& count, int& size)
{

    if (count < size) {
        cout << "Enter cell number: ";
        cin >> INV[count].cell_number;
        cout << "Enter item number: ";
        cin >> INV[count].item_number;
        cout << "Enter item quantity: ";
        cin >> INV[count].quantity;
        cout << "Enter item price: ";
        cin >> INV[count].price;
        cout << "Enter processing plant: ";
        cin >> INV[count].processing_plant;
        count++;
    }
    else {
        double_size(INV, count, size);
        cout << "Enter cell number: ";
        cin >> INV[count].cell_number;
        cout << "Enter item number: ";
        cin >> INV[count].item_number;
        cout << "Enter item quantity: ";
        cin >> INV[count].quantity;
        cout << "Enter item price: ";
        cin >> INV[count].price;
        cout << "Enter processing plant: ";
        cin >> INV[count].processing_plant;
        count++;
    }
    process(INV, count);
}


//deletes all records with the cell number that matched key stored in INV
void remove(order_record* INV, int& count, string key)
{

    for (int i = 0; i < count; i++) {
        if (INV[i].cell_number == key) {
            for (int h = i; h < count - 1; h++) {
                INV[h] = INV[h + 1];
            }
            count--;
        }
    }
}


//doubles the capacity of INV
void double_size(order_record*& INV, int count, int& size)
{

    order_record* temp = new order_record[2 * size];
    for (int i = 0; i < size; i++) {
        temp[i] = INV[i];
    }
    size = 2 * size;
    delete[] INV;
    INV = new order_record[size];
    for (int h = 0; h < count; h++) {
        INV[h] = temp[h];
    }
}

// ThIS function will calculate
void process(order_record* INV, int count)
{

    for (int i = 0; i < count; i++) {
        if (INV[i].processing_plant >= 0 && INV[i].processing_plant <= 50) {
            INV[i].tax_rate = .06;
        }
        else if (INV[i].processing_plant >= 51 && INV[i].processing_plant <= 110) {
            INV[i].tax_rate = .07;
        }
        else if (INV[i].processing_plant >= 111 && INV[i].processing_plant <= 200) {
            INV[i].tax_rate = .08;
        }
        else if (INV[i].processing_plant >= 201 && INV[i].processing_plant <= 500) {
            INV[i].tax_rate = 9;
        }
        else {
            INV[i].tax_rate = .11;
        }
        INV[i].order_tax = INV[i].quantity * INV[i].price * (INV[i].tax_rate);
        INV[i].net_cost = INV[i].quantity * INV[i].price;
        INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
    }

}


// The function will print every field of
//every order_record in INV to the file “purchase8_results.txt”
void print(const order_record* INV, const int count)
{
    ofstream out;
    out.open("purchase8_results.txt");
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    for (int i = 0; i < count; i++) {
        out << INV[i].cell_number << "\t"
            << INV[i].item_number << "\t"
            << INV[i].quantity << "\t"
            << INV[i].price << "\t"
            << INV[i].processing_plant << "\t"
            << INV[i].tax_rate << "\t"
            << INV[i].order_tax << "\t"
            << INV[i].net_cost << "\t"
            << INV[i].total_cost << endl;
    }
    out.close();
}


void destroy_INV(order_record*& INV, int& count, int& size)
{

    delete[] INV;
    size = 0;
    count = 0;
    INV = 0;
}


int main()
{
    int count = 0; //intializating count
    int size = 5;
    order_record* INV = new order_record[size]; //declaring the dynamic array & allocate memory 

    cout << "**********************************************************************\n";
    //Test 1:
    ////void initialize(order_record * & INV, int & count, int & size);
    cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
    initialize(INV, count, size);
    process(INV, count);
    print(INV, count);
    cout << "End of Test 1" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 2:
    //void add(order_record * & INV, int & count, int & size);
    cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
    add(INV, count, size);
    print(INV, count);
    cout << "End of Test 2" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 3:
    //void remove(order_record * INV, int & count, string key);
    cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
    cout << "Removing 9546321555\n";
    remove(INV, count, "9546321555");
    print(INV, count);
    cout << "Removing 787716590\n";
    remove(INV, count, "7877176590");
    print(INV, count);
    cout << "Removing 3051234567\n";
    print(INV, count);
    cout << "Removing 9546321555 ---AGAIN--- SHOULD GET MESSAGE\n";
    print(INV, count);
    cout << "End of Test 3" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 4:
    //void destroy_INV(order_record * INV, int & count, int & size);
    cout << "Test 4: destroy_INV and print " << endl;
    destroy_INV(INV, count, size);
    cout << "size = " << size << endl;
    cout << " count = " << count << endl;
    print(INV, count);
    cout << "End of Test 4" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    return 0;
}