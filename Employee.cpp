#include "Employee.h"
using namespace std;

int Employee::empCounter = 0;


Employee::Employee() {
	setName((char*)"Name");
	salary = startingSalary;
	id = 0;
}

Employee::Employee (const char* name, int id , double salary ){

	if(!name)return;
	setName(name);
	this->salary=salary;
	this->id=id;
	empCounter++;
}

Employee::Employee (const Employee& emp){
	id = emp.id;
	salary = emp.salary;
	setName(emp.name);
	empCounter++;
}

int Employee::planOfficeParty(){
	return empCounter*10;
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
	strcpy(temp, nName);
	delete [] nName;
    delete [] name;
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
	delete [] name;
	empCounter--;
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
inline bool Employee::operator==(const Employee& e)const {return (id == e.id);};
