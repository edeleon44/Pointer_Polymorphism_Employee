#include <iostream>
#include <sstream>
#include <iomanip>
#include "S_Employee.h"
#include "Employee.h"

using namespace std;

S_Employee::S_Employee() {
        // cout << "S_Epl(): " << this << endl;
        // size++;
        salary = 0;
}
                                                                  //start //number of chars to extract
                                                                  // Explicit call of param construc. otherwise it will call DEF.
                                                                  // : = "Delegation"
S_Employee::S_Employee(const string& input) : Employee(input.substr(0,72))
{
    istringstream ss(input.substr(72));
    string field;
    ss >> field;
    salary = stof(field); //setSalary(stof(field)); Auxillary Object
    
};

S_Employee::~S_Employee() {
    // cout << "~S_Employee(): " << this << endl;
}

void S_Employee::setSalary(double field) 
{
    this->salary = field;

}

double S_Employee::getSalary() const {
     return salary;
}



void S_Employee:: display(ostream& out)
{
   Employee::display(out);
   out << right << setw(13) << salary <<  endl;
}
