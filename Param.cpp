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

    layout->addWidget(new QLabel(texte),0,0);

    auto* valeur = new QLabel();
    valeur->setNum(defaut);
    layout->addWidget(valeur,0,1);

    widget = new QSlider(Qt::Orientation::Horizontal);
    widget->setRange(min,max);
    layout->addWidget(widget,1,0,1,2);

    connect(widget, SIGNAL(valueChanged(int)), valeur, SLOT(setNum(int)));
}
