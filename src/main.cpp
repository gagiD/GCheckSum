#include <QApplication>
#include <QDesktopWidget>

#include "gchecksum.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GCheckSum w;
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();

    return a.exec();
}
