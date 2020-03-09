#include "food.h"

Food::Food() {}

Food::Food(QString a, QColor color)
    : QWidget(), type_of_food(a), color_of_food(color) {}

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

void Bread::print() {}

Meat::Meat(QString a):Food(a, QColor::fromRgb(204,103,74)) {}

void Meat::print(){}

Cheese::Cheese(QString a):Food(a, QColor::fromRgb(246,235,98)) {}

void Cheese::print() {}

Veggies::Veggies(QString a):Food(a, QColor::fromRgb(125,176,6)) {}

void Veggies::print() {}
