#include "fieldwidgetproperty.h"

FieldWidgetProperty::FieldWidgetProperty() {
    _cellWidth = 10;
    _fieldSize = FieldSize(50, 50);
    _stepInterval = 100;
}

int FieldWidgetProperty::cellWidth() {
    return _cellWidth;
}

FieldSize FieldWidgetProperty::fieldSize() {
    return _fieldSize;
}

void FieldWidgetProperty::setCellWidth(int cellWidth) {
    _cellWidth = cellWidth;

    emit cellWidthChanged(_cellWidth);
    emit configChanged();
}

void FieldWidgetProperty::setFieldSize(FieldSize size) {
    _fieldSize = size;

    emit fieldSizeChanged(_fieldSize);
    emit configChanged();
}

bool FieldWidgetProperty::isDrawBorders() {
    return _borders;
}

void FieldWidgetProperty::setIsDrawBorders(bool state) {
    _borders = state;
    emit isDrawBordersChanged(_borders);
    emit configChanged();
}

int  FieldWidgetProperty::stepInterval() { return _stepInterval; }
void FieldWidgetProperty::setStepInterval(int interval) {
    _stepInterval = interval;
    emit stepIntervalChanged(_stepInterval);
    emit configChanged();
}
