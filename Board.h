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
    ORANGE,
    NONE,
    FINISH
};

class Board : public QFrame{
public:
    Board() = default;
    void paintEvent(QPaintEvent *event) override;
    void newGame(int nb_joueur, int puissance, int width, int heigth);

public slots:
    void addPiece(int col);

private:
    int nb_joueur;
    int puissance;
    int width;

    int heigth=8;
    std::vector<std::vector<Color>> tab;
    Color joueur=Color::RED;
    bool gagne();

    bool verif(int x, int j, int dx, int dy);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};


#endif //PROJET_BOARD_H
