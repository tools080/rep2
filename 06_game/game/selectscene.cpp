#include "selectscene.h"

SelectScene::SelectScene(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口大小及标题
    this->setFixedSize(320, 588);
    this->setWindowTitle("选择关卡");

    QMenuBar* menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);
    QMenu* startFile = menuBar->addMenu("开始");
    QAction* back = startFile->addAction("退出");
    connect(back, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton* backMain = new MyPushButton(":/BackButton.png", ":/BackButtonSelected.png");
    backMain->setParent(this);
    backMain->move(this->width() - backMain->width(), this->height() - backMain->height());
    connect(backMain, &MyPushButton::clicked, [=](){
        this->hide();
        emit backMainSig();
    });

    for(int i = 0; i < SELECTNUM; i++)
    {
        MyPushButton* selectBtn = new MyPushButton(":/LevelIcon.png");
        selectBtn->setParent(this);
        selectBtn->move(25 + (i % 4) * SELECTSPACE, 130 + (i / 4) * SELECTSPACE);

        QLabel* selectLable = new QLabel(this);
        selectLable->setFixedSize(selectBtn->width(),selectBtn->height());
        selectLable->setText(QString::number(i + 1)); //
        selectLable->setAlignment(Qt::AlignHCenter);
        selectLable->move(25 + (i % 4) * SELECTSPACE, 152 + (i / 4) * SELECTSPACE);
        selectLable->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    }
}

void SelectScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/Title.png");
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
