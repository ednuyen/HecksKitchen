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
    void pressedPlay();
    void pressedExit();
    void setPartner(QWidget* partner);

public slots:
    void goToPage1();
    void goToPage2();

private:
    bool music_mute = true;
    QLabel* title;
    QLabel* challenge_level;
    QSlider* challenge;
    QPushButton* start;
    QPushButton* leave;
    QPushButton* instructions;
    QGridLayout* buttons;
    SecondWindow w2;
    QStackedWidget* _stackedWidget;
    QWidget* firstPage;
    QHBoxLayout* firstPageLayout;
    QWidget* mPartner;
};

#endif // MAINWINDOW_H
