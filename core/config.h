// Copyright 2015 Belkin Dmitriy
#ifndef CONFIG_H
#define CONFIG_H

#include <QSize>
#include <QString>
#include <QMutex>

#include "../gui/interfaces.cpp"

// TODO: test QMutex :)

class Config: public IFieldWidgetProperty {
 public:
    static Config* getConfig();
    static void setConfig(Config* conf);

    int cellWidth() { return _cellWidth; }
    QSize fieldSize() { return _fieldSize; }

    void set_cellWidth(int cellWidth) {
        _cellWidth = cellWidth;
        emit cellWidthChanged(cellWidth);
    }

    void set_fieldSize(QSize fieldSize) {
        _fieldSize = fieldSize;
        emit fieldSizeChanged(fieldSize);
    }

 private:
    Config();

    static Config* _conf;
    static QMutex mutex;

    int _cellWidth;
    QSize _fieldSize;
};

#endif
