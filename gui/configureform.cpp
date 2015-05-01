#include "configureform.h"
#include "ui_configureform.h"
#include "../core/config.h"

ConfigureForm::ConfigureForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigureForm)
{
    ui->setupUi(this);

    loadConfigur();

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(saveConfig()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SIGNAL(gameStateToggled()));
}

void ConfigureForm::saveConfig() {
    Config::getConfig()->fwProp.data()->setCellWidth(ui->sbCellWidth->value());
    Config::getConfig()->fwProp.data()->setFieldSize(
                QSize(ui->sbWidth->value(),ui->sbHeight->value()));
    Config::getConfig()->fwProp.data()->setStepInterval(ui->sbInterval->value());
    Config::getConfig()->fwProp.data()->setIsDrawBorders(ui->checkBox->isChecked());
}

void ConfigureForm::loadConfigur() {
    ui->sbInterval->setValue(Config::getConfig()->fwProp.data()->stepInterval());
    ui->sbCellWidth->setValue(Config::getConfig()->fwProp.data()->cellWidth());

    int w,h;
    w = Config::getConfig()->fwProp.data()->fieldSize().width();
    h = Config::getConfig()->fwProp.data()->fieldSize().height();

    ui->sbWidth->setValue(w);
    ui->sbHeight->setValue(h);

    ui->checkBox->setChecked(Config::getConfig()->fwProp.data()->isDrawBorders());
}

ConfigureForm::~ConfigureForm()
{
    delete ui;
}

void ConfigureForm::on_pushButton_2_clicked()
{
    if(_lifeState) {
        _lifeState = false;
        ui->pushButton_2->setText("stop");
    } else {
        _lifeState = true;
        ui->pushButton_2->setText("start");
    }

    emit Config::getConfig()->fwProp.data()->gameStateToggled();
}
