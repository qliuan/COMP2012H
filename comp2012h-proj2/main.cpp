//
//  main.cpp
//  proj.2
//
//  Created by LIU Qinhan on 10/6/16.
//  Copyright © 2016 LIU Qinhan Henry. All rights reserved.
//

#include "TetrixWindow.h"
#include <QtGui>

int main(int argv, char* args[]) {

    QApplication app(argv, args);
    TetrixWindow* window = new TetrixWindow();
    window->show();
    
    return app.exec();
}
