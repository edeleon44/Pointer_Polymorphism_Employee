#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Employee.h"
#include "S_Employee.h"
#include "H_Employee.h"

using namespace std;
/* 
Application of Pointer and Polymorphism ln.33 
1. base class pointer -> to an obj of the child class
Employee* p[33];
2. new _&h/s employee__
3. P[I] -> DISPLAY() (Call of child display)
*/

int main()
{
    fstream fin_s; // Filehandler: datatype of fstream
    fin_s.open("salaried.txt", ios::in); // read file
   
        if(fin_s.fail() ) 
        {
            cout << "The file cannot be open" << endl;
            exit(1);
        }
    string input;
    
    int count = 0;
    int s_count = 0;
    Employee* p[35];
   // S_Employee* S_arr [30];
    while(getline(fin_s, input)) 
    {
        if(input != " ") { 
        p[count] = new S_Employee(input);
        //    S_arr[s_count] = new S_Employee(input); // explicit call: member-wise copy
           // s_count++;
          count++; 
        }
    }
    fin_s.close(); //File Handler

    // display before pointer polymorph. Emplloyee pointer -> Salary obj
    // for(int i =0; i < s_count; i++) {
    //     //S_arr[s_count]->display(cout);
    //     // s_count++;
    // }
    fstream fin_h;
    
    // string input;
    // int h_count = 0;
    //H_Employee* H_arr[30];
    fin_h.open("hourly.txt", ios::in);
    if(fin_h.fail() ) 
        {
            cout << "The file cannot be open" << endl;
            exit(1);
        }
    while(getline(fin_h, input)) 
    {
        if(input != " ") { 
           p[count] = new H_Employee(input);
           count++;
           //H_arr[h_count] = new H_Employee(input); // member-wise copy
           //h_count++;
        }
    }
    
    fin_h.close();

    // display before pointer polymorph. Emplloyee pointer -> Hourly obj
    // for(int i = 0; i < h_count; i ++)
    // {
    //     //H_arr[i]->display(cout);
    //     // h_count++;
    // }

// Now we call Employee type pointer diplay -> but child overrides because of public inheritance , virtual function (display) , and polymorphism
    for(int i = 0; i < count; i++)
        p[i]->display(cout);

        cout << "Number of Employees: " << Employee::getEmpSize() << endl; // :: scope resolution operator 
        
    for(int i=0; i< count; i++) 
    {
        delete p[i];    // When we delete an object --> we inherite Base class destructor using public inheritance & polym.
    }
    // Echo Test sizeof Employee, S_emp.. , H_emp..
    // cout << "Employe SIZEOF: " <<  sizeof(Employee) << endl;
    // cout << "S_E SIZEOF: " << sizeof(S_Employee) << endl;
    // cout << "H_W SIZEOF: " << sizeof(H_Employee) << endl;

    return 0;
}

