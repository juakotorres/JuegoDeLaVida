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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QStringListModel *typeModel;
    QStringListModel *typeModel2;

    void setUpGUI();
};



#endif //JUEGODELADAVI_WINDOW_H
