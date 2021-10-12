//
// Created by nurdan on 8.10.2021.
//

#ifndef HESAPMAK_HESAP_H
#define HESAPMAK_HESAP_H

#include <QWidget>
#include <QLineEdit>
#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class hesap; }
QT_END_NAMESPACE

class hesap : public QWidget {
Q_OBJECT
public:
    hesap(QWidget *parent = nullptr);
    ~hesap();

private:
    Ui::hesap *ui;

private slots:
    void digit_pressed();
    void unary_operation_pressed();
    void on_temizle_released();
    void on_equal_released();
   void binary_operation_pressed();
};
#endif // HESAP_H*/
