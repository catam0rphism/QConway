// Copyright 2015 Belkin Dmitriy
#include "qfieldWidget.h"

void QFieldWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
}