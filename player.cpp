#include "player.h"
#include <QLabel>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Player::Player(QWidget *parent)
    : QWidget(parent), pos_x(5), pos_y(5), chara(0) {
    setFocusPolicy(Qt::ClickFocus);
}

Player::Player(int x,int y, int person) : pos_x(x), pos_y(y), chara(person) {
    srand(time(NULL));
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

void Player::test_print_sandwich(){
    QWidget* w4 = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel * title = new QLabel(type_of_sandwich);
    layout->addWidget(title);
    for (size_t i =0; i<sandwich.size();i++){
        QLabel* new_one = new QLabel();
        QString a= sandwich[i]->get_food_type();
        new_one->setText(a);
        layout->addWidget(new_one);
    }
    w4->setLayout(layout);
    w4->show();
}

void Player::set_basic_sandwich(){
     rand_num = rand() % 5 +1;
     if (rand_num == 1){
         //House Special
         Food* a = new Bread("White Bread");
         Food* b = new Cheese("American Cheese");
         Food* c = new Meat("Turkey Meat");
         Food* d = new Bread("White Bread");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The House Special";
    } if (rand_num == 2){
         //Veggie Patty
         Food* a = new Veggies("Lettuce");
         Food* b = new Cheese("Vegan Cheese");
         Food* c = new Meat("Impossible Meat");
         Food* d = new Veggies("Lettuce");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The Veggie Patty";
    } if (rand_num == 3){
         //Swiss Steak
         Food* a = new Bread("Whole Wheat Bread");
         Food* b = new Cheese("Swiss Cheese");
         Food* c = new Meat("Steak");
         Food* d = new Bread("Whole Wheat Bread");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "The Swiss Steak";
    } if (rand_num == 4){
         //veggie delight
         Food* a = new Veggies("Lettuce");
         Food* b = new Veggies("Peppers");
         Food* c = new Veggies("Spinach");
         Food* d = new Veggies("Lettuce");
         this->add_food(a);
         this->add_food(b);
         this->add_food(c);
         this->add_food(d);
         type_of_sandwich = "Veggie Delight";
    } if (rand_num == 5){
         //Loaf of Bread
         Food* a = new Bread("White Bread");
         Food* b = new Bread("Pretzel Bun");
         Food* c = new Bread("Whole Wheat Bread");
         Food* d = new Bread("White Bread");
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
        Food* a = new Bread("White Bread");
        Food* b = new Cheese("American Cheese");
        Food* c = new Cheese("Swiss Cheese");
        Food* d = new Veggies("Spinach");
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
        Food* a = new Bread("Whole Wheat Bread");
        Food* b = new Veggies("Lettuce");
        Food* c = new Veggies("Peppers");
        Food* d = new Meat("Impossible Meat");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "Veggie Delite";
   } if (rand_num == 3){
        //New York Style
        Food* a = new Bread("White Bread");
        Food* b = new Cheese("American Cheese");
        Food* c = new Meat("Steak");
        Food* d = new Veggies("Spinach");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        this->add_food(a);
        type_of_sandwich = "The New York Style";
   } if (rand_num == 4){
        //The Spicy Green
        Food* a = new Veggies("Lettuce");
        Food* b = new Veggies("Peppers");
        Food* c = new Veggies("Spinach");
        Food* d = new Cheese("Vegan Cheese");
        Food* e = new Meat("Impossible Meat");
        this->add_food(a);
        this->add_food(d);
        this->add_food(c);
        this->add_food(e);
        this->add_food(b);
        this->add_food(a);
        type_of_sandwich = "The Spicy Green";
   } if (rand_num == 5){
        //Double Decker
        Food* a = new Bread("Pretzel Bun");
        Food* b = new Meat("Turkey Meat");
        Food* c = new Cheese("American Cheese");
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
        Food* a = new Bread("White Bread");
        Food* b = new Cheese("Swiss Cheese");
        Food* c = new Meat("Turkey Meat");
        Food* d = new Meat("Steak");
        Food* e = new Veggies("Spinach");
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
        Food* a = new Bread("Whole Wheat Bread");
        Food* b = new Veggies("Lettuce");
        Food* c = new Veggies("Peppers");
        Food* d = new Meat("Impossible Meat");
        Food* e = new Cheese("Vegan Cheese");
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
        Food* a = new Bread("Pretzel Bun");
        Food* b = new Cheese("American Cheese");
        Food* c = new Cheese("Swiss Cheese");
        Food* d = new Meat("Steak");
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
        Food* a = new Bread("White Bread");
        Food* b = new Meat("Turkey Meat");
        Food* c = new Bread("Whole Wheat Bread");
        Food* d = new Cheese("American Cheese");
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
        Food* a = new Bread("Pretzel Bun");
        Food* b = new Meat("Turkey Meat");
        Food* c = new Meat("Impossible Meat");
        Food* d = new Meat("Steak");
        Food* e = new Cheese("American Cheese");
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
        if (flip == false){
            QPainter painter(this);
            QPixmap player(":/player.png");
            player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
            painter.drawPixmap(2, 2 , 40 ,40, player);
            //for loop for food in vector, not completely finished yet cuz i may need to adjust size of rectangles and need to adjust colors of stack
            int x = 0;
            int y = 18; // tallest sandwich is 9 so 18 makes sure all the ingredients get stacked !
            for(size_t i = 0; i < sandwich.size(); i++) {
                y-=2;
                painter.setBrush(sandwich[i]->getColor());
                painter.setPen(sandwich[i]->getColor());
                painter.drawRect(x,y,20.0,2.0);}
     }
        else {
            QPainter painter(this);
            QPixmap player(":/playerflipped.png");
            player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
            painter.drawPixmap(16, 2 , 40 ,40, player);
            //for loop for food in vector, not completely finished yet cuz i may need to adjust size of rectangles and need to adjust colors of stack
            int x = 36;
            int y = 18; // tallest sandwich is 9 so 18 makes sure all the ingredients get stacked !
            for(size_t i = 0; i < sandwich.size(); i++) {
                y-=2;
                painter.setBrush(sandwich[i]->getColor());
                painter.setPen(sandwich[i]->getColor());
                painter.drawRect(x,y,20.0,2.0);
            }
        }
    }
    return;
}

void Player::turnRight(){flip = true;}
void Player::turnLeft(){flip = false;}

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
}

QString* Player::get_sandwich_name(){
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
