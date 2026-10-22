studentData: main.o address.o date.o student.o
	g++ main.o address.o date.o student.o -o studentData

main.o: main.cpp address.h date.h student.h
	g++ -c main.cpp

address.o: address.cpp address.h
	g++ -c address.cpp

date.o: date.cpp date.h
	g++ -c date.cpp

student.o: student.cpp student.h address.h date.h
	g++ -c student.cpp

run: studentData
	./studentData

debug:
	g++ -g main.cpp address.cpp date.cpp student.cpp -o studentData
	
clean: 
	rm -f *.o studentData

valgrind: studentData
	valgrind ./studentData

