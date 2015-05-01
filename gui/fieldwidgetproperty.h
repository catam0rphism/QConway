#ifndef FIELDWIDGETPROPERTY_H
#define FIELDWIDGETPROPERTY_H

#include <QObject>
#include <QSize>
#include <QColor>

typedef QSize FieldSize;

class FieldWidgetProperty: public QObject {
    Q_OBJECT

 public:
    FieldWidgetProperty();

    int cellWidth();
    void setCellWidth(int cellWidth);

    FieldSize fieldSize();
    void setFieldSize(FieldSize fieldSize);

    int stepInterval();
    void setStepInterval(int interval);

    bool isDrawBorders();
    void setIsDrawBorders(bool state);

 signals:
    void configChanged();
    void isDrawBordersChanged(bool state);
    void fieldSizeChanged(FieldSize size);
    void cellWidthChanged(int cellWidth);
    void stepIntervalChanged(int interval);

 private:
    int _cellWidth;
    FieldSize _fieldSize;
    int _stepInterval;
    bool _borders;
};

#endif  // FIELDWIDGETPROPERTY_H
