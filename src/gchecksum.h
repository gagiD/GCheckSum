#ifndef GCHECKSUM_H
#define GCHECKSUM_H

#include <QWidget>

namespace Ui {
class GCheckSum;
}

class QVBoxLayout;
class GSumWidget;
class QScrollArea;

class GCheckSum : public QWidget {
    Q_OBJECT

    QString filePath;

    QVBoxLayout* sumContLay;
    QWidget* sumCont;
    QScrollArea* scrollCont;

    GSumWidget *sum, *cksum, *md5, *sha1, *sha224,  *sha256,  *sha384,  *sha512;

public:
    explicit GCheckSum(QWidget *parent = 0);
    ~GCheckSum();

private slots:
    void on_fileSelect_clicked();

    void on_calculateSum_clicked();

private:
    Ui::GCheckSum *ui;
};

#endif // GCHECKSUM_H
