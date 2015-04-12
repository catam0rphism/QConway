QT += core gui widgets

TEMPLATE = app
TARGET = QConway

QMAKE_CXXFLAGS += -std=c++1y

HEADERS += core/config.h \
	core/life.h \
    gui/fieldWidget.h

SOURCES += main.cpp \
	core/config.cpp \
	core/life.cpp
	