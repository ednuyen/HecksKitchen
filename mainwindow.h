#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QPixmap>
#include "secondwindow.h"

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pressedExit();
    void setPartner(SecondWindow* partner);
    void start_timer();

public slots:
    void goToPage1();
    void goToPage2();
    void set_challenge_rating(int a);

private:
    QLabel* timeLabel;
    QTime time;
    QTimer timer;

    QWidget* homePage;
    qreal difficulty_level = 1; // !! not a pointer. will have to delete at some point? no bc this is on the stack...WHAT
    QSlider* choose_difficulty;
    QPushButton* startButton; // "PLAY"
    QPushButton* exitButton; // "EXIT"
    QPushButton* instrctnsButton; // "TRAINING"
    QGridLayout* buttons; // layout of PLAY, TRAINING, and EXIT
    QStackedWidget* stackedWidget; // has two widgets, the home page and instructions page
    SecondWindow* mPartner; // the game page
};

#endif // MAINWINDOW_H
