#include "Point.h"

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
    Point* p = new Point{x,y};
    points.push_back(p);
}

vector<Point*>* Points::returnPoints()
{
	return &points;
}
