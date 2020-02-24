#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QPropertyAnimation>
#include <QTimer>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString, QString = "");
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void zoom1();
    void zoom2();

protected:
    QString pix1;
    QString pix2;


signals:

public slots:
};

#endif // MYPUSHBUTTON_H
