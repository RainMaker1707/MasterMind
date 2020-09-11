//
// Created by RainMaker on 2020-09-11.
//

#include "MenuFrame.h"

MenuFrame::MenuFrame() : QWidget(){
    // init window
    setGeometry(0, 0, 600, 400);
    setWindowTitle("MasterMind");

    // init buttons & layouts
    startButton = new QPushButton("Start Game");
    quitButton = new QPushButton("Quit");
    loadGameButton = new QPushButton("Load Game");
    helpButton = new QPushButton("Help");
    parametersButton = new QPushButton("Parameters");
    mainLayout = new QVBoxLayout;
    buttonLayout = new QHBoxLayout;
    topLayout = new QHBoxLayout;
    rightTopLayout = new QVBoxLayout;

    // init image
    QImage img("img/board.png");
    QImage img2 = img.scaled(350, 350, Qt::KeepAspectRatio);
    QLabel *plotImg = new QLabel;
    plotImg->setScaledContents(true);
    plotImg->setPixmap(QPixmap::fromImage(img2));

    // setup and fill layouts
    setLayout(mainLayout);
    mainLayout->addLayout(topLayout);
    topLayout->addWidget(plotImg);
    topLayout->addLayout(rightTopLayout);
    rightTopLayout->addWidget(startButton);
    rightTopLayout->addWidget(loadGameButton);
    rightTopLayout->addWidget(helpButton);
    mainLayout->addLayout(buttonLayout);
    rightTopLayout->addWidget(parametersButton);
    rightTopLayout->addWidget(quitButton);

    setupCursors();
    makeConnection();
    FrameTools::centerFrame(this, width(), height());

    show();
}

void MenuFrame::makeConnection() {
    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startButtonClicked()));
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MenuFrame::startButtonClicked() {
    auto frame = new GameFrame(this);
    frame->show();
    this->close();
}

void MenuFrame::loadButtonClicked() {

}

void MenuFrame::helpButtonClicked() {

}

void MenuFrame::parametersButtonClicked() {

}

void MenuFrame::setupCursors() {
    startButton->setCursor(Qt::PointingHandCursor);
    loadGameButton->setCursor(Qt::PointingHandCursor);
    helpButton->setCursor(Qt::PointingHandCursor);
    parametersButton->setCursor(Qt::PointingHandCursor);
    quitButton->setCursor(Qt::PointingHandCursor);
}