#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
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
   /*! Sets up the second window for actual gameplay, lays out all widgets onto the grid
    * Calls begin_game() to set up the customers for the game */
    SecondWindow(QWidget *parent = nullptr);

   /*! Destructor*/
    ~SecondWindow();

   /*! Connects movements with keyboard buttons including arrow keys, WASD, 'G', Space*/
    void keyPressEvent(QKeyEvent *event);

   /*! Clicking the home button will maximize the partner window and minimize the current window
    *  Clicking the recipes button will maximize the partner2 window and minimize the current window
    *  Emission of loseCondition signal will maximize the partner3 window and minimize the current window
    *  Emission of winCondition signal will maximize the partner4 window and minimize the current window
    *  @param partner: the title page
    *  @param partner2: the recipe book
    *  @param partner3: the lose screen
    *  @param partner4: the win screen */
    void setPartner(QWidget* partner, RecipeWindow* partner2, Lose* partner3, Win* partner4);

   /*! Changes the difficulty level variable for the SecondWindow, this variable will then be called in
    * begin_game() to allow there to be a different number of customers and orders
    * @param int : the integer to set the difficulty to */
    void set_difficulty_level_w2(const int&);

   /*! Changes the amount of customers that appear and their specific orders depending on the level*/
    void customer_setup();

    /*! Calls the turnRight function of the Player */
    void faceRight();

   /*! Calls the turnLeft function of the Player */
    void faceLeft();

   /*! Takes away points from rating, called if player serves wrong sandwich or steps on obstacle*/
    void decrease_rating();

   /*! The restaurant rating, or equivalent to the player's health in the game.
    *  When Rating hits zero, player is fired/loses */
    class Rating : public QWidget {
    public:
       /*! Constructor */
        Rating(QWidget *parent = nullptr);

       /*! Draws health bar */
        void paintEvent(QPaintEvent* e);

       /*! Changes the value for the rating bar and will allow it to change in length
        *  @param int a : the amount to be subtracted from rating value */
        void change_rating_bar(int a);

       /*! This resets the rating_value for the bar when the game resets */
        void reset_rating();

    private:
        qreal rating_value = 10;
    };

public slots:
   /*! Changes text at the top of the screen to display the respective customer's order */
    void customer_order1();
    void customer_order2();
    void customer_order3();
    void customer_order4();
    void customer_order5();
    void customer_order6();
    void customer_order7();

   /*! Mutes the music and also reset it depending on when it is clicked*/
    void stop_music();

   /*! Calls both delete_game() and begin_game() to reset the game depending on the level the player is on */
    void reset_game();

   /*! Adds elements of the game to the board - all objects that vary and need to be reset each level*/
    void begin_game();

   /*! Deletes any extra items that were left from previous games after losing/winning/refreshing */
    void delete_game();

   /*! Called when player loses, stops timer, emits the loseCondition signal, shows the lose screen */
    void loseConditionSatisfied() { actual_game_timer->stop(); emit loseCondition();}

   /*! Called when player wins, stops timer, emits the winCondition signal, shows the win screen */
    void winConditionSatisfied() { actual_game_timer->stop(); emit winCondition();}

   /*! Updates the time displayed on the game screen - tells the player how much time has elapsed */
    void updateTime();

   /*! Starts and sets the interval of time the player has to win, two minutes and thirty seconds */
    void start_timer();

signals:
    void loseCondition();
    void winCondition();

private:
    QLabel* timeLabel;
    QTime time_display;
    QTimer timer_display;
    QTimer* actual_game_timer;

    QLabel* game_text;
    QGridLayout* play_space;
    QHBoxLayout* title_space;
    QVBoxLayout* fullwindow;
    Player* main_character;

    Rating* player_rating;
    QLabel* rating_text;
    qreal rating = 100; // Restaurant Rating starts at 100
    qreal people_served = 0;
    int difficulty_level = 1; // sets default difficulty to easy

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

    QWidget* mPartner;
    RecipeWindow* mPartner2;
    Lose* mPartner3;
    Win* mPartner4;
    QPushButton* toHome;
    QPushButton* toRecipes;
    QPushButton* mute;
};

class RecipeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeWindow(QWidget *parent = nullptr);
    ~RecipeWindow();
    /*! Clicking the recipes button will maximize the partner window and minimize the recipes window
     * @param partner: the window to be maximized, the game screen */
    void setPartner2(SecondWindow* partner);

public slots:
   /*! Clicking the recipeForward button (the forward arrow) increments the recipeCounter and changes the
    *  background of the window. If recipeCounter is 4, the button is hidden */
    void goForward();
   /*! Clicking the recipeBack button (the backward arrow) decrements the recipeCounter and changes the
    *  background of the window. If recipeCounter is 1, the button is hidden */
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
    /*! Constructor */
    explicit Win(QWidget *parent = nullptr);

     /*! Destructor */
    ~Win();

   /*! Clicking the home button will maximize the partner window and minimize the win window
    *  @param partner: the home screen */
    void setPartner4(QWidget* partner);

private:
    QWidget* mPartner4;
    QPushButton* backToHome;
};


class Lose: public QWidget
{
    Q_OBJECT
public:
     /*! Constructor */
    explicit Lose(QWidget *parent = nullptr);

     /*! Destructor */
    ~Lose();

   /*! Clicking the home button will maximize the partner window and minimize the lose window
    *  @param partner: the home screen */
    void setPartner3(QWidget* partner);

private:
    QWidget* mPartner3;
    QPushButton* backToHome;
};

#endif // SECONDWINDOW_H
