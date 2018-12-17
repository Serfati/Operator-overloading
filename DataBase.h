#ifndef DATABASE_H
#define DATABASE_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Employee.h"

using namespace std;

extern int num_of_emp;

class DataBase {
private:
	int numOfemployees;//number of Employees DB
	Employee **list; //array of employee list
	int arrLen; //size of list

public:
	DataBase();//default constructor
	DataBase ( const DataBase&  );//copy constructor

	bool addEmployee ( Employee*);//function to insert an employee into database
	void print()const; //prints the employee list
	bool removeEmployee(int); //function to delete an employee into database

	Employee* getEmployee (int);//gets the info of an employee by their id
	int getNumEmployee(); //gets the number of Employees in list
	int getArrayLength(); //gets the actual size of the list

	~DataBase();//destructor
};

#endif /* DATABASE_H_ */
