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
    /*! Clicking the start button will maximize the partner window and minimize the current window.
     * @param partner : the window to maximize, the game screen */
    void setPartner(SecondWindow* partner);

public slots:
    /*! Called in response to signal emitted when "EXIT" button is pressed.
     * Quits the application. */
    void pressedExit();

    /*! Called in response to signal emitted when "PLAY" button is pressed.
     * Calls start_timer() in SecondWindow to start timer when player starts playing. */
    void start_timer();

    /*! Called in response to signal emitted when "TRAINING" button is pressed
     *  Changes the index of stackedWidget to 1, showing the instructions page */
    void openTraining();

    /*! Called in response to signal emitted when "BACK" button is pressed
     *  Changes the index of stackedWidget to 0, showing the home page */
    void closeTraining();

    /*! Called in response to choose_difficulty QSlider being moved
     *  Tells game window what the difficulty level is, resets game whenever slider is moved
     *  @param level : the slider value, range of 1 to 3  */
    void set_difficulty_level(const int& level);

private:
    QWidget* homePage;
    qreal difficulty_level = 1;
    QSlider* choose_difficulty;
    QPushButton* startButton; // "PLAY"
    QPushButton* exitButton; // "EXIT"
    QPushButton* instrctnsButton; // "TRAINING"
    QGridLayout* buttons; // layout of PLAY, TRAINING, and EXIT
    QStackedWidget* stackedWidget; // has two widgets, the home page and instructions page
    SecondWindow* mPartner; // Game Page
};

#endif // MAINWINDOW_H
