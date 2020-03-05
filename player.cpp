#include "player.h"
#include <QLabel>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Player::Player(QWidget *parent)
    : QWidget(parent) {
    pos_x = 5;
    pos_y = 5;
    chara = 0;
    setFocusPolicy(Qt::ClickFocus);
}

Player::Player(int x,int y, int person){
    srand(time(NULL));
    pos_x = x;
    pos_y = y;
    chara = person;
}

void Player::set_character() {
    if (chara != 0)
        chara = rand() % 4 + 1;
}

bool Player:: check_order(Player *other){
    if(this->get_vector_size() == other->get_vector_size()){
        for(size_t i = 0; i < get_vector_size(); ++i) {
            if (this->sandwich[i]->get_food_type() != other->sandwich[i]->get_food_type()) {
                return false;
            }
        }
    } else {
        return false;
    } return true;
}

bool Player:: check_presence(){
    if (draw_character){
        return true;
    }
    else{
        return false;
    }
}

void Player::set_basic_sandwich(){
     rand_num = rand() % 5 +1;
     if (rand_num == 1){
         //House Special
         Food* a = new Food("White Bread");
         Food* b = new Food("American Cheese");
         Food* c = new Food("Turkey Meat");
         Food* d = new Food("White Bread");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The House Special";
    } if (rand_num == 2){
         //Veggie Patty
         Food* a = new Food("Lettuce");
         Food* b = new Food("Vegan Cheese");
         Food* c = new Food("Impossible Meat");
         Food* d = new Food("Lettuce");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The Veggie Patty";
    } if (rand_num == 3){
         //Swiss Steak
         Food* a = new Food("Whole Wheat Bread");
         Food* b = new Food("Swiss Cheese");
         Food* c = new Food("Steak");
         Food* d = new Food("Whole Wheat Bread");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The Swiss Steak";
    } if (rand_num == 4){
         //veggie delight
         Food* a = new Food("Lettuce");
         Food* b = new Food("Peppers");
         Food* c = new Food("Spinach");
         Food* d = new Food("Lettuce");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "Veggie Delight";
    } if (rand_num == 5){
         //Loaf of Bread
         Food* a = new Food("White Bread");
         Food* b = new Food("Pretzel Bun");
         Food* c = new Food("Whole Wheat Bread");
         Food* d = new Food("White Bread");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The Loaf of Bread";
    }
}

void Player::set_intermediate_sandwich(){
    rand_num = rand() % 5 +1;
    if (rand_num == 1){
        //The Cheese Melt
        Food* a = new Food("White Bread");
        Food* b = new Food("American Cheese");
        Food* c = new Food("Swiss Cheese");
        Food* d = new Food("Spinach");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(c);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "The Cheese Melt";
   } if (rand_num == 2){
        //Veggie Delite
        Food* a = new Food("Whole Wheat Bread");
        Food* b = new Food("Lettuce");
        Food* c = new Food("Peppers");
        Food* d = new Food("Impossible Meat");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "Veggie Delite";
   } if (rand_num == 3){
        //New York Style
        Food* a = new Food("White Bread");
        Food* b = new Food("American Cheese");
        Food* c = new Food("Steak");
        Food* d = new Food("Spinach");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(a);
        type_of_sandwich = "The New York Style";
   } if (rand_num == 4){
        //The Spicy Green
        Food* a = new Food("Lettuce");
        Food* b = new Food("Peppers");
        Food* c = new Food("Spinach");
        Food* d = new Food("Vegan Cheese");
        Food* e = new Food("Impossible Meat");
        this->add_food(a);
        this->add_food(d);
        this->add_food(c);
        this->add_food(e);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "The Spicy Green";
   } if (rand_num == 5){
        //Double Decker
        Food* a = new Food("Pretzel Bun");
        Food* b = new Food("Turkey Meat");
        Food* c = new Food("American Cheese");
        this->add_food(a);
        this->add_food(c);
        this->add_food(b);
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(a);
        type_of_sandwich = "The Double Decker";
   }
}

void Player::set_expert_sandwich(){
    rand_num = rand() % 5 +1;
    if (rand_num == 1){
        //Turkey & Steak
        Food* a = new Food("White Bread");
        Food* b = new Food("Swiss Cheese");
        Food* c = new Food("Turkey");
        Food* d = new Food("Steak");
        Food* e = new Food("Spinach");
        this->add_food(a);
        this->add_food(e);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(d);
        this->add_food(c);
        this->add_food(a);
        type_of_sandwich = "Turkey & Steak";
   } if (rand_num == 2){
        //Veggie SR
        Food* a = new Food("Whole Wheat Bread");
        Food* b = new Food("Lettuce");
        Food* c = new Food("Peppers");
        Food* d = new Food("Impossible Meat");
        Food* e = new Food("Vegan Cheese");
        this->add_food(a);
        this->add_food(b);
        this->add_food(e);
        this->add_food(d);
        this->add_food(c);
        this->add_food(e);
        this->add_food(d);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "Veggie SR";
   } if (rand_num == 3){
        //Philly Steak
        Food* a = new Food("Pretzel Bun");
        Food* b = new Food("American Cheese");
        Food* c = new Food("Swiss Cheese");
        Food* d = new Food("Steak");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "Philly Steak";
   } if (rand_num == 4){
        //Thxgiving Special
        Food* a = new Food("White Bread");
        Food* b = new Food("Turkey Meat");
        Food* c = new Food("Whole Wheat Bread");
        Food* d = new Food("American Cheese");
        this->add_food(a);
        this->add_food(d);
        this->add_food(b);
        this->add_food(d);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(d);
        this->add_food(a);
        type_of_sandwich = "Thxgiving Special";
   }if (rand_num == 5){
        //Meat Lovers
        Food* a = new Food("Pretzel Bun");
        Food* b = new Food("Turkey Meat");
        Food* c = new Food("Impossible Meat");
        Food* d = new Food("Steak");
        Food* e = new Food("American Cheese");
        this->add_food(a);
        this->add_food(b);
        this->add_food(e);
        this->add_food(d);
        this->add_food(c);
        this->add_food(b);
        this->add_food(e);
        this->add_food(d);
        this->add_food(a);
        type_of_sandwich = "Meat Lovers";
   }
}

void Player::paintEvent(QPaintEvent* e) {
    rect().setX(2);
    rect().setY(2);
    if(change_character) {
        if (chara != 0)
            chara = rand() % 4 + 1;
        change_character = false;
    } if (draw_character == true && chara == 1){
        QPainter painter(this);
        QPixmap player(":/chara1.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(2,2,25,40, player);
    }
    else if (draw_character == true && chara == 2){
        QPainter painter(this);
        QPixmap player(":/chara2.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(2,2,25,40, player);
    }
    else if (draw_character == true && chara == 3){
        QPainter painter(this);
        QPixmap player(":/chara3.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(2,2,25,40, player);
    }
    else if (draw_character == true && chara == 4){
        QPainter painter(this);
        QPixmap player(":/chara4.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(2,2,25,40, player);}
    else if (draw_character == true && chara == 0){
        QPainter painter(this);
        QPixmap player(":/player.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
       painter.drawPixmap(2, 2 , 40 ,40, player);}
    return;
}

void Player::remove_event(){
    draw_character = false;
    this-> update();
}
void Player::create_event(){
    draw_character = true;
    this-> update();
}

void Player::set_position(int x,int y){
    pos_x = x;
    pos_y = y;
}

int Player:: get_pos_x(){
    return pos_x;
}

int Player::get_pos_y(){
    return pos_y;
}

void Player::add_food(Food* next_food){
    sandwich.push_back(next_food);
    //next_food->print();
}

QString* Player::get_sandwich_name(){
    //QVBoxLayout* layout = new QVBoxLayout;
    QString * title = new QString(type_of_sandwich);
    return title;
}

size_t Player::get_vector_size() {
    return sandwich.size();
}

void Player:: delete_sandwich(){
    for (size_t i = 0; i<this->get_vector_size(); ++i) {
        delete sandwich[i];
        sandwich[i] = nullptr;
    }
    sandwich.clear();
}

void Player::move_up() { pos_y--; }
void Player::move_down() { pos_y++; }
void Player::move_right() { pos_x++; }
void Player::move_left() { pos_x--; }
