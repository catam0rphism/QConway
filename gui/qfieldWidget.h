// Copyright 2015 Belkin Dmitriy
#ifndef QFIELD_WIDGET_H
#define QFIELD_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

typedef QSize FieldSize;  // field size (in cells)

#include "fieldwidgetproperty.h"
#include "../core/life.h"

class QFieldWidget: public QWidget {
    Q_OBJECT

 public:
    QFieldWidget();
    Life* life;

    ~QFieldWidget();
    void start();

 private slots:
    void updateSize();
    void updateInterval();
    void nextStep();

 protected:
    // TODO: wtf?
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

 private:
    FieldWidgetProperty& propertyProvider;
    QTimer* timer;
};

#endif  // QFIELD_WIDGET_H
