//
// Created by RainMaker on 2020-09-11.
//

#include "MenuFrame.h"

MenuFrame::MenuFrame() : QWidget(){
    // init window
    setGeometry(0, 0, 550, 400);
    setWindowTitle("MasterMind");

    // init buttons & layouts
    startButton = new QPushButton("New Game");
    quitButton = new QPushButton("Quit");
    loadGameButton = new QPushButton("Load Game");
    helpButton = new QPushButton("Help");
    parametersButton = new QPushButton("Parameters");
    difficultiesButton = new QPushButton("Difficulties");
    mainLayout = new QVBoxLayout;
    topLayout = new QHBoxLayout;
    rightTopLayout = new QVBoxLayout;

    // setup and fill layouts
    setLayout(mainLayout);
    mainLayout->addLayout(topLayout);
    topLayout->addWidget(FrameTools::imageParser("img/board.png", 0.63*width(), 0.875*height()));
    topLayout->addLayout(rightTopLayout);
    rightTopLayout->addWidget(startButton);
    rightTopLayout->addWidget(loadGameButton);
    rightTopLayout->addWidget(difficultiesButton);
    rightTopLayout->addWidget(parametersButton);
    rightTopLayout->addWidget(helpButton);
    rightTopLayout->addWidget(quitButton);

    setupCursors();
    makeConnection();
    FrameTools::centerFrame(this, width(), height());
}

void MenuFrame::makeConnection() {
    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startButtonClicked()));
    QObject::connect(loadGameButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()));
    QObject::connect(difficultiesButton, SIGNAL(clicked()), this, SLOT(difficultiesButtonClicked()));
    QObject::connect(parametersButton, SIGNAL(clicked()), this, SLOT(parametersButtonClicked()));
    QObject::connect(helpButton, SIGNAL(clicked()), this, SLOT(helpButtonClicked()));
    QObject::connect(quitButton, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));
}

void MenuFrame::startButtonClicked() {
    auto frame = new GameFrame(this);
    frame->show();
    this->close();
}


void MenuFrame::setupCursors() {
    startButton->setCursor(Qt::PointingHandCursor);
    loadGameButton->setCursor(Qt::PointingHandCursor);
    difficultiesButton->setCursor(Qt::PointingHandCursor);
    parametersButton->setCursor(Qt::PointingHandCursor);
    helpButton->setCursor(Qt::PointingHandCursor);
    quitButton->setCursor(Qt::PointingHandCursor);
}

void MenuFrame::loadButtonClicked() {
    // TODO
    std::cout << "load\n";
}

void MenuFrame::difficultiesButtonClicked() {
    // TODO
    std::cout << "difficulties\n";
}

void MenuFrame::helpButtonClicked() {
    // TODO
    std::cout << "help\n";
}

void MenuFrame::parametersButtonClicked() {
    // TODO
    std::cout << "parameters\n";
}
