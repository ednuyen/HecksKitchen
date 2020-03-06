#include "food.h"

Food::Food() {}

Food::Food(QString a, QColor color)
    : QWidget(), type_of_food(a), color_of_food(color) {}
//    type_of_food = a

QString Food::get_food_type() {
    return type_of_food;
}

void Food::store_type(QString name) {
    type_of_food = name;
}

QColor Food::getColor() {
    return color_of_food;
}

Bread::Bread(QString a): Food(a, QColor::fromRgb(223,164,93)) {}

void Bread::print() {
//    QLabel* testing = new QLabel ("This is testing if bread was added to the vector");
//    testing->show();
}

Meat::Meat(QString a):Food(a, QColor::fromRgb(204,103,74)) {}

void Meat::print(){
//    QLabel* testing = new QLabel ("This is testing if meat was added to the vector");
//    testing->show();
}

Cheese::Cheese(QString a):Food(a, QColor::fromRgb(246,235,98)) {}

void Cheese::print() {
//    QLabel* testing = new QLabel ("This is testing if cheese was added to the vector");
//    testing->show();
}

Veggies::Veggies(QString a):Food(a, QColor::fromRgb(125,176,6)) {}

void Veggies::print() {
//    QLabel* testing = new QLabel("This is testing if veggies was added to the vector");
//    testing->show();
}
