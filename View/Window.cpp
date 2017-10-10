//
// Created by juaki on 5/2/17.
//

#include "Window.h"
#include <QPainter>
#include <QtWidgets/QVBoxLayout>

Window::Window(QWidget *parent)
        : QWidget(parent)
{   setUpGUI(); }

void Window::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    QPainter qp(this);
}

void Window::setUpGUI() {

    resize(640, 480);
    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(30, 420, 161, 20));
    horizontalSlider = new QSlider(this);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setGeometry(QRect(210, 420, 160, 22));
    horizontalSlider->setMouseTracking(true);
    horizontalSlider->setMinimum(10);
    horizontalSlider->setMaximum(30);
    horizontalSlider->setOrientation(Qt::Horizontal);
    widget = new QWidget(this);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(0, 0, 640, 400));
    spinBox = new QSpinBox(this);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setGeometry(QRect(380, 421, 41, 21));
    spinBox->setMinimum(10);
    spinBox->setMaximum(30);
    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(450, 421, 92, 32));

    setWindowTitle("Delaunay");
    label->setText("Choose minimum angle: ");
    pushButton->setText("Process");
    QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), spinBox, SLOT(setValue(int)));
    QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
    connect(pushButton, SIGNAL(pressed()), this, SLOT(handleButton()));

    QMetaObject::connectSlotsByName(this);

}

void Window::handleButton() {

}

Window::~Window() {

}