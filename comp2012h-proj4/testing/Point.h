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
    void printPoints();
};

Point* Point::ref = NULL; // reference point for comparision

bool Point::operator<(Point *p)
{
    //*
    if((p->x-ref->x)*(x-ref->x)>0)
    {
        if( (y-ref->y)*(p->x-ref->x) <
            (p->y-ref->y)*(x-ref->x) )
            return true;
        else
            return false;   
    }
    else if((p->x-ref->x)*(x-ref->x)<0)
    {
        if( (y-ref->y)*(p->x-ref->x) >
            (p->y-ref->y)*(x-ref->x) )
            return true;
        else
            return false;
    }
    else // (p->x-ref->x)*(x-ref->x)==0
    {
        if(p->x-ref->x==0 && x-ref->x!=0)
            return true;
        else
            return false;
    }
}

bool Point::operator==(Point *p)
{
    if( (y-ref->y)*(p->x-ref->x) ==
        (p->y-ref->y)*(x-ref->x) )
        return true;
    else
        return false;   
}

Points::Points(){}

void Points::addPoint(int x,int y)
{
    Point* p = new Point;
    p->x=x;
    p->y=y;
    points.push_back(p);
}

void Points::printPoints()
{
     cout << "Input size: " << points.size() << endl;
     //for(int i=0;i<size;i++)
     //cout << "point[" << i << "]\t" << points[i]->x << "\t" << points[i]->y << endl;
}

vector<Point*>* Points::returnPoints()
{
    return &points;
}


#endif /* Point_h */
