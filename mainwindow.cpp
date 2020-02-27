#include "mainwindow.h"

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
//    connect(start, &QPushButton::pressed, this,&MainWindow::pressedPlay);
    connect(leave,&QPushButton::pressed, this, &MainWindow::pressedExit);
    buttons->addItem(top, 1, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(bottom, 5, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(middle, 2, 3, 3, 3, Qt::AlignCenter);
    buttons->addItem(right, 3, 4, 3, 3, Qt::AlignCenter);
    buttons->addWidget(challenge, 2, 2, 3, 1, Qt::AlignLeft);
    buttons->addWidget(start, 2, 5, Qt::AlignCenter);
    buttons->addWidget(instructions, 3, 5, Qt::AlignCenter);
    buttons->addWidget(leave, 4, 5, Qt::AlignCenter);

//    this->setCentralWidget(homePage);

    QWidget *instructionPage = new QWidget();
    instructionPage->setStyleSheet("background-image: url(:/background.png)");
    QLabel *title = new QLabel("HOW TO PLAY");
    title->setStyleSheet("QLabel { color : black; font: 20pt; font-weight: bold; }");
    title->setAlignment(Qt::AlignCenter);
    QLabel *text = new QLabel("Use ARROW KEYS or WASD to move\n\nCLICK on customers' orders\n\n"
                              "Press SPACE to grab the right ingredients\n\nPress G to serve orders");
    text->setStyleSheet("QLabel { color : black; }");
    QPushButton *backToHome = new QPushButton("BACK");
    backToHome->setStyleSheet("QPushButton { background-color : white; color : black; }");
    QVBoxLayout *textLayout = new QVBoxLayout(instructionPage);
    textLayout->addWidget(title);
    textLayout->addWidget(text);
    textLayout->addWidget(backToHome);

    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(homePage);
    _stackedWidget->addWidget(instructionPage);

    QVBoxLayout *centrallayout = new QVBoxLayout;
    centrallayout->addWidget(_stackedWidget);
    this->setCentralWidget(_stackedWidget);
//    setLayout(centrallayout);
    connect(instructions,&QPushButton::pressed, this, &MainWindow::goToPage2);
    connect(backToHome,&QPushButton::pressed, this, &MainWindow::goToPage1);
}

void MainWindow::setPartner(QWidget* partner) {
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

MainWindow::~MainWindow() {}

void MainWindow::pressedPlay() {
//    w2.show();
}

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
