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
    int get_pos_x();
    int get_pos_y();
    void add_food(Food*);

    QString* print_sandwich();
    void test_print_sandwich();
    size_t get_vector_size();
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

private:
    std::vector<Food*> sandwich;

    int rand_num =0;
    int chara;
    int pos_x;
    int pos_y;
    bool draw_character = true;
    bool change_character = true;
    QString type_of_sandwich;

};
#endif // PLAYER_H
