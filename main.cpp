#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Employee.h"
#include "S_Employee.h"
#include "H_Employee.h"

using namespace std;

int main()
{
    fstream fin_s; //file handler class(fstream) var decleration (object of fstream)
    fin_s.open("salaried.txt", ios::in);
    string input;
    int s_count = 0;
    S_Employee S_arr[30]; //this will call the default S_Emp(); constructor 
        if(fin_s.fail() ) 
        {
            cout << "The file cannot be open" << endl;
            exit(1);
        }
    
                                   //  param1  ,  param2
    while(getline(fin_s, input))  // (istream& ,  input)
    {
        if(input != "") { 
                                                // Must be same Type
           S_arr[s_count] = S_Employee(input); // explicit call: member-wise copy  a < --- b (b into a)
           s_count++;
        }
    }
    fin_s.close();

//Display S_Employee
    for(int i =0; i < s_count; i++) {
        S_arr[i].display(cout);
    }


    fstream fin_h;
    
    // string input;
    fin_h.open("hourly.txt", ios::in);
    int h_count = 0;
    H_Employee H_arr[23];
    if(fin_h.fail() ) 
        {
            cout << "The file cannot be open" << endl;
            exit(1);
        }
    while(getline(fin_h, input)) 
    {
        if(input != "") { 
           H_arr[h_count] = H_Employee(input); // member-wise copy
           h_count++;
        }
    }
    // Employee::getEmpSize();
    fin_h.close();

//Display H_Employee's
    for(int i = 0; i < h_count; i ++)
    {
        H_arr[i].display(cout); // cout:: standard library. A f(n) call
    }

    cout << "Number of Employees: " << Employee::getEmpSize() << endl; // :: scope resolution operator 

    return 0;
}

