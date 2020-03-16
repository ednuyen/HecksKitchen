#ifndef PLAYER_H
#define PLAYER_H
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include "food.h"

class Player : public QWidget {
public:
   /*! Constructor */
    Player(QWidget *parent = nullptr);

   /*! Constructor with parameters
    * @param x position, y position, person value */
    Player(int,int,int player = 0);

   /*! Sets the specific location of a character */
    void set_position(int,int);

   /*! Draws the actual figure of the character on the board and the food stacking on the tray */
    void paintEvent(QPaintEvent* e);

   /*! Hides the image of the player, removing them from the board */
    void remove_event();

   /*! Adds the image of the player to the board */
    void create_event();

   /*! Accessor function, accesses the value of pos_x.
    *  @return pos_x : x-coord position of Player */
    int get_pos_x() const;

   /*! Accessor function, accesses the value of pos_y.
    *  @return pos_y : y-coord position of Player */
    int get_pos_y() const;

   /*! Adds a food pointer to the sandwich vector*/
    void add_food(Food*);

   /*! Accessor function, accesses the value of type_of_sandwich.
    *  @return type_of_sandwich : title of the sandwich */
    QString* get_sandwich_name() const;

    void set_basic_sandwich(); // creates all of the sandwich vectors
    void set_intermediate_sandwich(); // creates all of the sandwich vectors
    void set_expert_sandwich(); // creates all of the sandwich vectors
    Player& operator = (Player*);
    bool check_order(Player*); // checks vector to see if sandwich matches what customer ordered
    bool check_presence(); // checks if player was properly created
    void delete_sandwich(); // clears vector, called if player tries to give customer the wrong sandwich or if you throw sandwich in trash can

    void move_right();
    void move_left();
    void move_up();
    void move_down();
    /*! Sets the bool flip to true */
    void turnRight();
    /*! Sets the bool flip to false */
    void turnLeft();

private:
    std::vector<Food*> sandwich;
    int rand_num = 0;
    int pos_x;
    int pos_y;
    int chara;
    bool draw_character = true;
    bool change_character = true;
    bool flip = false;
    QString type_of_sandwich;
};

#endif // PLAYER_H

