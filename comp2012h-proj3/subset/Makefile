all: subset
subset: subset.o
	g++ -o subset subset.o
subset.o: subset.cpp randomized_queue.h
	g++ -c subset.cpp
clean:	
	rm *.o	



