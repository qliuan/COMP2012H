#include "Point.h"
#include "PointPlotter.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;


int main (int argc, char *argv[])
{
    const char *INPUT_FILE  = argv[1];
    ifstream fin(INPUT_FILE);     // Read input file for input
    assert (fin.is_open ());      // Check file opening
    
    Points points;
    int MAX = 0;
    fin >> MAX;
    int count = 0;
    // reading points 
    while (!fin.eof () && count<MAX)  // Check the read file until the end of file
    {   
        int x,y;
        fin >> x;
        fin >> y;
        points.addPoint(x, y);
        if(fin.fail())         // fail to read a record
            break;
        count++;
    }
    fin.close ();

    // initialize the plot window 
    QApplication app(argc, argv);
    PointPlotter* pp = new PointPlotter(&points);
    pp->show();
    
    return app.exec();
}
