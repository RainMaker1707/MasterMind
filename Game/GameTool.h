//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_GAMETOOL_H
#define MASTERMIND_GAMETOOL_H

#include <QtWidgets>

class GameTool: public QWidget {
    public:
        static void centerFrame(QWidget *frame, int width, int height);
        static QLabel *imageParser(const char str[], float width, float height);

};


#endif //MASTERMIND_GAMETOOL_H
