//
// Created by titou on 15/03/2023.
//

#include <QLabel>
#include <QSlider>
#include <QGridLayout>
#include "Param.h"

Param::Param(const char *texte, int min, int max,int defaut) {
    auto *layout = new QGridLayout(this);
    setLayout(layout);
    this->val = defaut;

    layout->addWidget(new QLabel(texte),0,0);

    valeur = new QLabel();
    valeur->setNum(defaut);
    layout->addWidget(valeur,0,1);

    widget = new QSlider(Qt::Orientation::Horizontal);
    widget->setRange(min,max);
    widget->setValue(defaut);
    layout->addWidget(widget,1,0,1,2);

    connect(widget, SIGNAL(valueChanged(int)), this, SLOT(setVal(int)));
}

void Param::setVal(int val) {
    valeur->setNum(val);
    this->val = val;
}

int Param::getVal() const {
    return val;
}
