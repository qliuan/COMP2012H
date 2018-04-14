//
//  TetrixWindow.cpp
//  proj.2
//
//  Created by LIU Qinhan on 10/6/16.
//  Copyright © 2016 LIU Qinhan Henry. All rights reserved.
//

#include "TetrixWindow.h"

TetrixWindow::TetrixWindow(QWidget *parent)
                        : QWidget(parent),score(0),level(1)
{
    myCore = new TetrixCore(this);
    DrawWindow();
    setWindowTitle("Tetrix Game");
    //resize(400,400);
    boardX = 0;
    boardY = 200;
    previewX = 250;
    previewY = 100;

	// initialise the timer to call SendShiftingInfo() repeatitively
    timer = new QTimer(this);
	timer->start(100);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(SendTimeInfo()));
}

TetrixWindow::~TetrixWindow()
{
	//delete myCore;
	//delete timer;	
}

void TetrixWindow::DrawWindow()
{
	// overlap the previous window
   
    scoreLabel.setNum(score);
    levelLabel.setNum(level);
    myLayout.addWidget(&scoreLabel,13,11);
    myLayout.addWidget(&levelLabel,15,11);
    backgroundImg.load("background.bmp");
    background.setPixmap(QPixmap::fromImage(backgroundImg));                           
	myLayout.addWidget(&background,0,0,20,10);	//  draw background
    previewImg.load("previewimg.png");
	preview.setPixmap(QPixmap::fromImage(previewImg)); 
    myLayout.addWidget(&preview,10,11);      		//  draw preview
	setLayout(&myLayout);
}

void TetrixWindow::UpdateScore(int score_incre)
{
    // update level every 100 scores
    if((score+score_incre)%100 > score%100)
        TetrixWindow::UpdateLevel();
    score += score_incre;
    scoreLabel.setNum(score);
}

void TetrixWindow::UpdateLevel()
{
    level++;
    levelLabel.setNum(level);
    // set a new falling time counter
    myCore->SetTimeInterval(level);
}

void TetrixWindow::UpdateWindow(const int previewBlocks[4][3], const int fallingBlocks[4][3],
                                const int staticBlocks[20][10],const int falling, const int shifting)
{
    DrawWindow();
    // draw preview blocks
    for(int c=0;c<4;c++)
    {
        penColor = SetPenColor(previewBlocks[c][0]);
        int blockY =(previewY - previewBlocks[c][1]*20)/10;
        int blockX =(previewX + previewBlocks[c][2]*20)/10;
        painter.fillRect(blockX,blockY,2,2,penColor);
    }
    // draw falling blocks
    for(int c=0;c<4;c++)
    {
        penColor = SetPenColor(fallingBlocks[c][0]);
        int blockY = boardY - (fallingBlocks[c][1]+shifting)*20;
        int blockX = boardX + (fallingBlocks[c][2]-falling )*20;
        painter.fillRect(blockX,blockY,20,20,penColor);
    }
    // draw static blocks
    for(int row=-19;row<1;row++){
        for(int col=-4;col<6;col++){
            if(staticBlocks[row+19][col+4]!=0){
                penColor = SetPenColor(staticBlocks[row+19][col+4]);
                int blockY = boardY - (row+19)*20;
                int blockX = boardX + (col+4)*20;
                painter.fillRect(blockX,blockY,20,20,penColor);
            }
        }
    }
}

QColor TetrixWindow::SetPenColor(int color)
{
    QColor penColor;
    switch (color) {
        case 1:
            penColor = QColor("red");
            return penColor;
        case 2:
            penColor = QColor("green");
            return penColor;
        case 3:
            penColor = QColor("blue");
            return penColor;
        case 4:
            penColor = QColor("yellow");
            return penColor;
        case 5:
            penColor = QColor("cyan");
            return penColor;
        case 6:
            penColor = QColor("orange");
            return penColor;
        default:
            penColor = QColor("purple");
            return penColor;
    }
}

void TetrixWindow::KeyEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Up)
		myCore->GameStart();
	if(event->key()==Qt::Key_Left)
		myCore->ShiftLeft();
	if(event->key()==Qt::Key_Right)
		myCore->ShiftRight();	
	if(event->key()==Qt::Key_Z)
		myCore->RotateClockwise();
	if(event->key()==Qt::Key_X)
		myCore->RotateAnticlockwise();
	if(event->key()==Qt::Key_Down)
		myCore->FallDown();
}

void TetrixWindow::SendTimeInfo()
{
	myCore->ShiftFallingBlocks();
}
