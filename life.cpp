// Copyright 2015 Belkin Dmitriy
#include "life.h"

Life::Life(int width, int height) {
    this->field = QBitArray(width * height);
    this->field.fill(false);

    this->fieldSize = QSize(width, height);
    // QSet<int> pretendentSet;
}

inline int Life::ind(int x, int y) {
    // if (y < fieldSize.height() && x < fieldSize.width()) {
        return fieldSize.width() * y + x;
    // }
    // throw;
}

bool Life::getCell(int x, int y) {
    // fix bug with mod function
    while (x < 0) x += fieldSize.width();
    while (y < 0) y += fieldSize.height();

    x %= fieldSize.width();
    y %= fieldSize.height();

    return field[ind(x, y)];
}

void Life::setCell(int x, int y, bool value) {
    // fix bug with mod function
    while (x < 0) x += fieldSize.width();
    while (y < 0) y += fieldSize.height();

    x %= fieldSize.width();
    y %= fieldSize.height();

    field[ind(x, y)] = value;
}
