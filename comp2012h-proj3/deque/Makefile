all: deq_main
deq_main: deq_main.o
	g++ -o deq_main deq_main.o
deq_main.o: deq_main.cpp deque.h
	g++ -c deq_main.cpp
clean:	
	rm *.o