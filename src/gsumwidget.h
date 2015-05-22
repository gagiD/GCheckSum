#ifndef GSUMWIDGET_H
#define GSUMWIDGET_H

#include <QGroupBox>

class QLabel;
class QGridLayout;
class QLineEdit;

class GSumWidget : public QGroupBox
{
    Q_OBJECT

    QGridLayout* layout;
    QLabel* sumLabel;
    QLabel* cmpLabel;
    QLabel* isSame;
    QLineEdit *sumEdit;
    QLineEdit *cmpEdit;

    QString sum;
public:
    explicit GSumWidget(QString title, QString file, QWidget *parent = 0);

signals:

public slots:
    void compareSum(QString);

};

#endif // GSUMWIDGET_H
