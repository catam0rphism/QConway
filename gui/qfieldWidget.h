// Copyright 2015 Belkin Dmitriy
#ifndef QFIELD_WIDGET_H
#define QFIELD_WIDGET_H

#include <QWidget>
#include <QPainter>

#include "interfaces.cpp"

typedef QSize FieldSize;  // field size (in cells)

class QFieldWidget: public QWidget {
    Q_OBJECT

 public:
    QFieldWidget(IFieldWidgetProperty* propertyProvider);

 protected:
    // TODO: wtf?
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

 private:
    IFieldWidgetProperty* propertyProvider;
};

#endif  // QFIELD_WIDGET_H
