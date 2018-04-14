all: ran_main
ran_main: ran_main.o
	g++ -o ran_main ran_main.o
ran_main.o: ran_main.cpp randomized_queue.h
	g++ -c ran_main.cpp
clean:	
	rm *.o