# comp2012h-proj2
  comp2012h project 2 Tetrix Game 
  created at 02/10/2016 
  Code by 
    LIU Qinhan (qliuan@connect.ust.hk SID20328953) 
    BAI Jiaxin (jbai@connect.ust.hk   SID20327648)
  
  In this tetrix game project, we attempted to seperate the UI with the Logics, thus two classes were defined.
    
    * TetrixWindow class focuses on updating the whole window constantly and paint blocks according to the color and position information stored. All QT based operations are here.
    * TetrixCore class focuses on handling blocks manipulations and memorizing information of 3 different groups of blocks (previewBlocks, fallingBlocks and staticBlocks). Independent from QT. 
    * Inside both classes, several interfacing functions are designed.
    
  
  Here we do not want to expand it too much and we believe the whole structure is pretty straight forward and easy to go through following the comments of each file.
