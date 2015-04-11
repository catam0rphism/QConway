// Copyright 2015 Belkin Dmitriy
#include "life.h"
#include <iostream>
using namespace std;

Life::Life(int width, int height) {
    this->field = QBitArray(width * height);
    this->field.fill(false);

    this->fieldSize = QSize(width, height);

    this->pretendentSet = QSet<int>();
    this->changedSet = QSet<int>();
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

void Life::doArea(int x, int y,
    std::function<void(bool, int, int)> f, int radius) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if(i == 0 && j == 0) continue;
            else f(field.at(ind(x + i, y + j)), x + i, y + j);
        }
    }
}

void Life::doArea(int x, int y,
    std::function<void(bool)> f, int radius) {
    // performance?
    doArea(x, y, [&f](bool b, int x, int y){ f(b); }, radius);
}

void Life::doArea(int x, int y,
    std::function<void(int, int)> f, int radius) {
    // performance?
    doArea(x, y, [&f](bool b, int x, int y){ f(x, y); }, radius);
}

void Life::step() {
    if (pretendentSet.empty()) {
        for (int i = 0; i < fieldSize.width(); i++) {
            for (int j = 0; j < fieldSize.height(); j++) {
                handleCell(i, j);
            }
        }
    } else {
        // cell set isn't empty

        auto i = QSetIterator<int>(pretendentSet);
        while (i.hasNext()) {
            int index = i.next();
            int y = index / fieldSize.width();
            int x = index % fieldSize.width();

            handleCell(x, y);
        }
    }

    auto i = QSetIterator<int>(changedSet);
    while (i.hasNext()) {
        field.toggleBit(i.next());
    }

    changedSet.clear();
    pretendentSet.clear();
}

void Life::handleCell(int i, int j) {
    int aliveCount = 0;
    doArea(i, j, [&aliveCount](bool cellState) {
        if (cellState) aliveCount++;
    });

    if ((getCell(i, j) && aliveCount != 2 && aliveCount != 3) ||
        (getCell(i, j) == false && aliveCount == 3)) {
        this->changedSet.insert(ind(i, j));

        pretendentSet.insert(ind(i, j));
        doArea(i, j, [this](int x, int y) {
            pretendentSet.insert(ind(x, y));
        });
    }
}
