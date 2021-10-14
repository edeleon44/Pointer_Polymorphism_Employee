#include "Employee.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// init. a static var in scope of Var. ->  outside of object with instance.
int Employee::size = 0;

Employee::Employee()
{
                // cout << "Employee(): " << this << endl;    
    size++; // if in parent, don't put in drive class
}; //constructor
Employee::Employee(const string& input){

//     cout << "Employee(const string& input): " << this << endl; // & of the object that call the function or OBJ
    istringstream ss(input); 

    string field;
    int count = 0;
    while(ss >> field) 
    {
        switch(count) {
        case 0: 
                setCode(field);
                break;
        case 1: 
                setSSN(field);
                break;
        case 2: 
                setFirst(field);
                break;
        case 3: 
                setLast(field);
                break;
        case 4: 
                setDept(field);
                break;
        case 5:
                setRole(field);
                break;
        }
        count++;
    } size++;
}; //constructor
Employee:: ~Employee(){
        //     cout << "S_Epl(): " << this << endl;
        
            size--;
};

void   Employee::setCode(string code) {
        this->code = code;
}
string Employee::getCode() const 
{
        return code;
}
void   Employee::setSSN(string ssn)
{
        this->ssn = ssn;
}
string Employee::getSSN() const
{
        return ssn;
}

void   Employee::setFirst(string first)
{
        this->first = first;
}

string Employee::getFirst()const
{
        return first;
}

string Employee::getLast() const
{
        return last;
}
void   Employee::setLast(string last)
{
        this->last = last;
}
string Employee::getDept() const
{
        return department;
}
void   Employee::setDept(string department)
{
        this->department = department;
}
string Employee::getRole() const{
        return role;
}
void   Employee::setRole(string role)
{
        this->role = role;
}
void   Employee::display(ostream& out){
        out << left << setw(6) << code << setw(15) << ssn
                << setw(10) << last << setw(15) << first << setw(17) 
                << department << setw(24) << role;
}
int Employee::getEmpSize(){
    return size;
}

