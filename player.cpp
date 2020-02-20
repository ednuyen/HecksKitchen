#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent) {
    pos_x = 5;
    pos_y = 5;
    setFocusPolicy(Qt::ClickFocus);
}

Player::Player(int x,int y) {
    srand(time(NULL));
    pos_x = x;
    pos_y = y;
}

bool Player:: check_order(Player *other) {
    if (this->get_vector_size() == other->get_vector_size()) {
        for (size_t i = 0; i < get_vector_size(); i++) {
            if (this->sandwich[i]->get_food_type()!=other->sandwich[i]->get_food_type()) {
                return false;
            }
        }
    } else { return false; }
    return true;
}

void Player::set_basic_sandwich() {
    rand_num = rand() % 5 +1;
    if (rand_num == 1) {
        //House Special
        Food* a = new Bread("White Bread");
        Food* b = new Cheese("American Cheese");
        Food* c = new Meat("Turkey Meat");
        Food* d = new Bread("White Bread");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        type_of_sandwich = "House Special";
    } if (rand_num == 2) {
        //Vegan sandwich
        Food* a = new Veggies("Lettuce");
        Food* b = new Cheese("Vegan Cheese");
        Food* c = new Meat("Impossible Meat");
        Food* d = new Veggies("Lettuce");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        type_of_sandwich = "Vegan Sandwich";
    } if (rand_num == 3) {
        //Swiss Burger
        Food* a = new Bread("Whole Wheat Bread");
        Food* b = new Cheese("Swiss Cheese");
        Food* c = new Meat("Steak");
        Food* d = new Bread("Whole Wheat Bread");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        type_of_sandwich = "Swiss Burger";
    } if (rand_num == 4) {
        //The Salad Sandwich
        Food* a = new Veggies("Lettuce");
        Food* b = new Veggies("Peppers");
        Food* c = new Veggies("Spinach");
        Food* d = new Veggies("Lettuce");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        type_of_sandwich = "The Salad Sandwich";
    } if (rand_num == 5) {
        //The Loft of Bread
        Food* a = new Bread("White Bread");
        Food* b = new Bread("Prezel Bun");
        Food* c = new Veggies("Whole Wheat Bread");
        Food* d = new Veggies("White Bread");
        this->add_food(a);
        this->add_food(b);
        this->add_food(c);
        this->add_food(d);
        type_of_sandwich = "The Loft of Bread";
    }
}

void Player:: paintEvent(QPaintEvent* e) {
    if (draw_character == true) {
        QPainter painter(this);
        QPixmap player(":/player.png");
        player = player.scaled(this->size(), Qt::IgnoreAspectRatio);
        painter.drawPixmap(rect(), player);
    }
    return;
}

void Player::remove_event() {
    draw_character = false;
    this->update();
}

void Player::set_position(int x,int y) {
    pos_x = x;
    pos_y = y;
}

int Player:: get_pos_x() { return pos_x; }

int Player::get_pos_y() { return pos_y; }

void Player::add_food(Food* next_food) {
    sandwich.push_back(next_food);
    //next_food->print();
}

QVBoxLayout* Player::print_sandwich() {
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel * title = new QLabel(type_of_sandwich);
    layout->addWidget(title);
    for (size_t i = 0; i < sandwich.size(); i++) {
        QLabel* new_one = new QLabel();
        QString a= sandwich[i]->get_food_type();
        new_one->setText(a);
        layout->addWidget(new_one);
    }
    return layout;
}

void Player::test_print_sandwich() {
    QWidget* w4 = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel * title = new QLabel(type_of_sandwich);
    layout->addWidget(title);
    for (size_t i = 0; i < sandwich.size(); i++) {
        QLabel* new_one = new QLabel();
        QString a = sandwich[i]->get_food_type();
        new_one->setText(a);
        layout->addWidget(new_one);
    }
    w4->setLayout(layout);
    w4->show();
}

size_t Player::get_vector_size() { return sandwich.size(); }

void Player:: delete_sandwich() {
    for (size_t i = 0; i < this->get_vector_size(); i++) {
        delete sandwich[i];
        sandwich[i] = nullptr;
    }
    sandwich.clear();
}

void Player::move_up() { pos_y--; }
void Player::move_down() { pos_y++; }
void Player::move_right() { pos_x++; }
void Player::move_left() { pos_x--; }
