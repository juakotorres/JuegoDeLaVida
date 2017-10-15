//
// Created by juaki on 10/10/17.
//

#include <QtGui/QPainter>
#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
}

Canvas::~Canvas() { }

void Canvas::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPainter qp(this);

    drawGrid(&qp, this->width(), this->height());


}

void Canvas::drawGrid(QPainter *painter, int width, int height) {
    Matrix *myGrid = myModel->getGrid();

    int widthP = width / myGrid->getWidth();
    int heightP = height / myGrid->getHeight();

    for (int i = 0; i < myGrid->getWidth(); i++){
        for (int j = 0; j < myGrid->getHeight(); j++){

            Qt::GlobalColor color = Qt::white;
            if (myGrid->getValue(i, j) == 1){
                color = Qt::black;
            }

            painter->fillRect(j*widthP, i*heightP, widthP, heightP, color);
        }
    }

}

void Canvas::setModel(model *pModel) {
    myModel = pModel;
}

void Canvas::handleButton(std::string chosenExample, std::string chosenImplementation) {

    myModel->setCurrentImplementation(chosenImplementation);
    myModel->setCurrentExample(chosenExample);
    myModel->runIteration();

    this->update();
}
