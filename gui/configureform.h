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

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ConfigureForm *ui;
    bool _lifeState = false;
};

#endif // CONFIGUREFORM_H
