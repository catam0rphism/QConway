#ifndef CONFIGUREFORM_H
#define CONFIGUREFORM_H

#include <QWidget>

namespace Ui {
class ConfigureForm;
}

class ConfigureForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigureForm(QWidget *parent = 0);
    ~ConfigureForm();

    void loadConfigur();
public slots:
    void saveConfig();

signals:
    void gameStateToggled();

private:
    Ui::ConfigureForm *ui;
};

#endif // CONFIGUREFORM_H
