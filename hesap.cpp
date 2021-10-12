#include "hesap.h"
    #include "ui_hesap.h"
    #include <QtGui>
    #include <QtCore>
double birinci;
bool user_is_typing_secondNumber=false;
hesap::hesap(QWidget *parent) : QWidget(parent),
      ui(new Ui::hesap) {
    ui->setupUi(this);

//ui->ekran.clear();
    connect(ui->buton0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->buton9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->isaret,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->carpma,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->toplama,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->ckarma,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->bolme,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->toplama->setCheckable(true);
    ui->ckarma->setCheckable(true);
    ui->bolme->setCheckable(true);
    ui->carpma->setCheckable(true);

}

hesap::~hesap() {
    delete ui; }

void hesap::digit_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    QString input;
    double ekransay;

    if((ui->toplama->isChecked() || ui->bolme->isChecked() ||
    ui->ckarma->isChecked() || ui->carpma->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        ekransay = button->text().toDouble();
        input = QString::number(ekransay,'g',15);
    }

    else
    {
        if(ui->ekran->text().contains(".") && button->text() == "0")
        {
            input=ui->ekran->text() + button->text();
        }
        else
        {
            ekransay = (ui->ekran->text() + button->text()).toDouble();
            input = QString::number(ekransay,'g',15);
        }
    }
    ui->ekran->setText(input);

}

void hesap::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double ekransay;
    QString input;

    if(button->text() == "+/-")
    {
        ekransay = (ui->ekran->text()).toDouble();
        ekransay *= -1;
        input = QString::number(ekransay,'g',15);
        ui->ekran->setText(input);
    }
    else {}
}

void hesap::on_temizle_released()
{
    ui->toplama->setChecked(false);
    ui->ckarma->setChecked(false);
    ui->carpma->setChecked(false);
    ui->bolme->setChecked(false);
    user_is_typing_secondNumber=false;

    ui->ekran->setText("0");
}

void hesap::on_equal_released()
{
    double ekransay,ikinci;
    QString input;
    ekransay=0;

    ikinci = ui->ekran->text().toDouble();

    if(ui->toplama->isChecked())
    {
        ekransay = birinci + ikinci;
        ui->toplama->setChecked(false);
    }

    else if(ui->ckarma->isChecked())
    {
        ekransay = birinci - ikinci;
        ui->ckarma->setChecked(false);
    }

    else if(ui->carpma->isChecked())
    {
        ekransay = birinci * ikinci;
        ui->carpma->setChecked(false);
    }

    else if(ui->bolme->isChecked())
    {
        ekransay = birinci / ikinci;
        ui->bolme->setChecked(false);
    }

    input = QString::number(ekransay,'g',15);
    ui->ekran->setText(input);

    user_is_typing_secondNumber=false;
}

void hesap::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    birinci = ui->ekran->text().toDouble();
    button->setChecked(true);

}
