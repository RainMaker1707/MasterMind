#include "Game/MenuFrame.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuFrame menu;
    menu.show();

    QApplication::exec();
    return 0;
}