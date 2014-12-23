All: main
main: main.cpp my_vector.o
	g++ -o main main.cpp my_vector.o
my_vector.o: my_vector.cpp
	g++ -c my_vector.cpp
c:
	rm  my_vector.o my_vector.h.gch main
