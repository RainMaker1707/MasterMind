//
// Created by RainMaker on 2020-09-11.
//

#include "GameFrame.h"

GameFrame::GameFrame(QWidget *frame): QMainWindow() {
    // setup frame
    setGeometry(0, 0, maximumWidth(), maximumHeight());
    setWindowTitle("MasterMind Game Board");
    this->frame = frame;

    // init layouts
    mainLayout = new QHBoxLayout;
    leftLayout = new QVBoxLayout;
    centerLayout = new QVBoxLayout;
    rightLayout = new QVBoxLayout;

    // init container
    container = new QWidget(this);
    container->setGeometry(0, 0, maximumWidth(), maximumHeight());

    // setup layouts & widgets
    container->setLayout(mainLayout);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(centerLayout);
    mainLayout->addLayout(rightLayout);
}

void GameFrame::closeEvent(QCloseEvent *event) {
    event->accept();
    frame->show();
    this->close();
}