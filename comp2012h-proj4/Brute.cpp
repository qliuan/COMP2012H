#include "Brute.h"

Brute::Brute(Points* points) : count(0)
{
	ps = points->returnPoints();
	MAX = ps->size();
	checkLine();
}

bool Brute::isColinear(int i,int j,int k,int u)
{
	if( (((*ps)[j]->y-(*ps)[i]->y)*((*ps)[k]->x-(*ps)[i]->x) == 
		 ((*ps)[k]->y-(*ps)[i]->y)*((*ps)[j]->x-(*ps)[i]->x)) 
		&& 
	    (((*ps)[j]->y-(*ps)[u]->y)*((*ps)[k]->x-(*ps)[u]->x) == 
		 ((*ps)[k]->y-(*ps)[u]->y)*((*ps)[j]->x-(*ps)[u]->x)) 
	  )
	    return true;
	else 
		return false;
}

void Brute::checkLine()
{
	for(int i=0;i<MAX-3;i++)
		for(int j=i+1;j<MAX-2;j++)
			for(int k=j+1;k<MAX-1;k++)
				for(int u=k+1;u<MAX;u++)
					if(isColinear(i,j,k,u))
					{
						lineSegment.clear();
						lineSegment.push_back(i);
						lineSegment.push_back(j);
						lineSegment.push_back(k);
						lineSegment.push_back(u);
						line.push_back(lineSegment);
						count++;
					}
}

void Brute::printLine()
{
	cout << "Total number of 4-point line segments: " << count << endl;
	for(int i=0;i<count;i++)
	{
		int a = line[i][0];
		int b = line[i][1];
		int c = line[i][2];
		int d = line[i][3];
		cout << "4: (" << (*ps)[a]->x << ", " << (*ps)[a]->y << ") -> ";
		cout << "(" << (*ps)[b]->x << ", " << (*ps)[b]->y << ") -> ";
		cout << "(" << (*ps)[c]->x << ", " << (*ps)[c]->y << ") -> ";
		cout << "(" << (*ps)[d]->x << ", " << (*ps)[d]->y << ")" << endl;	 
	}
}

vector< vector<int> > Brute::returnLine()
{
	return line;
}

