run: main.o DataBase.o Employee.o
	g++ main.o DataBase.o Employee.o -o run

main.o: main.cpp Employee.h DataBase.h
	g++ -c main.cpp

DataBase.o: DataBase.cpp DataBase.h Employee.h
	g++ -c DataBase.cpp

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp

clean:
	rm -f main.o DataBase.o Employee.o run
