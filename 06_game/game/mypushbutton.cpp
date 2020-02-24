#include "mypushbutton.h"

//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton::MyPushButton(QString pix1, QString pix2)
{
    this->pix1 = pix1;
    this->pix2 = pix2;

    QPixmap pix;
    pix.load(pix1);

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(pix2 != "")
    {
        QPixmap pix;
        int ret = pix.load(pix2);
        if(!ret)
        {
            qDebug()<<"error";
            return;
        }
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(pix2 != "")
    {
        QPixmap pix;
        int ret = pix.load(pix1);
        if(!ret)
        {
            qDebug()<<"error";
            return;
        }
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}

void MyPushButton::zoom1()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    return;
}
void MyPushButton::zoom2()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    return;
}
