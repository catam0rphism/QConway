// Copyright 2015 Belkin Dmitriy
#include "config.h"

Config* Config::_conf = nullptr;
QMutex Config::mutex;

Config* Config::getConfig() {
    if (_conf == NULL) {
        _conf = new Config();
    }
    return _conf;
}

void Config::setConfig(Config* conf) {
    Config::mutex.lock();

    if (conf == NULL) {
        // user try to set null config =)
    }
    // TODO do copy of conf
    _conf = conf;
    Config::mutex.unlock();
}

Config::Config() {
    test = "foo";
}
