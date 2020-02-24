#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QString>
#include "mypushbutton.h"

#define SELECTNUM 20
#define SELECTSPACE 70

class SelectScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit SelectScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
    void backMainSig();
public slots:
};

#endif // SELECTSCENE_H
