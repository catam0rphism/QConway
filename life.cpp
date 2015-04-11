// Copyright 2015 Belkin Dmitriy
#include "life.h"

using namespace std;

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

void Life::doArea(int x, int y,
    std::function<void(bool, int, int)> f, int radius) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            f(field.at(ind(x + i, y + j)), x + i, y + j);
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
                int aliveCount = 0;
                doArea(i, j, [&aliveCount](bool cellState) {
                    if (cellState) aliveCount++;
                });

                if (getCell(i, j) && aliveCount != 2 && aliveCount != 3) {
                    setCell(i, j, false);
                    doArea(i, j, [this](int x, int y) {
                        this->pretendentSet.insert(ind(x, y));
                    });
                } else if (!getCell(i, j) && aliveCount == 3) {
                    setCell(i, j, true);
                    doArea(i, j, [this](int x, int y) {
                        this->pretendentSet.insert(ind(x, y));
                    });
                }
            }
        }
    }
}
