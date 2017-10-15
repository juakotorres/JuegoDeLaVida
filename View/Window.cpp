//
// Created by juaki on 5/2/17.
//

#include "Window.h"
#include <QPainter>

Window::Window(QWidget *parent)
        : QWidget(parent)
{
    modelo =  new model();
    setUpGUI();
}

void Window::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    QPainter qp(this);
    //widget->runIteration(cpu);
    //usleep(100000);
}

void Window::setUpGUI() {
    
    resize(823, 572);
    gridLayout_2 = new QGridLayout(this);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout_3 = new QGridLayout();
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

    QStringList items;
    items << tr("Lines") << tr("Replicator") << tr("Waifu");
    typeModel = new QStringListModel(items, this);

    comboBox = new QComboBox(this);
    comboBox->clear();
    comboBox->setModel(typeModel);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));

    gridLayout_3->addWidget(comboBox, 1, 0, 1, 1);

    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setScaledContents(false);
    label->setWordWrap(false);
    label->setText("Elegir Ejemplo: ");

    gridLayout_3->addWidget(label, 0, 0, 1, 1);

    QStringList items2;
    items2 << tr("CPU") << tr("CUDA") << tr("OpenCL");
    typeModel2 = new QStringListModel(items2, this);

    comboBox_2 = new QComboBox(this);
    comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
    comboBox_2->setModel(typeModel2);

    gridLayout_3->addWidget(comboBox_2, 1, 2, 1, 1);

    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    gridLayout_3->addWidget(pushButton_2, 1, 4, 1, 1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setText("Elegir implementación: ");

    gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);

    gridLayout_3->setColumnStretch(0, 1);
    gridLayout_3->setColumnStretch(2, 1);
    gridLayout_3->setColumnStretch(3, 3);
    gridLayout_3->setColumnStretch(4, 1);

    gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 1);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    widget = new Canvas(this);
    widget->setModel(modelo);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setMinimumSize(QSize(0, 272));

    gridLayout->addWidget(widget, 0, 0, 1, 1);


    gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

    gridLayout_2->setRowStretch(0, 20);
    gridLayout_2->setRowStretch(1, 3);

    pushButton_2->setText("Run");

    connect(pushButton_2, SIGNAL(pressed()), this, SLOT(handleButton()));

    QMetaObject::connectSlotsByName(this);

}

void Window::handleButton() {

    std::string chosenExample = comboBox->currentText().toUtf8().constData();
    std::string chosenImplementation = comboBox_2->currentText().toUtf8().constData();
    widget->handleButton(chosenExample, chosenImplementation);
}

Window::~Window() {

}