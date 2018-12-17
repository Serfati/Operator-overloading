#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include "DataBase.h"


DataBase::DataBase() { // default constructor
	empCounter=0;
	numOfemployees = 0;
	arrLen = 3;
	list = new Employee*[arrLen]; // data is an array need to build array with size 3
	if(list == NULL) return;

}

DataBase::DataBase ( const DataBase& DB ){//copy another database
	//copy everything
	list = new Employee*[DB.arrLen];
	if(list == NULL) return;
	this->numOfemployees = DB.numOfemployees;
	this->arrLen = DB.arrLen;

	for(int i = 0; i < DB.arrLen; i++)
		list[i] = DB.list[i]; //copies all the employees inside the other list

}

bool DataBase::addEmployee(Employee *theEmployee){
	Employee** temp;
	if( !getEmployee(theEmployee->getId())){ //if it does not exist already, add the employee
		if (numOfemployees < arrLen) { //looks if the list is full or not
			list[numOfemployees] = theEmployee; //adds the employee to the list
			numOfemployees++; //increments the list
			empCounter++;
			return true;
		}
		else {// array is full
			arrLen = arrLen * 2;            // Double the previous size.
			temp = new Employee*[arrLen]; // Allocate new, bigger array.
			if(temp == NULL) return false;
			for (int i = 0; i< numOfemployees; i++)
				temp[i] = list[i];       // Copy old array to new array.
			delete list;          		 // Free old array memory.
			list = temp;                 // Now a points to new array.
			list[numOfemployees] = theEmployee; //adds the employee to the list
			numOfemployees++; //increments the list
			empCounter++;
			return true;
		}
	}
	else //This employee is already in the database\n";
		delete theEmployee;
	return false;
}


bool DataBase::removeEmployee(int idToRemove){
	Employee* E = getEmployee(idToRemove);
	if(E != NULL ){ //if it exist, delete it, looks if the list is empty or not
		for(int i = 0; i < numOfemployees; i++){
			if(list[i]->getId() == idToRemove){
				delete list[i];
				for( i = 0; i < numOfemployees-1; i++)
					list[i] = list[i+1]; //shifts the elements
				numOfemployees--; //decrements the list
				empCounter--;
				return true;
			}
		}
	}
	cout<<"The employee isn't in the database\n"<<endl;
	return false;
}

Employee* DataBase::getEmployee(int employeeID){
	for (int i = 0; i < this->numOfemployees;i++)
	{
		if (list[i]->getId() == employeeID)
			return this->list[i];
	}
	return NULL;
}

void DataBase::print() const{
	if(numOfemployees > 0){
		cout<<"Employees database:\n"<<endl;
		for(int i = 0; i < numOfemployees;  i++)
			list[i]->print();
	}

}

int DataBase::getNumEmployee(){ //gets the number of employee in the database company
	return numOfemployees;
}

int DataBase::getArrayLength(){ //returns the size
	return arrLen;
}

DataBase::~DataBase() {
	// destructor stub
	for(int i = 0; i < arrLen; i++)
		delete list[i];
	delete list;
}
