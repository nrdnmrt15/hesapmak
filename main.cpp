#include <QApplication>
#include <QPushButton>
#include "hesap.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    hesap w;
    w.show();

    return QApplication::exec();
}
