//
// Created by RainMaker on 2020-09-11.
//

#include "FrameTools.h"

void FrameTools::centerFrame(QWidget *frame, int width, int height) {
    QDesktopWidget *widget = QApplication::desktop();
    int desktop_width = widget->width();
    int desktop_height = widget->height();
    int x = desktop_width / 2 - width / 2;
    int y = desktop_height / 2 - height / 2 - 25;
    frame->move(QPoint(x, y));
}
