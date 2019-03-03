#include "actionhistorymdi.h"
#include "ui_actionhistorymdi.h"

ActionHistoryMDI::ActionHistoryMDI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ActionHistoryMDI)
{
    ui->setupUi(this);

}

void ActionHistoryMDI::addItem(QString *text) // Never gets called for some reasion
{
    ui->listWidget->addItem("uwu");
    ui->listWidget->addItem(QString("%1").arg(text->unicode(),0,16));
}

ActionHistoryMDI::~ActionHistoryMDI()
{
    delete ui;
}
