// Copyright 2015 Belkin Dmitriy
#ifndef CONFIG_H
#define CONFIG_H

#include <QSize>
#include <QString>
#include <QMutex>
#include <QSharedPointer>

#include "../gui/fieldwidgetproperty.h"

// TODO: test QMutex :)
class Config {
 public:
    static Config* getConfig();
    static void setConfig(Config* conf);

    QSharedPointer<FieldWidgetProperty> fwProp;

    ~Config();
 private:
    Config();

    static Config* _conf;
    static QMutex mutex;

    int _cellWidth;
    QSize _fieldSize;
};


#endif
