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
        void saveGameClicked();
        void redButtonClicked();
        void yellowButtonClicked();
        void blackButtonClicked();
        void whiteButtonClicked();
        void blueButtonClicked();
        void greenButtonClicked();


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

        QPushButton *redBall;
        QPushButton *yellowBall;
        QPushButton *blackBall;
        QPushButton *whiteBall;
        QPushButton *blueBall;
        QPushButton *greenBall;

        QColor *red;
        QColor *yellow;
        QColor *black;
        QColor *white;
        QColor *blue;
        QColor *green;

        void initColor();
        void closeEvent(QCloseEvent *event) override;
        void setupMenuBar();
        void setupLoadMenu();
        void setupLayout();
        void makeConnection();
        void setupGrid();
        void setupUserChoice();
        void colorClicked(QColor *color);
};


#endif //MASTERMIND_GAMEFRAME_H
