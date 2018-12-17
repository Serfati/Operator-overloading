
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string.h>
#include <iostream>


using namespace std;

const int startingSalary = 0;


class Employee {
private:
	char* name;
	double salary;
	int   id;

public:
	static int empCounter ;
	Employee();//Default Constructor

	Employee ( const char* , int , double );//Constructor
	Employee ( const Employee&);//Copy Constructor
	int planOfficeParty();
	void print() const;  //prints the employee

	// GETTERS AND SETTERS
	bool setName( const char* );
	const char* getName() const; //gets his name
	void setId( int );
	int getId() const; //gets his employee id
	void setSalary( double );
	double getSalary() const;
	void promote( double raiseAmount);

	//OPERATORS
	Employee operator+ ( const Employee& e) ;
	Employee& operator++();
	Employee operator++( int);
	friend  bool operator>( const Employee& l, const Employee& r);
	inline bool operator==( const Employee& e)const ;
	Employee& operator+=( const Employee& e);
	Employee& operator=( const Employee& e);
	friend ostream& operator<<( ostream& out, const Employee& e);

	virtual ~Employee();//Destructor
};
#endif /* EMPLOYEE_H_ */
