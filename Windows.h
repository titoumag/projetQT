//
// Created by titou on 11/03/2023.
//

#ifndef PROJET_WINDOWS_H
#define PROJET_WINDOWS_H


#include <QMainWindow>
#include <QLCDNumber>
#include <QSlider>
#include <QHBoxLayout>
#include "Board.h"
#include "Param.h"

enum dim{
    NB_JOUEUR,
    PUISSANCE,
    WIDTH,
    HEIGTH
};
#define NB_PARAM 4

class QPushButton;
class Windows : public QWidget{
public :
    Windows();

public slots:
    void newGame();

private:
    Board *board;
    QPushButton *newGameButton;
    QPushButton *quit;
//    std::vector<QPushButton*> buttonCol;
    QHBoxLayout* hbox;
    Param** listeParam;

    int getVal(int i) const;
};


#endif //PROJET_WINDOWS_H
