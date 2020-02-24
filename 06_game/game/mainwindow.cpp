#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小及标题
    this->setFixedSize(320, 588);
    this->setWindowTitle("翻金币主场景");
    //信号量，设置点击菜单栏 退出 则退出
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });
    //初始化一个游戏选择窗口
    this->selectScene = new SelectScene();
    //初始化开始按钮
    MyPushButton* startButton = new MyPushButton(":/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(QPoint(this->width()*0.5-startButton->width()*0.5,this->height()*0.7));
    //表示开始弹起的动画，并将画面转为游戏选择画面
    connect(startButton, &MyPushButton::clicked, [=](){
        startButton->zoom1();
        startButton->zoom2();
        QTimer::singleShot(600, this, [=](){
            this->hide();
            selectScene->show();
        });
    });

    connect(this->selectScene, &SelectScene::backMainSig, [=](){
       this->show();
    });
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
