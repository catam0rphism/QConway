#include <QSize>
#include <QColor>

class IFieldWidgetProperty {
    Q_OBJECT

 public:
    virtual QSize cellSize;
    virtual QSize fieldSize;

 public signals:
    void cellSizeChanged(QSize size);

};