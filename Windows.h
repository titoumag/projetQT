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
    HEIGTH,
    VITESSE,
    TEMPS
};
#define NB_PARAM 6

class Reseau;
class QPushButton;
class Windows : public QWidget{
    Q_OBJECT
public :
    Windows();

public slots:
    void newGame();
    void gagne(Color joueur);
    void addPieceOk(int col);
    void addPieceReseau(int i);
    void nouvellePartieReseau();

private:
    Board *board;
    QPushButton *newGameButton;
//    QPushButton *quit;
    QHBoxLayout* hbox;
    QLCDNumber *lcdTimer;
    Param** listeParam;
    Reseau *reseau;
    int tempsTimer;

    int getVal(int i) const;
    QLabel *label;

public:
    QLabel *labelMessage;
    bool coupAutorise();

    void addWidgetDroite(QVBoxLayout *layout);
};


#endif //PROJET_WINDOWS_H
