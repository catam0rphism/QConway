// Copyright 2015 Belkin Dmitriy
#ifndef QFIELD_WIDGET_H
#define QFIELD_WIDGET_H

#include <QWidget>
#include <QPainter>

typedef QSize FieldSize;  // field size (in cells)

class QFieldWidget: public QWidget {
    Q_OBJECT

 public:
    QFieldWidget() { }

    FieldSize fieldSize;
    QSize cellSize;

 protected:
    // TODO: wtf?
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
 private:
};

#endif  // QFIELD_WIDGET_H
