//
// Created by titou on 11/03/2023.
//

#ifndef PROJET_BOARD_H
#define PROJET_BOARD_H


#include <QWidget>
#include <QFrame>

enum class Color{
    RED,
    YELLOW,
    GREEN,
    ORANGE,
    NONE,
    FINISH
};

class Windows;
class Board : public QFrame{
Q_OBJECT
public:
    Board(Windows *windows);
    void paintEvent(QPaintEvent *event) override;
    void newGame(int nb_joueur, int puissance, int width, int heigth, int vitesse);
    int joueurActuel();

public slots:
    void addPiece(int col);

signals:
    void win(Color joueur);
    void addPieceOk(int);

private:
    int nb_joueur{};
    int puissance{};
    int width{};
    bool gagne();
    int vitesse;

    int colTemp;
    int ligneTemp;
    void addPieceTimer();

    int heigth=8;
    std::vector<std::vector<Color>> tab;
    Color joueur=Color::RED;
    bool canPlay;
    Windows *windows;

    bool verif(int x, int j, int dx, int dy);
    void mousePressEvent(QMouseEvent *event) override;

};


#endif //PROJET_BOARD_H
