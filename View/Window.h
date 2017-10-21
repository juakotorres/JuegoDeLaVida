//
// Created by juaki on 10/9/17.
//

#ifndef JUEGODELADAVI_WINDOW_H
#define JUEGODELADAVI_WINDOW_H

#pragma once

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtCore/QStringListModel>
#include <QtWidgets/QGridLayout>
#include "../Implementations/CPU/cpu.h"
#include "Canvas.h"
#include "../Implementations/OpenCL/parallelOpenCL.h"
#include "../Model/model.h"


class Window : public QWidget {
Q_OBJECT
public:
    Window(QWidget *parent = 0);
    ~Window();

public slots:
    void handleButton();
    void handleButton1s();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    Canvas *widget;
    QPushButton *pushButton_3;
    QStringListModel *typeModel;
    QStringListModel *typeModel2;

    void setUpGUI();

    model *modelo;

};



#endif //JUEGODELADAVI_WINDOW_H
