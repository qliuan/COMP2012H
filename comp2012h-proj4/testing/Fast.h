#include "Point.h"
#include <vector>
#include <algorithm> 

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

vector<Point*> *PS;

bool compare(int i,int j)
{   
    if( (*(*PS)[i])<(*PS)[j] || (*(*PS)[i])==(*PS)[j] )
        return true;                
    else 
        return false;
}

bool compareX(int i,int j)
{
    if((*PS)[i]->x <= (*PS)[j]->x)
        return true;
    else
        return false;
}


Fast::Fast(Points *points) 
{
    PS = points->returnPoints();
    MAX = PS->size();
    checkLine();
}

void Fast::checkLine()
{
    for(int i=0;i<MAX;i++)
    {
        (*PS)[i]->ref = (*PS)[i]; // set up the reference for all point 
        // record indices for all other points in index 
        for(int j=0;j<i;j++)
            index.push_back(j);
        for(int j=i+1;j<MAX;j++)
            index.push_back(j);

        // sort all other points by their slope with respect to the reference
        sort(index.begin(),index.end(),compare);
        
        // count points on the same line
        count = 1;
        for(int j=1;j<index.size();j++)
        {
            int a = index[j-1];
            int b = index[j];     // this point
            if( (*(*PS)[b])==(*PS)[a] ) // has same slope as previous one 
                count++;
            else
            {
                if(count<3)
                    count = 1; // re-count
                else
                {
                    // record this line segment 
                    for(int k=0;k<count;k++)
                        lineSegment.push_back(index[j-count+k]);
                    // with the reference point
                    lineSegment.push_back(i);
                    // sort points on this line segment by the x value
                    sort(lineSegment.begin(),lineSegment.end(),compareX);
                    // compare this lineSegment with those stored in lines
                    if(!dupSegment())
                        lines.push_back(lineSegment);
                    // re-initialization
                    count = 1;
                    lineSegment.clear();
                }
            }
        }

        if(count>2)
        {
            // record this line segment 
            int lastIn = index.size()-1;
            for(int k=0;k<count;k++)
                lineSegment.push_back(index[lastIn-count+k]);
            // with the reference point
            lineSegment.push_back(i);
            // sort points on this line segment by the x value
            sort(lineSegment.begin(),lineSegment.end(),compareX);
            // compare this lineSegment with those stored in lines
            if(!dupSegment())
                lines.push_back(lineSegment);
        }

        index.clear(); // re-initialise for next loop  
    }
}

bool Fast::dupSegment()
{
    // check two endpoints of lineSegment with those ones inside lines
    int s1 = lineSegment[0];
    int s2 = lineSegment[lineSegment.size()-1];
    int l1,l2; 
    for(int l=0;l<lines.size();l++)
    {
        l1 = lines[l][0];
        l2 = lines[l][lines[l].size()-1];
        if(s1==l1 || s2==l2)
            return true;
    }
    return false;
}

void Fast::printLine()
{
    cout << "Total number of line segments: " << lines.size() << endl;
    for(int i=0;i<lines.size();i++)
    {
        vector<int> lineSegment = lines[i];  
        cout << lineSegment.size() << ": ";
        for(int j=0;j<lineSegment.size();j++)
        {
            int in = lineSegment[j];
            if(j!=lineSegment.size()-1) // not last line segment
                cout << "(" << (*PS)[in]->x << ", " << (*PS)[in]->y << ") -> ";
            else
                cout << "(" << (*PS)[in]->x << ", " << (*PS)[in]->y << ")" << endl;
        }
    }
}

vector< vector<int> > Fast::returnLine()
{
    return lines;	
}
