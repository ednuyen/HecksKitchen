#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(875,700);
    move(300,50);

    QPixmap bkgnd(":/menu.png"); // Home page image
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    homePage = new QWidget();
    homePage->setParent(this);

    buttons = new QGridLayout(homePage); // layout of PLAY, TRAINING, and EXIT buttons
    choose_difficulty = new QSlider;
    choose_difficulty->setRange(1,3); // easy(1), medium(2), hard(3)
    choose_difficulty->setFixedHeight(225);

    startButton = new QPushButton;
    QPixmap startPix(":/play.png");
    startPix = startPix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    startButton->setIcon(startPix);
    startButton->setIconSize(startPix.rect().size());
    startButton->setFixedSize(startPix.rect().size());

    exitButton = new QPushButton;
    QPixmap leavePix(":/exit.png");
    leavePix = leavePix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    exitButton->setIcon(leavePix);
    exitButton->setIconSize(leavePix.rect().size());
    exitButton->setFixedSize(leavePix.rect().size());

    instrctnsButton = new QPushButton;
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

    connect(choose_difficulty, &QSlider::sliderMoved, this, &MainWindow::set_difficulty_level);
    connect(exitButton, &QPushButton::pressed, this, &MainWindow::pressedExit);
    connect(startButton, &QPushButton::pressed, this, &MainWindow::start_timer);

    QLabel* instructionsPage = new QLabel(this);
    QPixmap instructPix(":/instructions.png");
    instructPix = instructPix.scaled(875,700, Qt::KeepAspectRatio, Qt::FastTransformation);
    instructionsPage->setPixmap(instructPix);
    QPushButton *backToHome = new QPushButton(instructionsPage); // 'BACK' button on instructions page
    QPixmap homePix(":/back.png");
    homePix = homePix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome->setIcon(homePix);
    backToHome->setIconSize(homePix.rect().size());
    backToHome->setFixedSize(homePix.rect().size());

    QVBoxLayout *instrctnsLayout = new QVBoxLayout(instructionsPage);
    QSpacerItem* space = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrctnsLayout->addItem(space);
    instrctnsLayout->addWidget(backToHome, 0, Qt::AlignCenter);

    connect(instrctnsButton,&QPushButton::pressed, this, &MainWindow::openTraining);
    connect(backToHome,&QPushButton::pressed, this, &MainWindow::closeTraining);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(instructionsPage);

    this->setCentralWidget(stackedWidget);
}

void MainWindow::setPartner(SecondWindow* partner) {
    mPartner = partner;
    connect(startButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(startButton, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
}

void MainWindow::set_difficulty_level(const int& level){
    difficulty_level = level;
    this->mPartner->set_difficulty_level_w2(level);
    this->mPartner->reset_game();
    return;
}

void MainWindow::start_timer() {
    mPartner->start_timer();
}

MainWindow::~MainWindow() {}

void MainWindow::pressedExit() {
    MainWindow::close();
}

void MainWindow::openTraining() {
    stackedWidget->setCurrentIndex(1); // index 1 is instructions page
}

void MainWindow::closeTraining() {
    stackedWidget->setCurrentIndex(0); // index 0 is home page
}
