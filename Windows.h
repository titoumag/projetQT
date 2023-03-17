//
// Created by titou on 11/03/2023.
//

#ifndef PROJET_WINDOWS_H
#define PROJET_WINDOWS_H


#include <QMainWindow>
#include <QLCDNumber>
#include <QSlider>
#include "Board.h"

class QPushButton;
//class Windows : public QMainWindow{
class Windows : public QWidget{
public :
    Windows();

public slots:
    void newGame();

private:
    Board *board;
    QPushButton *newGameButton;
    QPushButton *quit;
    std::vector<QPushButton*> buttonCol;
    QSlider *widthS;
};


#endif //PROJET_WINDOWS_H
