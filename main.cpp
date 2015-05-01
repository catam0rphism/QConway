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
    ConfigureForm conf;
    QFieldWidget f(Config::getConfig()->fwProp.data(), *conf);

    f.life->setCell(0, 0, true);
    f.life->setCell(0, 1, true);
    f.life->setCell(0, 2, true);
    f.life->setCell(2, 1, true);
    f.life->setCell(1, 2, true);


    f.show();
    f.start();

//    conf.show();

    return app.exec();
}
