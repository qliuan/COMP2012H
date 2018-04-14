#include "PointPlotter.h"
#include <iostream>
using namespace std;

PointPlotter::PointPlotter(Points *p) : points(p),
	pixel(32767),w(0.0),h(0.0),r(5),bruteCount(0),fastCount(0)
{
	ps = points->returnPoints();
	MAX = ps->size();
	
	// set up the window
    setWindowTitle("Pattern");
	resize(800,800);

	brute = new QAction(tr("Brute"),this);
	fast = new QAction(tr("Fast"),this);
	connect(brute, SIGNAL(triggered()), this, SLOT(bruteMethod()));
	connect(fast, SIGNAL(triggered()), this, SLOT(fastMethod()));

	menu = menuBar()->addMenu(tr("Algorithm"));
	menu->addAction(brute);
	menu->addAction(fast);
}


void PointPlotter::paintEvent(QPaintEvent *e)
{
	QPainter *painter = new QPainter(this);
	// set up the unit width and unit height
	w = double(width())/pixel;
	h = double(height())/pixel;

	// plot all points
	painter->setPen(Qt::blue);
	
	for(int i=0;i<MAX;i++)
	{
		int x = setX((*ps)[i]->x);
		int y = setY((*ps)[i]->y);
		painter->drawEllipse(x-r,y-r,r,r);
	}
	
	// draw bruteLine properly
	if(bruteCount!=0)
	{
		for(int i=0;i<bruteCount;i++)
		{
			int a = bruteLine[i][0];
			int b = bruteLine[i][1];
			int c = bruteLine[i][2];
			int d = bruteLine[i][3];	

			painter->drawLine(setX((*ps)[a]->x),setY((*ps)[a]->y),setX((*ps)[b]->x),setY((*ps)[b]->y));
			painter->drawLine(setX((*ps)[a]->x),setY((*ps)[a]->y),setX((*ps)[c]->x),setY((*ps)[c]->y));
			painter->drawLine(setX((*ps)[a]->x),setY((*ps)[a]->y),setX((*ps)[d]->x),setY((*ps)[d]->y));
		}
	}

	if(fastCount!=0)
	{
		for(int i=0;i<fastCount;i++)
		{
			// find two endpoints a & b of each line segment
			int a = fastLine[i][0];
			int b = fastLine[i][fastLine[i].size()-1];
			painter->drawLine(setX((*ps)[a]->x),setY((*ps)[a]->y),setX((*ps)[b]->x),setY((*ps)[b]->y));
		}
	}
}

void PointPlotter::bruteMethod()
{
	clock_t t; 
	t = clock(); // initiate a clock;

	Brute b(points);
	
	t = clock() - t; // count the time

	QString time = QString("Running brute algorithm takes %1 sec").arg(float(t)/CLOCKS_PER_SEC); 
	QMessageBox prompt;
	prompt.information(this,tr("Brute Running Time"),time);
	cout << "\n\nRunning brute algorithm takes " << float(t)/CLOCKS_PER_SEC << " seconds." << "\n\n";

	b.printLine();
	bruteLine = b.returnLine();
	bruteCount = bruteLine.size();
	repaint();
}

void PointPlotter::fastMethod()
{
	clock_t t; 
	t = clock(); // initiate a clock;

	Fast f(points);
	
	t = clock() - t; // count the time

	QString time = QString("Running fast algorithm takes %1 sec").arg(float(t)/CLOCKS_PER_SEC); 
	QMessageBox prompt;
	prompt.information(this,tr("Fast Running Time"),time);
	cout << "\n\nRunning fast algorithm takes " << float(t)/CLOCKS_PER_SEC << " seconds." << "\n\n";

	f.printLine();
	fastLine = f.returnLine();
	fastCount = fastLine.size();
	repaint();
}

int PointPlotter::setX(int x)
{
	return x*w;
}

int PointPlotter::setY(int y)
{
	return h*(pixel-y);
}
