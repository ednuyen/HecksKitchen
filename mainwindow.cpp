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

    homePage = new QWidget();
    homePage->setParent(this);

    buttons = new QGridLayout(homePage); // does this set parent?? i think yes
    choose_difficulty = new QSlider();
    choose_difficulty->setRange(1,3);

    startButton = new QPushButton(homePage);
    QPixmap startPix(":/play.png");
    startPix = startPix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    startButton->setIcon(startPix);
    startButton->setIconSize(startPix.rect().size());
    startButton->setFixedSize(startPix.rect().size());

    exitButton = new QPushButton(homePage);
    QPixmap leavePix(":/exit.png");
    leavePix = leavePix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    exitButton->setIcon(leavePix);
    exitButton->setIconSize(leavePix.rect().size());
    exitButton->setFixedSize(leavePix.rect().size());

    instrctnsButton = new QPushButton(homePage);
    QPixmap instPix(":/training.png");
    instPix = instPix.scaled(275, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    instrctnsButton->setIcon(instPix);
    instrctnsButton->setIconSize(instPix.rect().size());
    instrctnsButton->setFixedSize(instPix.rect().size());

    QSpacerItem* top = new QSpacerItem(100, 220, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* bottom = new QSpacerItem(100, 120, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* right = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* middle = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
    buttons->addItem(top, 1, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(bottom, 5, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(middle, 2, 3, 3, 3, Qt::AlignCenter);
    buttons->addItem(right, 3, 4, 3, 3, Qt::AlignCenter);
    buttons->addWidget(choose_difficulty, 2, 2, 3, 1, Qt::AlignLeft);
    buttons->addWidget(startButton, 2, 5, Qt::AlignCenter);
    buttons->addWidget(instrctnsButton, 3, 5, Qt::AlignCenter);
    buttons->addWidget(exitButton, 4, 5, Qt::AlignCenter);

    connect(choose_difficulty, &QSlider::sliderMoved,this, &MainWindow::set_challenge_rating);
    connect(exitButton,&QPushButton::pressed, this, &MainWindow::pressedExit);

    QLabel* instructionsPage = new QLabel(homePage);
    QPixmap instructPix(":/instructions.png");
    instructPix = instructPix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    instructionsPage->setPixmap(instructPix);
    QPushButton *backToHome = new QPushButton(instructionsPage); // 'back to home' button on instructions page
    QPixmap homePix(":/home.png");
    homePix = homePix.scaled(100, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome->setIcon(homePix);
    backToHome->setIconSize(homePix.rect().size());
    backToHome->setFixedSize(homePix.rect().size());

    /* FOR REFERENCE
     * color of the yellow background: rgb(255,223,130)
     * color of the brown text: rgb(93,63,55)
    */
    QVBoxLayout *instrctnsLayout = new QVBoxLayout(instructionsPage);
    QSpacerItem* space = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrctnsLayout->addItem(space);
    instrctnsLayout->addWidget(backToHome, 0, Qt::AlignRight);

    stackedWidget = new QStackedWidget(this); // 'this' sets parent to be MainWindow...i think
    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(instructionsPage);

    this->setCentralWidget(stackedWidget);

    connect(instrctnsButton,&QPushButton::pressed, this, &MainWindow::goToPage2);
    connect(backToHome,&QPushButton::pressed, this, &MainWindow::goToPage1);
}

//make this a secondwindow*
void MainWindow::setPartner(SecondWindow* partner) {
    if (partner == 0)
        return;
    if (mPartner != partner) {
        if(mPartner != 0) {
            disconnect(startButton, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(startButton, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
        mPartner = partner;
        connect(startButton, SIGNAL(clicked()), this, SLOT(hide()));
        connect(startButton, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
    }

void MainWindow::set_challenge_rating(int a){
    difficulty_level = a;
    this->mPartner->set_challenge_rating_w2(a);
    this->mPartner->customer_setup();
    return;
}

MainWindow::~MainWindow() {}

void MainWindow::pressedExit() {
    MainWindow::close();
}

void MainWindow::goToPage2() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::goToPage1() {
    stackedWidget->setCurrentIndex(0);
}
