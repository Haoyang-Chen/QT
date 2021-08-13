#include "selectdialog.h"
#include "ui_selectdialog.h"
#include <QButtonGroup>

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);
    RadioGroup = new QButtonGroup(this);
    RadioGroup->addButton(ui->radioGreater);
    RadioGroup->addButton(ui->radioEqual);
    RadioGroup->addButton(ui->radioLower);
    m_iSelectIndex = 0;
    m_iRadioID = 0;
}

SelectDialog::~SelectDialog()
{
    delete ui;
    delete RadioGroup;
}

float SelectDialog::GetValue()
{
    QString strValue = ui->lineEditSelectedValue->text();
    float fValue = strValue.toFloat();
    return fValue;
}

void SelectDialog::on_comboSpecialItem_currentIndexChanged(const QString &arg1)
{
    if(arg1=="身高")
    {
        m_iSelectIndex = 0;
        ui->label_unit->setText("厘米");
    }

    if(arg1=="体重")
    {
        m_iSelectIndex = 1;
        ui->label_unit->setText("千克");
    }
}

void SelectDialog::on_radioGreater_clicked()
{
    m_iRadioID = 0; //高于
}

void SelectDialog::on_radioEqual_clicked()
{
    m_iRadioID = 1;//等于
}

void SelectDialog::on_radioLower_clicked()
{
    m_iRadioID = 2;//低于
}
