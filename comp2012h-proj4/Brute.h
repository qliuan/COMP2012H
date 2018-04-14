#include "Point.h"
#include <vector>

#ifndef BRUTE_H
#define BRUTE_H
class Brute
{
private:
	vector<Point*> *ps;
	int MAX;
	vector< vector<int> > line; // n*4 Stores all 4 points for each line segment 
	vector<int> lineSegment;
	int count;
public:
	Brute(Points*);
	bool isColinear(int,int,int,int);
	void checkLine();
	void printLine();
	vector< vector<int> > returnLine();
};

#endif /* BRUTE_H */
