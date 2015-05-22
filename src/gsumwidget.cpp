#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QProcess>

#include "gsumwidget.h"

GSumWidget::GSumWidget(QString title, QString file, QWidget *parent) :
    QGroupBox(parent)
{
    setTitle(title);
    setMinimumHeight(130);

    QProcess calSum;
    calSum.start(title, QStringList() << file);
    while (calSum.waitForReadyRead()) {
        const QByteArray tmp = calSum.readAllStandardOutput();
        sum = tmp;
    }
    sum.remove(sum.indexOf(' '), sum.length());

    sumLabel = new QLabel(title);
    cmpLabel = new QLabel(tr("Compare with"));
    isSame = new QLabel;
    isSame->setPixmap(QPixmap(":/img/img/no.png"));

    sumEdit = new QLineEdit(sum);
    sumEdit->setReadOnly(true);
    cmpEdit = new QLineEdit();

    layout = new QGridLayout;

    layout->addWidget(sumLabel, 0,0);
    layout->addWidget(sumEdit, 0,1);
    layout->addWidget(cmpLabel, 1,0);
    layout->addWidget(cmpEdit, 1,1);
    layout->addWidget(isSame, 1,2);

    setLayout(layout);

    connect(cmpEdit, SIGNAL(textChanged(QString)), this, SLOT(compareSum(QString)));
}

void GSumWidget::compareSum(QString cSum) {
    if (sum == cSum)
        isSame->setPixmap(QPixmap(":/img/img/yes.png"));
    else
        isSame->setPixmap(QPixmap(":/img/img/no.png"));
}
