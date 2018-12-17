#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
#include "Employee.h"

int empCounter = 0;


Employee::Employee() {
	this->name = new char[5];
	strcpy(this->name,"Name");
	salary = 0;
	id = 0;
}

Employee::Employee (const char* name, int id , double salary ){

	if(!name)return;
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
	this->salary=salary;
	this->id=id;
}

Employee::Employee (const Employee& emp){
	id = emp.id;
	salary = emp.salary;
	this->name = new char[strlen(emp.name)+1];
	strcpy(this->name,emp.name);
}

int Employee::planOfficeParty(){
	return ::empCounter * 10;
}

void Employee::print() const
{
	cout << "name:" << name << "\n" << "ID:" << id
			<< "\n" << "Salary:" << salary << "\n" << endl;
}

//GETTERS AND SETTERS

bool Employee::setName( const char* nName){
	if (!nName)
		return false;
	char* temp;
	temp = new char[strlen(nName) + 1];
	if (!temp)
		return false;
	delete  name;
	strcpy(temp, nName);
	this->name = temp;

	return true;
}

const char* Employee::getName() const {
	return name;
}

void Employee::setSalary(double newSalary) {
	salary = newSalary;
}

double Employee::getSalary() const {
	return salary;
}

void Employee::setId(int nId){
	id = nId;
}

int Employee::getId() const {
	return id;
}

void Employee::promote(double raiseAmount = 100){
	setSalary(getSalary() + raiseAmount);
}

Employee::~Employee() {
	if(name != NULL)
		delete [] name;
}

Employee Employee::operator+ (const Employee& e) {
	double d = e.salary;
	this->promote(d);
	return *this;
}
Employee& Employee::operator++(){
	this->promote();
	return *this;
}
Employee Employee::operator++(int){
	Employee tmp (*this);
	++(*this);
	return tmp;
}

Employee& Employee::operator+=(const Employee& e){
	strcat(name, e.name);
	return *this;
}

Employee& Employee::operator=(const Employee& e){
	this->id = e.id;
	this->salary = e.salary;
	setName(e.name);
	return *this;
}

ostream& operator<<(ostream& out, const Employee& e) { e.print(); return out;};
bool operator>(const Employee& l, const Employee& r){return l.salary > r.salary;};
bool Employee::operator==(const Employee& e) {return (id == e.id);};
