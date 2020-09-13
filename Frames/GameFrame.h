//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_GAMEFRAME_H
#define MASTERMIND_GAMEFRAME_H

#include <QtWidgets>
#include <iostream>
#include "FrameTools.h"

class GameFrame : public QMainWindow{

    Q_OBJECT;

    public:
        explicit GameFrame(QWidget *frame);

    public slots:
        static void saveGameClicked();


    private:
        QWidget *frame;
        QWidget *container;

        QMenu *gameMenu;
        QAction *newGame;
        QMenu *loadMenu;
        QAction *saveGame;

        QVBoxLayout *mainLayoutV;
        QHBoxLayout *mainLayoutH;
        QGridLayout *leftGrid;
        QGridLayout *centralGrid;
        QGridLayout *rightGrid;
        QHBoxLayout *userLayout;
        QHBoxLayout *userLayout1;

        void closeEvent(QCloseEvent *event) override;
        void setupMenuBar();
        void setupLoadMenu();
        void setupLayout();
        void makeConnection();
        void setupGrid();
        void setupUserChoice();
};


#endif //MASTERMIND_GAMEFRAME_H
