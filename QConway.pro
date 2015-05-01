QT += core gui widgets

TEMPLATE = app
TARGET = QConway

QMAKE_CXXFLAGS += -std=c++1y

HEADERS += core/config.h \
	core/life.h \
    gui/qfieldWidget.h \
    gui/fieldwidgetproperty.h \
    gui/configureform.h

SOURCES += main.cpp \
	core/config.cpp \
	core/life.cpp \
    gui/qfieldWidget.cpp \
    gui/fieldwidgetproperty.cpp \
    gui/configureform.cpp
	

FORMS += \
    gui/configureform.ui
