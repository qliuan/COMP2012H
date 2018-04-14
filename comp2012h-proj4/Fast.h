#include "Point.h"
#include <vector>
#include <algorithm>

#ifndef FAST_H
#define FAST_H

class Fast
{
private:
	int MAX;
	vector< vector<int> > lines; // n * k  Stores all k points for each line segment 
	int count;
	vector<int> index;
	vector<int> lineSegment;
public:
	Fast(Points*);
	void checkLine();
	bool dupSegment();
	void printLine();
	vector< vector<int> > returnLine();
};


#endif /* FAST_H */
