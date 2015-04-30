// Copyright 2015 Belkin Dmitriy
#include "config.h"

Config* Config::_conf = nullptr;
QMutex Config::mutex;

Config* Config::getConfig() {
    if (_conf == nullptr) {
        _conf = new Config();
    }
    return _conf;
}

void Config::setConfig(Config* conf) {
    Config::mutex.lock();

    if (conf == nullptr) {
        // user try to set null config =)
    }
    // TODO do copy of conf
    _conf = conf;
    Config::mutex.unlock();
}

Config::Config() {
    /* TODO: Init field */ 
    fwProp = QSharedPointer<FieldWidgetProperty>(
        new FieldWidgetProperty());
    // fwProp->setFieldSize(QSize(5,5));
    // fwProp->setCellWidth(10);
}
Config::~Config() { 
    // delete _conf;
    _conf = nullptr;
}
