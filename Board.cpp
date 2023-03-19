//
// Created by titou on 11/03/2023.
//

#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include "Board.h"

void Board::newGame(int nb_joueur, int puissance, int width, int heigth) {
    this->nb_joueur=nb_joueur;
    this->puissance=puissance;
    this->width=width;
    this->heigth=heigth;
    canPlay=false;
    setFixedSize(width*50, heigth*50);
    tab = std::vector<std::vector<Color>>(width,std::vector(heigth,Color::NONE));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < heigth; j++) {
            tab[i][j] = Color::NONE;
        }
    }
    joueur=Color::RED;
    update();
}

void Board::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);

    QRect rect = contentsRect();

    QPainter painter(this);
    painter.setBrush(Qt::darkBlue);
    painter.drawRect(0, 0, rect.width(), rect.height());

    const Qt::GlobalColor colors[6] = {Qt::red, Qt::yellow, Qt::green,Qt::magenta, Qt::white,Qt::black};
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < heigth; ++j) {
            painter.setBrush(colors[(int)tab[i][j]]);
            painter.drawEllipse((i*rect.width())/width+2,(j*rect.height())/heigth,(rect.height())/heigth-4,(rect.height())/heigth-4);
        }
    }

    painter.end();
}

void Board::mousePressEvent(QMouseEvent *event) {
    addPiece(event->pos().x()/50);
}

void Board::addPiece(int col) {
    if (canPlay) return;
    canPlay=true;
    colTemp=col;
    ligneTemp=-1;
    addPieceTimer();
}

void Board::addPieceTimer(){
    if (ligneTemp!=-1)
        tab[colTemp][ligneTemp]=Color::NONE;
    if (tab[colTemp][ligneTemp+1]==Color::NONE && ligneTemp<heigth-1){
        tab[colTemp][ligneTemp+1]=joueur;
        ligneTemp++;
        update();
        QTimer::singleShot(100, this, &Board::addPieceTimer);
    }else{
        int y=ligneTemp;
        if (tab[colTemp][y]==Color::NONE){
            tab[colTemp][y]=joueur;
            update();
            if (!gagne()) {
                joueur = (Color) (((int) joueur + 1) % nb_joueur);
                canPlay=false;
            }else {
                emit win(joueur);
                canPlay=true;
                update();
            }
        }
    }
}


bool Board::gagne(){
    for(int i=0;i<width;i++)
        for(int j=0;j<heigth;j++) {
            if (verif(i,j,1,0) || verif(i,j,0,1) || verif(i,j,1,1) || verif(i,j,1,-1))
                return true;
        }
    return false;
}

bool Board::verif(int x,int j,int dx, int dy){
    for (int i = 0; i < puissance; ++i) {
        if (x+i*dx>=width || j+i*dy>=heigth || j+i*dy<0 || tab[x+i*dx][j+i*dy]!=joueur)
            return false;
    }
    for (int i = 0; i < puissance; ++i) {
        tab[x+i*dx][j+i*dy]=Color::FINISH;
    }
    std::cout << "gagne"<<std::endl;
    return true;
}

