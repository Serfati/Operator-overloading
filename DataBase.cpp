#include "Employee.h"
#include "DataBase.h"

using namespace std;


DataBase::DataBase() { // default constructor
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

	if( dynamic_cast <Employee*>(theEmployee) && getEmployee(theEmployee->getId()) == NULL ){ //if it does not exist already, add the employee
		if (numOfemployees < arrLen) { //looks if the list is full or not
			list[numOfemployees] = theEmployee; //adds the employee to the list
			numOfemployees++; //increments the list
			return true;
		}
		else {// array is full
			arrLen = arrLen * 2;            // Double the previous size.
			Employee** temp = new Employee*[arrLen]; // Allocate new, bigger array.
			if(temp == NULL) return false;
			for (int i = 0; i< numOfemployees; i++)
				temp[i] = list[i];       // Copy old array to new array.
			delete list;          		 // Free old array memory.
			list = temp;                 // Now a points to new array.
			list[numOfemployees] = theEmployee; //adds the employee to the list
			numOfemployees++; //increments the list
			return true;
		}
	}
	else{
		cout<<"This employee is already in the database\n"<<endl;
		delete theEmployee;
	}
	return false;
}

bool DataBase::removeEmployee(int idToRemove){
	Employee* E = getEmployee(idToRemove);
	if(E != NULL ){ //if it exist, delete it, looks if the list is empty or not
		for(int i = 0; i < arrLen; i++){
			if(list[i]->getId() == E->getId()){
				list[i]->~Employee();
				delete list[i];
				for(int j = i; j < arrLen-1; j++)
					list[j] = list[j+1]; //shifts the elements
				numOfemployees--; //decrements the list
				return true;
			}
		}
	}
	cout<<"The employee isn't in the database\n"<<endl;
	return false;
}

Employee* DataBase::getEmployee(int employeeID){
	for(int i = 0; i < numOfemployees; i++){
		if(strcmp(list[i]->getName(), "Name") != 0)
			if(list[i]->getId() == employeeID )
				return list[i];
	}
	return NULL;
}

void DataBase::print() const{
	if(numOfemployees > 0){
		cout<<"Employees database:\n"<<endl;
		for(int i = 0; i < numOfemployees;  i++)
			if(strcmp(list[i]->getName(), "Name") != 0)
				list[i]->print();
	}
	else
		cout<<"Cannot print the list of employees because it is empty."<<endl;

}

int DataBase::getNumEmployee(){ //gets the number of employee in the database company
	return numOfemployees;
}

int DataBase::getArrayLength(){ //returns the size
	return arrLen;
}

DataBase::~DataBase() {
	// destructor stub
	for(int i = 0; i < arrLen; i++){
		list[i]->~Employee();
		delete list[i];
	}

	delete list;
}
