//
// Created by titou on 11/03/2023.
//

#ifndef PROJET_BOARD_H
#define PROJET_BOARD_H


#include <QWidget>

enum class Color{
    RED,
    YELLOW,
    GREEN,
    NONE,
    FINISH
};

class Board : public QFrame{
public:
    Board(int nb_joueur, int puissance, int width);
    void paintEvent(QPaintEvent *event) override;
    void newGame(int nb_joueur, int puissance, int width);

public slots:
    void addPiece(int col);

private:
    int nb_joueur;
    int puissance;
    int width;

    int heigth=8;
    std::vector<Color[8]> tab;
    Color joueur=Color::RED;
    bool gagne();

    bool verif(int x, int j, int dx, int dy);
};


#endif //PROJET_BOARD_H
