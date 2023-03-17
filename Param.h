//
// Created by titou on 15/03/2023.
//

#ifndef PROJET_PARAM_H
#define PROJET_PARAM_H


#include <QWidget>

class Param : public QWidget{
public:
    Param(const char *texte, int min, int max,int defaut);
    QSlider *widget;
};


#endif //PROJET_PARAM_H
