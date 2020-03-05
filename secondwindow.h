#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QMediaPlayer>
#include <QStackedWidget>
#include "health.h"
#include "player.h"
#include "bread_bin.h"
#include "cheese_bin.h"
#include "meat_bin.h"
#include "veggie_bin.h"
//#include "veggies.h"

class RecipeWindow;

class SecondWindow: public QWidget
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void decrease_health();
    void keyPressEvent(QKeyEvent *event);
    void setPartner(QWidget* partner);
    void setPartner2(RecipeWindow* partner);
    void play_music();
    void set_challenge_rating_w2(int);
    void customer_setup();

public slots:
    void customer_order1();
    void customer_order2();
    void customer_order3();
    void customer_order4();
    void customer_order5();
    void customer_order6();
    void customer_order7();
    void goToWin();
    void goToLose();
    void goToGamePage();
    void stop_music();
    void reset_game();
    void board_setup();
    void delete_game();

signals:

private:
    QLabel* text1;
    Health* player_health;
    QLabel* health_text;
    qreal health = 100;
    qreal people_served = 0;
    int challenge_number = 1;
    QGridLayout* play_space;
    QHBoxLayout* title_space;
    QGridLayout* sandwich_layout;
    QVBoxLayout* fullwindow;
    QVBoxLayout* menuLayout;
    Player* main_character;

    QMediaPlayer* music;

    int music_mute = 0;

    Bread_Bin* breadBin1;
    Bread_Bin* breadBin2;
    Bread_Bin* breadBin3;

    Cheese_Bin* cheeseBin1;
    Cheese_Bin* cheeseBin2;
    Cheese_Bin* cheeseBin3;

    Meat_Bin* meatBin1;
    Meat_Bin* meatBin2;
    Meat_Bin* meatBin3;

    Veggie_Bin* veggieBin1;
    Veggie_Bin* veggieBin2;
    Veggie_Bin* veggieBin3;

    Bin* trash;

    Player* customer1;
    QPushButton* order1;
    Player* customer2;
    QPushButton* order2;
    Player* customer3;
    QPushButton* order3;
    Player* customer4;
    QPushButton* order4;
    Player* customer5;
    QPushButton* order5;
    Player* customer6;
    QPushButton* order6;
    Player* customer7;
    QPushButton* order7;

    QWidget* secondPage;
    QWidget* menuPage;
    QWidget* youWinPage;
    QWidget* youLosePage;
    QWidget* mPartner;
    RecipeWindow* mPartner2;
    QPushButton* homeScreen;
    QPushButton* toRecipes;
    QPushButton *backToHome1;
    QPushButton *backToHome2;
    QStackedWidget* stackedWidget;
    QPushButton* mute;
};

class RecipeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeWindow(QWidget *parent = nullptr);
    ~RecipeWindow();
    void setPartner2(SecondWindow* partner);
signals:
public slots:
    void goForward();
    void goBack();
private:
    SecondWindow* mPartner2;
    QPushButton* toSecondW;
    QPushButton* recipeBack;
    QPushButton* recipeForward;
    QGridLayout* buttonLayout;
    int recipeCounter = 1;
    QPalette recipebkgnd;
};

#endif // SECONDWINDOW_H
