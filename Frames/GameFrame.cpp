//
// Created by RainMaker on 2020-09-11.
//
#include "GameFrame.h"

GameFrame::GameFrame(QWidget *frame): QMainWindow() {
    this->frame = frame;
    setWindowTitle("MasterMind Game Board");
    gameMenu    = new QMenu;
    newGame     = new QAction;
    saveGame    = new QAction;
    loadMenu    = new QMenu;
    container   = new QWidget;
    mainLayoutV = new QVBoxLayout;
    mainLayoutH = new QHBoxLayout;
    leftGrid    = new QGridLayout;
    centralGrid = new QGridLayout;
    rightGrid   = new QGridLayout;
    userLayout  = new QHBoxLayout;
    userLayout1 = new QHBoxLayout;

    setupMenuBar();
    setupLoadMenu();
    setCentralWidget(container);
    setupLayout();
    setupGrid();
    setupUserChoice();
    makeConnection();
    setGeometry(0, 0, 280, 600);
    FrameTools::centerFrame(this, width(), height());
    QWidget *temp = centralGrid->itemAtPosition(0, 0)->widget();
}


void GameFrame::closeEvent(QCloseEvent *event) {
    event->accept();
    frame->show();
    menuBar()->clear();
    this->close();
}


void GameFrame::setupMenuBar() {
    menuBar()->setNativeMenuBar(true);
    gameMenu = menuBar()->addMenu("&Game");
    newGame  = gameMenu->addAction("&New Game");
    loadMenu = gameMenu->addMenu("&Load Game");
    saveGame = gameMenu->addAction("&Save Game");
    newGame->setShortcut(QKeySequence("Ctrl+N"));
    saveGame->setShortcut(QKeySequence("Ctrl+S"));
}


void GameFrame::setupLoadMenu() {
    // TODO display real saved game
    char buff[100];
    for(int i = 0; i < 5; i++) {
        snprintf(buff, sizeof(buff), "Game_%i", i+1);
        QString action;
        action.append(buff);
        action.append(QString(i));
        loadMenu->addAction(action);
    }
}


void GameFrame::setupLayout(){
    container->setMaximumWidth(350);
    container->setLayout(mainLayoutV);
    mainLayoutV->addLayout(mainLayoutH);
    mainLayoutH->addLayout(leftGrid);
    mainLayoutH->addLayout(centralGrid);
    mainLayoutH->addLayout(rightGrid);
    mainLayoutV->addLayout(userLayout);
    mainLayoutV->addLayout(userLayout1);
    leftGrid->setColumnMinimumWidth(0, 40);
    rightGrid->setColumnMinimumWidth(0, 40);
}


void GameFrame::setupGrid() {
    for (int  col=0; col<4; col++) centralGrid->setColumnMinimumWidth(col, 40);
    for (int row = 0; row < 12; row++){
        centralGrid->setRowMinimumHeight(row, 40);
        auto ansGrid  = new QGridLayout;
        auto ansWdg   = new QWidget;
        auto ansNoWdg = new QWidget;
        ansWdg->setStyleSheet("background-color: gray;");
        ansWdg->setLayout(ansGrid);
        for (int i=0; i<2; i++) {
            ansGrid->setRowMinimumHeight(i, 10);
            ansGrid->setMargin(5);
            for (int j=0; j<2; j++) {
                auto fourWdg = new QWidget;
                fourWdg->setStyleSheet("background-color: #4D4D4D;");
                fourWdg->setGeometry(0, 0, 20, 20);
                ansGrid->addWidget(fourWdg, i , j);
                ansGrid->setColumnMinimumWidth(j, 10);
            }
        }
        if (row%2 == 0){
            leftGrid->addWidget(ansWdg, row, 0);
            rightGrid->addWidget(ansNoWdg, row, 0);
        }
        else {
            rightGrid->addWidget(ansWdg, row, 0);
            leftGrid->addWidget(ansNoWdg, row, 0);
        }
        for (int column = 0; column < 4; column++) {
            auto wdg = new QWidget();
            wdg->setStyleSheet("background-color: lightsteelblue;");
            centralGrid->addWidget(wdg, row, column);
            auto cellLayout = new QHBoxLayout;
            wdg->setLayout(cellLayout);
        }

    }
}


void GameFrame::setupUserChoice() {
    auto redBall    = new QPushButton;
    auto yellowBall = new QPushButton;
    auto blackBall  = new QPushButton;
    auto whiteBall  = new QPushButton;
    auto blueBall   = new QPushButton;
    auto greenBall  = new QPushButton;
    userLayout->addWidget(redBall);
    userLayout->addWidget(yellowBall);
    userLayout->addWidget(blackBall);
    userLayout1->addWidget(whiteBall);
    userLayout1->addWidget(blueBall);
    userLayout1->addWidget(greenBall);

    redBall->setCursor(Qt::PointingHandCursor);
    yellowBall->setCursor(Qt::PointingHandCursor);
    blackBall->setCursor(Qt::PointingHandCursor);
    whiteBall->setCursor(Qt::PointingHandCursor);
    blueBall->setCursor(Qt::PointingHandCursor);
    greenBall->setCursor(Qt::PointingHandCursor);

    redBall->setFixedSize(70, 70);
    yellowBall->setFixedSize(70, 70);
    blackBall->setFixedSize(70, 70);
    whiteBall->setFixedSize(70, 70);
    blueBall->setFixedSize(70, 70);
    greenBall->setFixedSize(70, 70);

    redBall->setStyleSheet("background-color: red;");
    yellowBall->setStyleSheet("background-color: yellow;");
    blackBall->setStyleSheet("background-color: black;");
    whiteBall->setStyleSheet("background-color: white;");
    blueBall->setStyleSheet("background-color: blue;");
    greenBall->setStyleSheet("background-color: green;");

    QRect rect(10, 10, 50, 50);
    QRegion region(rect, QRegion::Ellipse);

    redBall->setMask(region);
    yellowBall->setMask(region);
    blackBall->setMask(region);
    whiteBall->setMask(region);
    blueBall->setMask(region);
    greenBall->setMask(region);


}


void GameFrame::makeConnection() {
    QObject::connect(saveGame, SIGNAL(triggered()), this, SLOT(saveGameClicked()));
}


void GameFrame::saveGameClicked() {
    std::cout << "Game Saved\n";
    // TODO really save game
}
