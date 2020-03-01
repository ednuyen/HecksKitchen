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


public slots:
    void goToPage1();
    void goToPage2();
    void set_challenge_rating(int a);

private:
    int challenge_rating =1;
    QSlider* challenge;
    QPushButton* start;
    QPushButton* leave;
    QPushButton* instructions;
    QGridLayout* buttons;
    SecondWindow w2;
    QStackedWidget* _stackedWidget;
    SecondWindow* mPartner;
};

#endif // MAINWINDOW_H
