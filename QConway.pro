QT += core gui widgets

TEMPLATE = app
TARGET = QConway

QMAKE_CXXFLAGS += -std=c++1y

HEADERS += core/config.h \
	core/life.h \
    gui/qfieldWidget.h

SOURCES += main.cpp \
	core/config.cpp \
	core/life.cpp \
    gui/qfieldWidget.cpp
	