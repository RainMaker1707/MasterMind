//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_GAMEFRAME_H
#define MASTERMIND_GAMEFRAME_H

#include <QtWidgets>
#include "FrameTools.h"

class GameFrame : public QMainWindow{

    Q_OBJECT;

    public:
        explicit GameFrame(QWidget *frame);

    private:
        QWidget *frame;
        void closeEvent(QCloseEvent *event) override;
};


#endif //MASTERMIND_GAMEFRAME_H
