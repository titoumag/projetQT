#include <QApplication>
#include "Windows.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Windows window;
    window.show();
    return QApplication::exec();
}
