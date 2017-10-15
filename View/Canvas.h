//
// Created by juaki on 10/10/17.
//

#ifndef JUEGODELADAVI_CANVAS_H
#define JUEGODELADAVI_CANVAS_H


#include <QtWidgets/QWidget>
#include "../Utils/Matrix.h"
#include "../Examples/Example.h"
#include "../Implementations/CPU/cpu.h"
#include "../Model/model.h"

class Canvas : public QWidget {
Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    ~Canvas();

    void handleButton(std::string string, std::string basic_string);
    void setModel(model *pModel);

protected:
    void paintEvent(QPaintEvent *event);

private:
    model *myModel;
    void drawGrid(QPainter *painter, int width, int height);
};


#endif //JUEGODELADAVI_CANVAS_H
