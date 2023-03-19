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

class Board : public QFrame{
Q_OBJECT
public:
    Board() = default;
    void paintEvent(QPaintEvent *event) override;
    void newGame(int nb_joueur, int puissance, int width, int heigth);

public slots:
    void addPiece(int col);

signals:
    void win(Color joueur);

private:
    int nb_joueur{};
    int puissance{};
    int width{};
    bool gagne();

    int colTemp;
    int ligneTemp;
    void addPieceTimer();

    int heigth=8;
    std::vector<std::vector<Color>> tab;
    Color joueur=Color::RED;
    bool canPlay;

    bool verif(int x, int j, int dx, int dy);
    void mousePressEvent(QMouseEvent *event) override;

};


#endif //PROJET_BOARD_H
