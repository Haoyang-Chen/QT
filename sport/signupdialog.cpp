#include "signupdialog.h"
#include "ui_signupdialog.h"

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

QString SignupDialog::Name()
{
    return ui->textEditName->toPlainText();
}

int SignupDialog::Number()
{
    QString sNumber = ui->textEditNumber->toPlainText();
    int number = sNumber.toInt();
    return number;
}

QDate SignupDialog::BirthDate()
{
    return ui->dateEditBirth->date();
}

float SignupDialog::SportsmanHeight()
{
    QString sHeight = ui->textEditHigh->toPlainText();
    float height = sHeight.toFloat();
    return  height;
}

float SignupDialog::SportsmanWeight()
{
    QString sWeight = ui->textEditWeight->toPlainText();
    float weight = sWeight.toFloat();
    return weight;
}

