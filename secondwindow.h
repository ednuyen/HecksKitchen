#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include <QStackedWidget>

#include "player.h"
#include "food.h"
#include "bread_bin.h"
#include "cheese_bin.h"
#include "meat_bin.h"
#include "veggie_bin.h"
#include "puddle.h"
#include "fire.h"

class RecipeWindow;
class Lose;
class Win;

class SecondWindow: public QWidget
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void decrease_health();
    void keyPressEvent(QKeyEvent *event);
    void setPartner(QWidget* partner, RecipeWindow* partner2, Lose* partner3, Win* partner4);
    // recently added
    void setPartner2(RecipeWindow* partner);
    void set_challenge_rating_w2(int);
    void customer_setup();
    void faceRight(){ main_character->turnRight(); }
    void faceLeft(){ main_character->turnLeft(); }

    class Health : public QWidget {
    public:
        Health(QWidget *parent = nullptr);
        void paintEvent(QPaintEvent* e);
    //    QLabel get_health_text();
        void change_health_bar(int a);
        void reset_health();
    private:
        qreal health_value = 10;
    //    QLabel* health_text;
    };

public slots:
    void customer_order1();
    void customer_order2();
    void customer_order3();
    void customer_order4();
    void customer_order5();
    void customer_order6();
    void customer_order7();
    void goToGamePage();
    void stop_music();

    // recently added
    void reset_game();
    void begin_game();
    void delete_game();
    void loseConditionSatisfied() { actual_game_timer->stop(); emit loseCondition();}
    void winConditionSatisfied() { actual_game_timer->stop(); emit winCondition();}
    // time
    void updateTime();
    void start_timer();


signals:
    void loseCondition();
    void winCondition();

private:
    // time
    QLabel* timeLabel;
    QTime elapsed_time;
    QTimer elapsed_timer;
    QTimer* actual_game_timer;

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
    Bin* trash2;

    Puddle* puddle1;
    Puddle* puddle2;
    Fire* fire1;

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
    Lose* mPartner3;
    Win* mPartner4;
    QPushButton* homeScreen;
    QPushButton* toRecipes;
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

class Win: public QWidget
{
    Q_OBJECT
public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();
    void setWinScreen();
    void setPartner4(QWidget* partner);
    friend class SecondWindow;
signals:
public slots:
private:
    QWidget* mPartner4;
    QPushButton* backToHome;
};

class Lose: public QWidget
{
    Q_OBJECT
public:
    explicit Lose(QWidget *parent = nullptr);
    ~Lose();
    void setLoseScreen();
    void setPartner3(QWidget* partner);
    friend class SecondWindow;
signals:
public slots:
private:
    QWidget* mPartner3;
    QPushButton* backToHome;
};

#endif // SECONDWINDOW_H
