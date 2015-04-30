// Copyright 2015 Belkin Dmitriy
#include "qfieldWidget.h"

QFieldWidget::QFieldWidget(FieldWidgetProperty* propertyProvider) {
    this->propertyProvider = propertyProvider;


    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));
    connect(propertyProvider, SIGNAL(configChanged()), this, SLOT(updateInterval()));
}

QFieldWidget::~QFieldWidget() {
    delete life;
    // delete timer;
    // delete propertyProvider;
}

void QFieldWidget::updateSize() {
    resize(propertyProvider->fieldSize() * propertyProvider->cellWidth());

    int w = propertyProvider->fieldSize().width();
    int h = propertyProvider->fieldSize().height();
 
    this->life = new Life(w, h);
}

void QFieldWidget::updateInterval() {
    timer->setInterval(propertyProvider->stepInterval());
}

void QFieldWidget::nextStep() {
    life->step();
    update();
}

void QFieldWidget::start() {
    timer->start();
}

void QFieldWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    // painter.setFont(QFont("Arial", 30));
    // painter.drawText(rect(), Qt::AlignCenter, "Hello, world!");

    resize(propertyProvider->fieldSize() * propertyProvider->cellWidth());

    int w = propertyProvider->fieldSize().width();
    int h = propertyProvider->fieldSize().height();

    int cellWidth = propertyProvider->cellWidth();


    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            QBrush aliveBrush(Qt::red);
            QBrush deadBrush(Qt::black);
            
            int x = i * cellWidth;
            int y = j * cellWidth;

            painter.fillRect(x, y, cellWidth, cellWidth,
                life->getCell(i,j) ? aliveBrush : deadBrush);
        }
    }

    // painter.setPen(Qt::blue);
    // for (int i = 0; i <= w; ++i) {
    //     painter.drawLine(i * cellWidth, 0, i * cellWidth, h * cellWidth);
    // }

    // for (int i = 0; i <= h; ++i) {
    //     painter.drawLine(0, i * cellWidth, w * cellWidth, i * cellWidth);
    // }
}