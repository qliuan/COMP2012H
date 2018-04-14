//
//  TetrixWindow.h
//  proj.2
//
//  Created by LIU Qinhan on 10/6/16.
//  Copyright © 2016 LIU Qinhan Henry. All rights reserved.
//

#include "TetrixCore.h"
#include <QWidget>
#include <QtGui>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

#ifndef TetrixWindow_h
#define TetrixWindow_h

class TetrixWindow : public QWidget
{
	Q_OBJECT	// for slots
private:
    TetrixCore* myCore;
    QLabel scoreLabel;
    QLabel levelLabel;
    int score;
    int level;
    QGridLayout myLayout;
    QPainter painter;
    QImage backgroundImg;
	QLabel background;
    QImage previewImg;
	QLabel preview;
    QColor penColor;
    int boardX;
    int boardY;
    int previewX;
    int previewY;
    QTimer* timer;

public:
    TetrixWindow(QWidget *parent=0);
    ~TetrixWindow();
	void DrawWindow();
    void UpdateScore(int score_incre);
    void UpdateLevel();
    void UpdateWindow(const int previewBlocks[4][3], const int fallingBlocks[4][3],
                      const int staticBlocks[20][10],const int falling, const int shifting);
    QColor SetPenColor(int color);
	void KeyEvent(QKeyEvent* event);
public slots:
    void SendTimeInfo();	 
};

#endif /* TetrixWindow_h */
