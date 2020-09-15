//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_GAMEFRAME_H
#define MASTERMIND_GAMEFRAME_H

#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QObject>
#include <iostream>
#include "GameTool.h"

class GameFrame : public QMainWindow{

    Q_OBJECT;

    public:
        explicit GameFrame(QWidget *frame);

    public slots:
        static void saveGameClicked();
        void newGameClicked();
        void redButtonClicked();
        void yellowButtonClicked();
        void blackButtonClicked();
        void whiteButtonClicked();
        void blueButtonClicked();
        void greenButtonClicked();

    signals:
        void newGameSignal();


    private:
        QWidget *frame;
        QWidget *container;

        QMenu *gameMenu;
        QAction *newGame;
        QMenu *loadMenu;
        QAction *saveGame;
        QMenu *parametersMenu;
        QAction *languageAction;
        QAction *difficultiesAction;
        QAction *helpAction;

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

        int row_ = 0;
        int col_ = 0;

        void initColor();
        void closeEvent(QCloseEvent *event) override;
        void setupMenuBar();
        void setupLoadMenu();
        void setupLayout();
        void makeConnection();
        void setupGrid();
        void setupUserChoice();
        void colorClicked(QColor *color);
        void checkCombination();
        void setAnsGridColor(int attempts, int pos, QColor *color);
};


#endif //MASTERMIND_GAMEFRAME_H
