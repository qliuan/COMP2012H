//
//  TetrixCore.h
//  proj.2
//
//  Created by LIU Qinhan on 10/6/16.
//  Copyright © 2016 LIU Qinhan Henry. All rights reserved.
//

#ifndef TetrixCore_h
#define TetrixCore_h

class TetrixWindow;

class TetrixCore 
{
    
private:
    TetrixWindow* myWindow;
    int staticBlocks[20][10];
    int previewBlocks[4][3];
    int fallingBlocks[4][3];
    int timeCount;
    int timeInter;
    int falling;
    int shifting;
    bool isStarted;
    
public:
    TetrixCore(TetrixWindow* w);
    ~TetrixCore();
    void PreviewGenerate();
	void GameStart();
    bool IsEnded();
    bool IsStarted();
    bool HitsBlocks(int temp[4][3]);
    bool HitsBoundry(int temp[4][3]);
	void ShiftLeft();
	void ShiftRight();
	void RotateClockwise();
	void RotateAnticlockwise();
	void FallDown();
	void ShiftFallingBlocks();
    void RemoveFullRows();
    void SetTimeInterval(int level);
    void UpdateWindow();
};

#endif /* TetrixCore_h */
