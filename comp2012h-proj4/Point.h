#ifndef Point_h
#define Point_h

#include <vector>
#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
	static Point *ref;
	bool operator< (Point*);
	bool operator== (Point*);
};

class Points
{
private:
    vector<Point*> points;
public:
    Points();
    void addPoint(int,int);
    vector<Point*>* returnPoints();
};

#endif /* Point_h */
