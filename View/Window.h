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


class Window : public QWidget {
Q_OBJECT
public:
    Window(QWidget *parent = 0);
    ~Window();
public slots:
    void handleButton();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QLabel *label;
    QSlider *horizontalSlider;
    QWidget *widget;
    QSpinBox *spinBox;
    QPushButton *pushButton;

    void setUpGUI();
};



#endif //JUEGODELADAVI_WINDOW_H
