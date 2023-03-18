//
// Created by titou on 15/03/2023.
//

#ifndef PROJET_PARAM_H
#define PROJET_PARAM_H


#include <QWidget>

class QSlider;
class QLabel;
class Param : public QWidget{
Q_OBJECT
public:
    Param(const char *texte, int min, int max,int defaut);
    QSlider *widget;
    QLabel *valeur;
    int val;
    int defaultVal;
    int getVal() const;
    void defautParam();

public slots:
    void setVal(int val);

};


#endif //PROJET_PARAM_H
