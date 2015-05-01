// Copyright 2015 Belkin Dmitriy
#ifndef QFIELD_WIDGET_H
#define QFIELD_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>

typedef QSize FieldSize;  // field size (in cells)

#include "fieldwidgetproperty.h"
#include "configureform.h"
#include "../core/life.h"

class QFieldWidget: public QWidget {
    Q_OBJECT

 public:
    QFieldWidget(FieldWidgetProperty* propertyProvider);
    Life* life;

    ~QFieldWidget();
    void start();

 private slots:
    void updateSize();
    void updateInterval();
    void nextStep();
    void toggleState();

 protected:
    // TODO: wtf?
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

 private:
    FieldWidgetProperty* propertyProvider;
    QTimer* timer;
    QSize currFieldSize;
};

#endif  // QFIELD_WIDGET_H
