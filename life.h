// Copyright 2015 Belkin Dmitriy
#ifndef LIFE_H
#define LIFE_H

#include <QBitArray>
#include <QPoint>
#include <QSize>
#include <QSet>

class Life {
 public:
    Life(int width, int height);
    ~Life();

    // do it immutable?
    void step();

    bool getCell(int x, int y);
    void setCell(int x, int y, bool value);

 private:
    int ind(int x, int y);

    QSize fieldSize;

    QBitArray* field;
    QSet<QPoint>* pretendentSet;
};

#endif
