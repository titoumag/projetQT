#ifndef PROJET_WINDOWS_H
#define PROJET_WINDOWS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QGridLayout>
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
class Windows : public QWidget{
    Q_OBJECT
public :
    Windows();
    QTimer *timer;
    QLabel *labelMessage;
    bool coupAutorise() const;
    void addWidgetDroite(QVBoxLayout *layout);

public slots:
    void newGame();
    void gagne(Color joueur);
    void addPieceOk(int col);
    void addPieceReseau(int i);
    void nouvellePartieReseau();
    void updateTimer();
    void changeModeTimer(int mode);

private:
    Board *board;
    QPushButton *newGameButton;
    QHBoxLayout* hbox;
    QLCDNumber *lcdTimer;
    Param** listeParam;
    Reseau *reseau;
    int tempsTimer;
    int tempsPartie;
    QLabel *label;
    bool timerActif;
    int getVal(int i) const;

};


#endif //PROJET_WINDOWS_H
