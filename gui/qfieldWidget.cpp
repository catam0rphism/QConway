// Copyright 2015 Belkin Dmitriy
#include "qfieldWidget.h"

QFieldWidget::QFieldWidget(IFieldWidgetProperty* propertyProvider) {
    this->propertyProvider = propertyProvider;
    resize(_fieldSize * _cellWidth);
}

void QFieldWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Hello, world!");
}