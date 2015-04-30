#ifndef FIELDWIDGETPROPERTY_H
#define FIELDWIDGETPROPERTY_H

#include <QObject>
#include <QSize>
#include <QColor>
#include <QMutex>

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

 signals:
    void configChanged();
    void fieldSizeChanged(FieldSize size);
    void cellWidthChanged(int cellWidth);
    void stepIntervalChanged(int interval);

 private:
    int _cellWidth;
    FieldSize _fieldSize;
    int _stepInterval;

    QMutex mutex;
};

#endif  // FIELDWIDGETPROPERTY_H
