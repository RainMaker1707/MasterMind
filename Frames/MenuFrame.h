//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_MENUFRAME_H
#define MASTERMIND_MENUFRAME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <iostream>
#include "GameFrame.h"
#include "FrameTools.h"

class MenuFrame: public QWidget {

    Q_OBJECT;

    public:
        MenuFrame();
        void setupCursors();

    public slots:
        void startButtonClicked();
        static void loadButtonClicked();
        static void difficultiesButtonClicked();
        static void helpButtonClicked();
        static void parametersButtonClicked();

    signals:

    private:
        QVBoxLayout *mainLayout;
        QHBoxLayout *topLayout;
        QVBoxLayout *rightTopLayout;

        QPushButton *startButton;
        QPushButton *quitButton;
        QPushButton *loadGameButton;
        QPushButton *helpButton;
        QPushButton *parametersButton;
        QPushButton *difficultiesButton;

        void setupLayout();
        void makeConnection();
};


#endif //MASTERMIND_MENUFRAME_H
