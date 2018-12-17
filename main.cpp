//#include "Employee.h"
//#include "DataBase.h"
//
//#include <string.h>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	DataBase dataBase ;
//	Employee* yael = new Employee((char*)"Yael",11,6000);
//	Employee* barak = new Employee((char*)"Barak",10,11000);
//	Employee* avi = new Employee((char*)"avi serfati",204520803,2000);
//	Employee* lea = new Employee((char*)"Lea Kalimi ",203344106,1000);
////	Employee* lea3 = new Employee((char*)"Lea Kalimi ",203344106,1000);
////	Employee* lea1 = new Employee((char*)"Lea Kalimi ",203344106,1000);
//
//
//
//	cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;
//	cout<<"Cost party for yael: "<< yael->planOfficeParty() << "\n" <<endl;
//	(*barak)++++;
//	++++++(*yael);
//	//cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;
//	cout<<"Cost party for yael: "<< yael->planOfficeParty() << "\n" <<endl;
//	if(*barak>*yael)
//		cout<<"Barak's salary is higher than Yael's \n"<<endl;
//	double salaryBefore =((*yael)).getSalary();
//	cout<< "Salary before:"<< salaryBefore <<"\n"<<endl;
//	cout <<(*barak)<<endl;
//	*barak+*yael;
//	*barak += *yael;
//	cout<< "Salary of barakyael:"<<endl;
//	cout <<(*barak)<<endl;
//	if(*barak>*yael)
//		cout<<"Barak's salary is higher than Yael's \n"<<endl;
//
//	dataBase.addEmployee(yael);
//	dataBase.addEmployee(barak);
//	dataBase.addEmployee(barak);
//	dataBase.addEmployee(barak);
//	dataBase.addEmployee(avi);
//	dataBase.addEmployee(lea);
//	dataBase.print();
//	dataBase.removeEmployee(11);
//	dataBase.removeEmployee(10);
//	dataBase.removeEmployee(203344106);
//	cout <<"*******************REMOVE*******************"<<endl;
//	dataBase.print();
////	Employee *b = dataBase.getEmployee(204520803);
//	cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;
//	cout<<"Cost party for yael: "<< yael->planOfficeParty() << "\n" <<endl;
//
//	dataBase.~DataBase();
//
//
//	return 0;
//
//}
//

//-----------------------------------------------------------------
//-----------------------------------------------------------------
#include "DataBase.h"

int main() {

        DataBase dataBase;
//        dataBase.addEmployee(new Employee((char*)"Sharon",11,10000));
        dataBase.addEmployee(new Employee((char*)"Yael",11,20000));
        dataBase.addEmployee(new Employee((char*)"Yael",1,20000));
        dataBase.addEmployee(new Employee((char*)"Barak",10,11000));
        dataBase.addEmployee(new Employee((char*)"avi serfati",204520803,2000));
        dataBase.addEmployee(new Employee((char*)"Leah Kalimi ",203344106,1000));
        dataBase.print();
        dataBase.removeEmployee(1);
        dataBase.removeEmployee(11);
        dataBase.print();

        Employee *yael = dataBase.getEmployee(12);
        Employee *barak = dataBase.getEmployee(10);



        cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;

        if(*barak>*yael)
        {
                cout<<"Barak's salary is higher than Yael's \n"<<endl;
        }

        cout<<++(*barak)<<endl;
        double salaryBefore =((*barak)++).getSalary();
        cout<< "Salary before:"<< salaryBefore <<"\n"<<endl;
        cout <<(*barak)<<endl;

        dataBase.print();
        if(*barak>*yael)
        {
                cout<<"Barak's salary is higher than Yael's \n"<<endl;
        }

        return 0;

}

