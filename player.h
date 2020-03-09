#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include "food.h"
#include <vector>

class Player:public QWidget{
public:
    void set_position(int,int);
    Player(QWidget *parent= nullptr);
    Player(int,int,int player = 0);

    void paintEvent(QPaintEvent* e);
    void remove_event();
    void create_event();
    int get_pos_x();
    int get_pos_y();
    void add_food(Food*);

    QString* get_sandwich_name();
    size_t get_vector_size();
    void test_print_sandwich();
    void set_basic_sandwich();
    void set_intermediate_sandwich();
    void set_expert_sandwich();
    Player& operator = (Player*);
    bool check_order(Player*);
    bool check_presence();
    void delete_sandwich();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void set_character();
    void turnRight();
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
