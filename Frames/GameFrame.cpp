//
// Created by RainMaker on 2020-09-11.
//

#include "GameFrame.h"

GameFrame::GameFrame(QWidget *frame): QMainWindow() {
    setGeometry(0, 0, maximumWidth(), maximumHeight());
    this->frame = frame;
}

void GameFrame::closeEvent(QCloseEvent *event) {
    frame->show();
    this->close();
}