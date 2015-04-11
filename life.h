// Copyright 2015 Belkin Dmitriy
#ifndef LIFE_H
#define LIFE_H

#include "functional"

#include <QBitArray>
#include <QPoint>
#include <QSize>
#include <QSet>
#include <QVector>

class Life {
 public:
    Life(int width, int height);
    // ~Life();

    // do it immutable?
    void step();

    bool getCell(int x, int y);
    void setCell(int x, int y, bool value);

 private:
    int ind(int x, int y);

    QSize fieldSize;

    QBitArray field;
    QSet<int> pretendentSet;

    void doArea(int x, int y,
        std::function<void(bool, int, int)> f, int radius = 1);
    void doArea(int x, int y,
        std::function<void(int, int)> f, int radius = 1);
    void doArea(int x, int y,
        std::function<void(bool)> f, int radius = 1);
};

#endif
