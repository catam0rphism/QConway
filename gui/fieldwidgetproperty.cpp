#include "fieldwidgetproperty.h"

FieldWidgetProperty::FieldWidgetProperty() {
    _cellWidth = 10;
    _fieldSize = FieldSize(50, 50);
    _stepInterval = 100;

    QMutex mutex();
}

int FieldWidgetProperty::cellWidth() {
    return _cellWidth;
}

FieldSize FieldWidgetProperty::fieldSize() {
    return _fieldSize;
}

void FieldWidgetProperty::setCellWidth(int cellWidth) {
    mutex.lock();
    _cellWidth = cellWidth;
    mutex.unlock();

    emit cellWidthChanged(_cellWidth);
    emit configChanged();
}

void FieldWidgetProperty::setFieldSize(FieldSize size) {
    mutex.lock();
    _fieldSize = size;
    mutex.unlock();

    emit fieldSizeChanged(_fieldSize);
    emit configChanged();
}

int  FieldWidgetProperty::stepInterval() { return _stepInterval; }
void FieldWidgetProperty::setStepInterval(int interval) {
    mutex.lock();
    _stepInterval = interval;
    mutex.unlock();
    emit stepIntervalChanged(_stepInterval);
    emit configChanged();
}
