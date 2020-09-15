//
// Created by RainMaker on 2020-09-11.
//

#include "GameTool.h"

void GameTool::centerFrame(QWidget *frame, int width, int height) {
    QDesktopWidget *widget = QApplication::desktop();
    int desktop_width = widget->width();
    int desktop_height = widget->height();
    int x = desktop_width / 2 - width / 2;
    int y = desktop_height / 2 - height / 2 - 50;
    frame->move(QPoint(x, y));
}

QLabel *GameTool::imageParser(const char str[], float width, float height) {
    QImage img(str);
    QImage img2 = img.scaled((int) width, (int) height, Qt::KeepAspectRatio);
    QLabel *plotImg = new QLabel;
    plotImg->setScaledContents(true);
    plotImg->setPixmap(QPixmap::fromImage(img2));
    return plotImg;
}
