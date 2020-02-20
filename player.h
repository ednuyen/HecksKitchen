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
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bread.h"
#include "cheese.h"
#include "veggies.h"
#include "meat.h"
#include "food.h"

class Player:public QWidget {
public:
    // void keyPressEvent(QKeyEvent* e);
    // void keyReleaseEvent(QKeyEvent *event);
    Player(QWidget *parent= nullptr);
    Player(int,int);

    int get_pos_x();
    int get_pos_y();
    void set_position(int,int);
    void paintEvent(QPaintEvent* e);
    void remove_event();

    void add_food(Food*);
    size_t get_vector_size();

    Player& operator=(Player*);
    bool check_order(Player*);
    void set_basic_sandwich();
    void test_print_sandwich();
    QVBoxLayout* print_sandwich();
    void delete_sandwich();

    void move_right();
    void move_left();
    void move_up();
    void move_down();

private:
    std::vector<Food*> sandwich;
    int rand_num = 0;
    int pos_x;
    int pos_y;
    bool draw_character = true;
    QString type_of_sandwich;

};
#endif // PLAYER_H
