//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_MENUFRAME_H
#define MASTERMIND_MENUFRAME_H

#include <QtWidgets>
#include "GameFrame.h"
#include "FrameTools.h"

class MenuFrame: public QWidget {

    Q_OBJECT;

    public:
        MenuFrame();
        void setupCursors();

    public slots:
        void startButtonClicked();
        void loadButtonClicked();
        void helpButtonClicked();
        void parametersButtonClicked();

    signals:

    private:
        QVBoxLayout *mainLayout;
        QHBoxLayout *buttonLayout;
        QHBoxLayout *topLayout;
        QVBoxLayout *rightTopLayout;

        QPushButton *startButton;
        QPushButton *quitButton;
        QPushButton *loadGameButton;
        QPushButton *helpButton;
        QPushButton *parametersButton;

        void makeConnection();
};


#endif //MASTERMIND_MENUFRAME_H
