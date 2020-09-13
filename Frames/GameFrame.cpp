//
// Created by RainMaker on 2020-09-11.
//
#include "GameFrame.h"

GameFrame::GameFrame(QWidget *frame): QMainWindow() {
    this->frame = frame;
    setWindowTitle("MasterMind Game Board");

    gameMenu = new QMenu;
    newGame = new QAction;
    saveGame = new QAction;
    loadMenu = new QMenu;
    container = new QWidget;
    mainLayoutV = new QVBoxLayout;
    mainLayoutH = new QHBoxLayout;
    leftGrid = new QGridLayout;
    centralGrid = new QGridLayout;
    rightGrid = new QGridLayout;
    userLayout = new QHBoxLayout;
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
    newGame = gameMenu->addAction("&New Game");
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
    container->setLayout(mainLayoutV);
    mainLayoutV->addLayout(mainLayoutH);
    mainLayoutH->addLayout(leftGrid);
    mainLayoutH->addLayout(centralGrid);
    mainLayoutH->addLayout(rightGrid);
    mainLayoutV->addLayout(userLayout);
    mainLayoutV->addLayout(userLayout1);

    leftGrid->setColumnMinimumWidth(0, 35);
    rightGrid->setColumnMinimumWidth(0, 35);
}


void GameFrame::setupGrid() {
    for (int  col=0; col<4; col++) centralGrid->setColumnMinimumWidth(col, 35);
    for (int row = 0; row < 12; row++){
        centralGrid->setRowMinimumHeight(row, 35);
        auto ansGrid = new QGridLayout;
        auto ansWdg = new QWidget;
        auto ansNoWdg = new QWidget;
        ansWdg->setStyleSheet("background-color: lightsteelblue;");
        if (row%2 == 0){
            leftGrid->addWidget(ansWdg, row, 0);
            ansWdg->setLayout(ansGrid);
            rightGrid->addWidget(ansNoWdg, row, 0);
        }
        else {
            rightGrid->addWidget(ansWdg, row, 0);
            ansWdg->setLayout(ansGrid);
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
    auto redBall = new QPushButton("Red");
    auto yellowBall = new QPushButton("Yellow");
    auto blackBall = new QPushButton("Black");
    auto whiteBall = new QPushButton("White");
    auto blueBall = new QPushButton("Blue");
    auto greenBall = new QPushButton("Green");
    userLayout->addWidget(redBall);
    userLayout->addWidget(yellowBall);
    userLayout->addWidget(blackBall);
    userLayout1->addWidget(whiteBall);
    userLayout1->addWidget(blueBall);
    userLayout1->addWidget(greenBall);

}


void GameFrame::makeConnection() {
    QObject::connect(saveGame, SIGNAL(triggered()), this, SLOT(saveGameClicked()));
}


void GameFrame::saveGameClicked() {
    std::cout << "Game Saved\n";
    // TODO really save game
}
