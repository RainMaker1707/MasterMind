//
// Created by RainMaker on 2020-09-11.
//

#include "GameFrame.h"

GameFrame::GameFrame(QWidget *frame): QMainWindow() {
    this->frame = frame;
    setGeometry(0, 0, maximumWidth(), maximumHeight());
    setWindowTitle("MasterMind Game Board");

    gameMenu = new QMenu;
    newGame = new QAction;
    saveGame = new QAction;
    loadMenu = new QMenu;

    mainLayoutV = new QVBoxLayout;
    mainLayoutH = new QHBoxLayout;
    leftGrid = new QGridLayout;
    centralGrid = new QGridLayout;
    rightGrid = new QGridLayout;
    userLayout = new QHBoxLayout;

    container = new QWidget;

    setupMenuBar();
    setCentralWidget(container);
    setupLayout();

    makeConnection();
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

    setupLoadMenu();
}

void GameFrame::setupLoadMenu() {
    // TODO display real saved game
    for(int i = 0; i < 5; i++) {

        char buff[100];
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
}

void GameFrame::makeConnection() {
    QObject::connect(saveGame, SIGNAL(triggered()), this, SLOT(saveGameClicked()));
}

void GameFrame::saveGameClicked() {
    std::cout << "Game Saved\n";
    // TODO really save game
}

