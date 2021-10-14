
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "H_Employee.h"
#include "Employee.h"

using namespace std;

H_Employee::H_Employee()
{
    // cout << "H_employee(): " << this << endl;
    hoursWorked = 0;
    payRate = 0;
};

H_Employee::H_Employee(const string &input) : Employee(input.substr(0, 70))
{

    istringstream ss(input.substr(72));
    string field;
    // string field2;
    int count = 0;
    ss >> field;
    hoursWorked = stoi(field);
    ss >> field;
    payRate = stof(field);
    //  cout << "H_employee(): " << this << endl;
}

H_Employee ::~H_Employee(){
    // cout << "~H_Employee(): " << this << "\n";
    
};
void H_Employee::setHoursWorked(int hw)
{
    hoursWorked = hw;
}
int H_Employee::getHoursWorked()
{
    return hoursWorked;
}

int H_Employee::getPayRate()
{
    return payRate;
}
void H_Employee::setPayRate(double pr)
{
    payRate = pr;
}
void H_Employee::display(ostream &out)
{
    Employee::display(out);
    out << right << setw(13) << hoursWorked << setw(13) << payRate << endl;
}
