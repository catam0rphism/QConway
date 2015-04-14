#ifndef INTERFACES_CPP
#define INTERFACES_CPP

#include <QSize>
#include <QColor>

typedef QSize FieldSize;

class IFieldWidgetProperty {
    Q_OBJECT

 public:
    virtual int cellWidth() = 0;
    virtual void set_cellWidth(int cellWidth) = 0;

    virtual FieldSize fieldSize() = 0;
    virtual void set_fieldSize(FieldSize fieldSize) = 0;

 signals:
    void cellWidthChanged(int size);
    void fieldSizeChanged(FieldSize);
};


#endif // INTERFACES_CPP
