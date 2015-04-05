// Copyright 2015 Belkin Dmitriy
#ifndef CONFIG_H
#define CONFIG_H

#include <QSize>
#include <QString>
#include <QMutex>

// TODO: test QMutex :)

class Config {
 public:
    static Config* getConfig();
    static void setConfig(Config* conf);

    QSize fieldSize;
    QString test;


 private:
    Config();

    static Config* _conf;
    static QMutex mutex;
};

#endif
