// Copyright 2015 Belkin Dmitriy
#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QPainter>

#include "iostream"

#include "core/config.h"
#include "core/life.h"
#include "gui/qfieldWidget.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    // QMainWindow window;
    QFieldWidget f;

    f.life->setCell(0, 0, true);
    f.life->setCell(0, 1, true);
    f.life->setCell(0, 2, true);
    f.life->setCell(2, 1, true);
    f.life->setCell(1, 2, true);

    // window.show();
     f.show();
     f.start();

     // for (int i = 1; i <= 100000000; i++) {
     Config::getConfig()->fwProp->setStepInterval(50);
     // }

    // Config* tmp = Config::getConfig();
    // tmp->test = "new foo";
    // Config::setConfig(tmp);

    // qDebug() << Config::getConfig()->test << endl;
    // int N = 20000;
    // while (N-->0) {
    //     for (int i = 0; i < 10; ++i) {
    //         for (int j = 0; j < 10; ++j) {
    //             cout << (life.getCell(i, j) ? '0' : '.');
    //         }
    //         cout << endl;
    //     }
    //     system("read");
        
    //     life.step();
    // }


    return app.exec();
}
