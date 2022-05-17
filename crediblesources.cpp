#include "crediblesources.h"
#include "ui_crediblesources.h"

credibleSources::credibleSources(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credibleSources)
{
    ui->setupUi(this);
}

credibleSources::~credibleSources()
{
    delete ui;
}
