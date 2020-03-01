#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(875,700);

    QPixmap bkgnd(":/menu.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QWidget* homePage = new QWidget();
    buttons = new QGridLayout(homePage);
    challenge = new QSlider();
    challenge->setRange(1,3);
    start = new QPushButton();

    QPixmap startPix(":/play.png");
    startPix = startPix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon startIcon(startPix);
    start->setIcon(startIcon);
    start->setIconSize(startPix.rect().size());
    start->setFixedSize(startPix.rect().size());

    leave = new QPushButton();
    QPixmap leavePix(":/exit.png");
    leavePix = leavePix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon leaveIcon(leavePix);
    leave->setIcon(leavePix);
    leave->setIconSize(leavePix.rect().size());
    leave->setFixedSize(leavePix.rect().size());

    instructions = new QPushButton();
    QPixmap instPix(":/training.png");
    instPix = instPix.scaled(275, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon instIcon(instPix);
    instructions->setIcon(instIcon);
    instructions->setIconSize(instPix.rect().size());
    instructions->setFixedSize(instPix.rect().size());

    QSpacerItem* top = new QSpacerItem(100, 220, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* bottom = new QSpacerItem(100, 120, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* right = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* middle = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
    connect(leave,&QPushButton::pressed, this, &MainWindow::pressedExit);
    buttons->addItem(top, 1, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(bottom, 5, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(middle, 2, 3, 3, 3, Qt::AlignCenter);
    buttons->addItem(right, 3, 4, 3, 3, Qt::AlignCenter);
    buttons->addWidget(challenge, 2, 2, 3, 1, Qt::AlignLeft);
    buttons->addWidget(start, 2, 5, Qt::AlignCenter);
    buttons->addWidget(instructions, 3, 5, Qt::AlignCenter);
    buttons->addWidget(leave, 4, 5, Qt::AlignCenter);
    connect(challenge, &QSlider::sliderMoved,this, &MainWindow::set_challenge_rating);


    QLabel* instructionsPage = new QLabel;
    QPixmap instructPix(":/instructions.png");
    instructPix = instructPix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    instructionsPage->setPixmap(instructPix);
    QPushButton *backToHome = new QPushButton("BACK");
    backToHome = new QPushButton;
    QPixmap homePix(":/home.png");
    homePix = homePix.scaled(100, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon homeIcon(homePix);
    backToHome->setIcon(homeIcon);
    backToHome->setIconSize(homePix.rect().size());
    backToHome->setFixedSize(homePix.rect().size());

    /* FOR REFERENCE
     * color of the yellow background: rgb(255,223,130)
     * color of the brown text: rgb(93,63,55)
    */
    QVBoxLayout *textLayout = new QVBoxLayout(instructionsPage);
    QSpacerItem* space = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    textLayout->addItem(space);
    textLayout->addWidget(backToHome, 0, Qt::AlignRight);

    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(homePage);
    _stackedWidget->addWidget(instructionsPage);

    QVBoxLayout *centrallayout = new QVBoxLayout;
    centrallayout->addWidget(_stackedWidget);
    this->setCentralWidget(_stackedWidget);
    connect(instructions,&QPushButton::pressed, this, &MainWindow::goToPage2);
    connect(backToHome,&QPushButton::pressed, this, &MainWindow::goToPage1);
}

//make this a secondwindow*
void MainWindow::setPartner(SecondWindow* partner) {
    if (partner == 0)
        return;
    if (mPartner != partner) {
        if(mPartner != 0) {
            disconnect(start, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(start, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
        mPartner = partner;
        connect(start, SIGNAL(clicked()), this, SLOT(hide()));
        connect(start, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
    }

void MainWindow::set_challenge_rating(int a){
    challenge_rating = a;
    this->mPartner->set_challenge_rating_w2(a);
    this->mPartner->board_setup();
    return;}

MainWindow::~MainWindow() {}

void MainWindow::pressedExit() {
    MainWindow::close();
    w2.close();
}

void MainWindow::goToPage2() {
    _stackedWidget->setCurrentIndex(1);
}

void MainWindow::goToPage1() {
    _stackedWidget->setCurrentIndex(0);
}
