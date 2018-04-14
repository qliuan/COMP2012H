//
//  TetrixCore.cpp
//  proj.2
//
//  Created by LIU Qinhan on 10/6/16.
//  Copyright © 2016 LIU Qinhan Henry. All rights reserved.
//

#include "TetrixCore.h"
#include "TetrixWindow.h"
#include <time.h>
using namespace std;

TetrixCore::TetrixCore(TetrixWindow* w)
: myWindow(w),timeInter(10),timeCount(0),falling(2),shifting(0),isStarted(FALSE)
{
    PreviewGenerate();
    UpdateWindow();                         
}

TetrixCore::~TetrixCore(){}

void TetrixCore::PreviewGenerate()     //  DONE
{
    const static int shapes[7][4][3] =
    {
        { {1,0,0}, {1,-1,0}, {1,-1,-1}, {1,-1,-1} },
        { {2,0,0}, {2,0,1},  {2,1,0},   {2,1,-1}  },
        { {3,0,0}, {3,1,0},  {3,1,1},   {3,0,-1}  },
        { {4,0,0}, {4,0,1},  {4,0,-1},  {4,1,-1}  },
        { {5,0,0}, {5,0,1},  {5,0,-1},  {5,-1,-1} },
        { {6,0,0}, {6,-1,0}, {6,0,1},   {6,1,0}   },
        { {7,0,0}, {7,0,2},  {7,0,1},   {7,0,-1}  }
    };
    
    srand(time(NULL));
    int random = rand() % 7;
    copy(&shapes[random][0][0],&shapes[random][4][3],&previewBlocks[0][0]);
}

void TetrixCore::GameStart()
{
	if(!isStarted)
		isStarted = TRUE;
		copy(&previewBlocks[0][0],&previewBlocks[4][3],&fallingBlocks[0][0]);
        PreviewGenerate();
        UpdateWindow();                         
}

bool TetrixCore::IsEnded()                           
{
    // check the topest two rows 0 & -1 of staticBlocks
    for(int row=-1;row<1;row++){
        for(int col=-4;col<6;col++){
            if(staticBlocks[row+19][col+4]!=0)
				isStarted = FALSE;
                return TRUE;
        }
    }
    return FALSE;
}

bool TetrixCore::IsStarted()
{
    return isStarted;
}

bool TetrixCore::HitsBlocks(int temp[4][3])          
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<10;j++)
        {
			int row = temp[i][2]-falling+19;
            int nextRow = (temp[i][2]-falling+19)-1;
            if(	( (temp[i][1] == staticBlocks[nextRow][j])
               &&   (staticBlocks[nextRow][j]>0) )  // there is a static block under temporate blocks
			 || ( (temp[i][1] == staticBlocks[row][j])
               &&   (staticBlocks[row][j]>0) )		// there is an overlaped block
			  )
                return TRUE;
        }
    }
    return FALSE;
}

bool TetrixCore::HitsBoundry(int temp[4][3])        
{
    if( ((temp[0][1]+shifting)>-4) && ((temp[1][1]+shifting)>-4) &&
       ((temp[2][1]+shifting)>-4) && ((temp[3][1]+shifting)>-4) && // left  boundry
       
       ((temp[0][1]+shifting)<5)  && ((temp[1][1]+shifting)<5)  &&
       ((temp[2][1]+shifting)<5)  && ((temp[3][1]+shifting)<5)     // right boundry 
       ){ return FALSE;}
    else{ return TRUE; }
}

void TetrixCore::ShiftLeft()
{
    if(isStarted && !IsEnded() && !HitsBoundry(fallingBlocks))
    {
	    shifting--;    
		UpdateWindow();
	}
}
    
void TetrixCore::ShiftRight()
{
    if(isStarted && !IsEnded() && !HitsBoundry(fallingBlocks))
    {
	    shifting++;
		UpdateWindow();
	}
}
    
void TetrixCore::RotateClockwise()
{
    if(isStarted && !IsEnded())
    {
        int temp[4][3];
        // rotates clockwisely, Xt=Y, Yt=-X
        for(int c=0;c<4;c++){
            temp[c][1] = fallingBlocks[c][2];
            temp[c][2] = -fallingBlocks[c][1];
        }
        if(!HitsBlocks(temp) && !HitsBoundry(temp))
        {
            copy(&temp[0][0],&temp[4][3],&fallingBlocks[0][0]);
            UpdateWindow();              
        }
    }
}

void TetrixCore::RotateAnticlockwise()
{
    if(isStarted && !IsEnded())
    {
        int temp[4][3];
        // rotates anti-clockwisely, Xt=-Y, Yt=X
        for(int c=0;c<4;c++){
            temp[c][1] = -fallingBlocks[c][2];
            temp[c][2] = fallingBlocks[c][1];
        }
        if(!HitsBlocks(temp) && !HitsBoundry(temp))
        {
            copy(&temp[0][0],&temp[4][3],&fallingBlocks[0][0]);
            UpdateWindow();             
        }
    }
}
    
void TetrixCore::FallDown()
{
    if(isStarted && !IsEnded())
    {
        ShiftFallingBlocks();
        UpdateWindow();                
    }
}

void TetrixCore::ShiftFallingBlocks()     // every time event (0.1s) calls this function
{
    timeCount++;
    timeCount %= timeInter;
    if(timeCount == 0){					// every 0.1s*timeInter enters
        if(!HitsBlocks(fallingBlocks)){
            falling++;     // shift down the falling blocks
            UpdateWindow();                                        
        }
        else
        {
            RemoveFullRows();
            if(!IsEnded()){
                copy(&previewBlocks[0][0],&previewBlocks[4][3],&fallingBlocks[0][0]);
                falling = 2;
                PreviewGenerate();
                UpdateWindow();  
            }
        }
    }
}

void TetrixCore::RemoveFullRows()
{
    // record all fallingBlocks in staticBlocks
    for(int i=0;i<4;i++){
        int row = fallingBlocks[i][2]-falling;
        int col = fallingBlocks[i][1];
        staticBlocks[row+19][col+4] = fallingBlocks[i][0];
    }
    // count blocks each row
    int eachRow[20] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 };
    for(int row=-19;row<1;row++){
        for(int col=-4;col<6;col++){
            if(staticBlocks[row+19][col+4]!=0)
                eachRow[row+19]++;
        }
    }
    // remove full rows
    int combo = 0;
    for(int i=0;i<20;i++){
        if(eachRow[i]==10){
            combo++;
            int row = i-19-(combo-1);   // finds the shifted full row
            // shift down unfull rows
            for(;row<0;row++){
                for(int col=-4;col<6;col++){
                    staticBlocks[row+19][col+4]=staticBlocks[row+20][col];
                }
            }
        }
    }
    // update score and level
    int score_incre = 10*combo*combo;
    myWindow->UpdateScore(score_incre);
}

void TetrixCore::SetTimeInterval(int level)
{
    timeInter = 11 - level; // every timeInter * 0.1s fallingBlocks shift down 1 unit
}

void TetrixCore::UpdateWindow()
{
	if(!IsEnded() && IsStarted())
	    myWindow->UpdateWindow	(previewBlocks,fallingBlocks,staticBlocks,falling,shifting);
}
