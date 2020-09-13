//
// Created by RainMaker on 2020-09-11.
//

#ifndef MASTERMIND_FRAMETOOLS_H
#define MASTERMIND_FRAMETOOLS_H

#include <QtWidgets>

class FrameTools: public QWidget {
    public:
        static void centerFrame(QWidget *frame, int width, int height);
        static QLabel *imageParser(const char str[], float width, float height);

};


#endif //MASTERMIND_FRAMETOOLS_H
