// Copyright 2015 Belkin Dmitriy
#include "life.h"

Life::Life(int width, int height) {
    field = new QBitArray(width * height);
    pretendentSet = nullptr;
}

int Life::ind(int x, int y) {
    if (y < fieldSize.height() && x < fieldSize.width()) {
        return fieldSize.width() * y + x;
    }
    throw;
}

bool Life::getCell(int x, int y) {
    return field->at(ind(x, y));
}

void Life::step() {
}
