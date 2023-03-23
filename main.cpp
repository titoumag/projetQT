#include <QApplication>
#include <QFile>
#include <QStyleFactory>
#include <iostream>
#include "Windows.h"

void modeSombre(QApplication*);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    modeSombre(&a);
    Windows window;
    window.show();
    return QApplication::exec();
}

void modeSombre(QApplication* app){
    app->setStyle(QStyleFactory::create("Fusion"));
    QPalette p = app->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(255,255,255));
    app->setPalette(p);
}