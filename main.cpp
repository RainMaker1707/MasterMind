#include <iostream>
#include <QDebug>
#include "Frames/MenuFrame.h"

int main(int argc, char *argv[]) {
    qDebug() << QT_VERSION_STR;
    QApplication app(argc, argv);

    MenuFrame menu;

    QApplication::exec();
    return 0;
}