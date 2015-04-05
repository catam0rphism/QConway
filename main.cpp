// Copyright 2015 Belkin Dmitriy
#include <QApplication>
#include <QDebug>

#include "config.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Config* tmp = Config::getConfig();
    tmp->test = "new foo";
    Config::setConfig(tmp);

    qDebug() << Config::getConfig()->test;

    return app.exec();
}
