all: palindrome
palindrome: palindrome.o
	g++ -o palindrome palindrome.o
palindrome.o: palindrome.cpp deque.h
	g++ -c palindrome.cpp
clean:
	rm *.o