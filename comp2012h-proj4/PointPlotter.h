#ifndef PointPlotter_h
#define PointPlotter_h

#include "Point.h"
#include "Brute.h"
#include "Fast.h"
#include <vector>
#include <time.h>
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QString>

class PointPlotter : public QMainWindow
{
    Q_OBJECT // for slots
private:
    Points *points;
	vector<Point*> *ps;
	int MAX;
	double pixel;
	double w;	// unit width
	double h;	// unit height
	int r; 		// radius of points
	QMenu *menu;
	QAction *brute;
	QAction *fast;
	vector< vector<int> > bruteLine;	// N * 4 
	int bruteCount;
	vector< vector<int> > fastLine;	// N * n
	int fastCount;
private slots:
	void bruteMethod();
	void fastMethod();
public:
    PointPlotter(Points*);
	void paintEvent(QPaintEvent*);
	int setX(int);
	int setY(int);
};


#endif /* PointPlotter_h */
