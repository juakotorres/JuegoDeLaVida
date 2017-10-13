//
// Created by juaki on 10/10/17.
//

#include <QtGui/QPainter>
#include <iostream>
#include "Canvas.h"
#include "../Examples/GosperGliderGun.h"
#include "../Examples/Lines.h"
#include "../Examples/Replicator.h"
#include "../Examples/Waifu.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    myExample = new Waifu();
    myGrid = myExample->getExample();
}

Canvas::~Canvas() { }

void Canvas::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPainter qp(this);

    drawGrid(&qp, this->width(), this->height());


}

void Canvas::drawGrid(QPainter *painter, int width, int height) {
    int widthP = width / myGrid->getWidth();
    int heightP = height / myGrid->getHeight();

    for (int i = 0; i < myGrid->getWidth(); i++){
        for (int j = 0; j < myGrid->getHeight(); j++){

            Qt::GlobalColor color = Qt::white;
            if (this->myGrid->getValue(i, j) == 1){
                color = Qt::black;
            }

            painter->fillRect(j*widthP, i*heightP, widthP, heightP, color);
        }
    }


}

void Canvas::runIteration(implementations *cpu) {
    cpu->runIteration(myGrid);
    //std::cout << "ya iteró" << std::endl;
    this->update();
}
