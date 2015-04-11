// Copyright 2015 Belkin Dmitriy
#include <QApplication>
#include <QDebug>

#include "iostream"

#include "config.h"
#include "life.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Config* tmp = Config::getConfig();
    tmp->test = "new foo";
    Config::setConfig(tmp);

    qDebug() << Config::getConfig()->test << endl;

    Life life(10, 10);
    life.setCell(0, 0, true);
    life.setCell(0, 1, true);
    life.setCell(0, 2, true);
    life.setCell(2, 1, true);
    life.setCell(1, 2, true);

    int N = 20;
    while (N-->0) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << (life.getCell(i, j) ? '0' : '.');
            }
            cout << endl;
        }

        cout << endl << endl;

        life.step();
    }


    return app.exec();
}
