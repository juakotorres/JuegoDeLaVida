//
// Created by juaki on 10/10/17.
//

#ifndef JUEGODELADAVI_CANVAS_H
#define JUEGODELADAVI_CANVAS_H


#include <QtWidgets/QWidget>
#include "../Utils/Matrix.h"
#include "../Examples/Example.h"
#include "../Implementations/CPU/cpu.h"

class Canvas : public QWidget {
Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    ~Canvas();
    void runIteration(implementations *cpu);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Example *myExample;
    Matrix *myGrid;
    void drawGrid(QPainter *painter, int width, int height);
};


#endif //JUEGODELADAVI_CANVAS_H
