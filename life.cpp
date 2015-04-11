// Copyright 2015 Belkin Dmitriy
#include "life.h"

Life::Life(int width, int height) {
    QBitArray field(width * height);
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
    if (x < 0) x += fieldSize.width();
    if (y < 0) y += fieldSize.height();

    x %= fieldSize.width();
    y %= fieldSize.height();

    return field[ind(x, y)];
}

void Life::setCell(int x, int y, bool value) {
    // fix bug with mod function
    if (x < 0) x += fieldSize.width();
    if (y < 0) y += fieldSize.height();

    x %= fieldSize.width();
    y %= fieldSize.height();

    field.setBit(ind(x, y), value);
}
