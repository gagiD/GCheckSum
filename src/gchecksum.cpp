#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QScrollArea>

#include <QPalette>

#include "gchecksum.h"
#include "gsumwidget.h"
#include "ui_gchecksum.h"

GCheckSum::GCheckSum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GCheckSum)
{
    ui->setupUi(this);

    sumContLay = new QVBoxLayout;
    sumCont = new QWidget;
    scrollCont = new QScrollArea;
    sumCont->setLayout(sumContLay);
    scrollCont->setWidget(sumCont);
    scrollCont->setWidgetResizable(true);

    ui->verticalLayout->addWidget(scrollCont);

    sum = cksum = md5 = sha1 = sha224 = sha256 = sha384 = sha512 = 0;

}

GCheckSum::~GCheckSum() {
    delete ui;
}

void GCheckSum::on_fileSelect_clicked() {
    filePath = QFileDialog::getOpenFileName(this, tr("Select file for CheckSum"), QDir::homePath());

    ui->fileSelectLabel->setText(filePath);
}

void GCheckSum::on_calculateSum_clicked() {
    if (filePath.isEmpty()) {
        QMessageBox err(this);
        err.setIcon(QMessageBox::Warning);
        err.setText(tr("No file selected"));
        err.exec();
    } else {
        delete sum; delete cksum; delete md5; delete sha1; delete sha224; delete sha256; delete sha384; delete sha512;
        sum = cksum = md5 = sha1 = sha224 = sha256 = sha384 = sha512 = 0;

        if (ui->sumCheck->isChecked()) {
            sum = new GSumWidget("sum", filePath);
            sumContLay->addWidget(sum);
        }
        if (ui->cksumCheck->isChecked()) {
            cksum = new GSumWidget("cksum", filePath);
            sumContLay->addWidget(cksum);
        }
        if (ui->md5Check->isChecked()) {
            md5 = new GSumWidget("md5sum", filePath);
            sumContLay->addWidget(md5);
        }
        if (ui->sha1Check->isChecked()) {
            sha1 = new GSumWidget("sha1sum", filePath);
            sumContLay->addWidget(sha1);
        }
        if (ui->sha224Check->isChecked()) {
            sha224 = new GSumWidget("sha224sum", filePath);
            sumContLay->addWidget(sha224);
        }
        if (ui->sha256Check->isChecked()) {
            sha256 = new GSumWidget("sha256sum", filePath);
            sumContLay->addWidget(sha256);
        }
        if (ui->sha384Check->isChecked()) {
            sha384 = new GSumWidget("sha384sum", filePath);
            sumContLay->addWidget(sha384);
        }
        if (ui->sha512Check->isChecked()) {
            sha512 = new GSumWidget("sha512sum", filePath);
            sumContLay->addWidget(sha512);
        }
    }
}
