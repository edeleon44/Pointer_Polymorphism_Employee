#ifndef  EMPLOYEE_H
#define  EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string code;
    string ssn;
    string first;
    string last;
    string department;
    string role;
    // static int size;

protected:
   // void parse(int, string);
    static int size; // static member variable classname::getEmpSize()

public: 
    Employee(); //constructor
    Employee(const string&); //constructor
    virtual ~Employee();
    string getCode() const;
    void   setCode(string);
    string getSSN() const;
    void   setSSN(string);
    string getFirst()const;
    void   setFirst(string);
    string getLast() const;
    void   setLast(string);
    string getDept() const;
    void   setDept(string);
    string getRole() const;
    void   setRole(string);
    virtual void   display(ostream&);
    static int getEmpSize(); // we need a getter for employee class to allow main to access static var
    
};
#endif

