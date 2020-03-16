#include "food.h"

Food::Food() {} // Default Constructor

Food::Food(QString type) : type_of_food(type) {}

QString Food::get_food_type() const { return type_of_food; }

Bread::Bread(QString type_name) : Food(type_name) {
    // Sets color of specific type of bread if the string 'type_name' matches
    if (type_name == "White Bread")
        color_of_food = QColor::fromRgb(206,172,124);
    if (type_name == "Whole Wheat Bread")
        color_of_food = QColor::fromRgb(145,113,97);
    if (type_name == "Pretzel Bun")
        color_of_food = QColor::fromRgb(186,152,107);
}

QColor Bread::getColor() const { return color_of_food; }

Meat::Meat(QString type_name) : Food(type_name) {
    // Sets color of specific type of meat if the string 'type_name' matches
    if (type_name == "Turkey Meat")
        color_of_food = QColor::fromRgb(226,161,145);
    if (type_name == "Steak")
        color_of_food = QColor::fromRgb(100,55,43);
    if (type_name == "Impossible Meat")
        color_of_food = QColor::fromRgb(89,62,51);
}

QColor Meat::getColor() const { return color_of_food; }

Cheese::Cheese(QString type_name) : Food(type_name) {
    // Sets color of specific type of cheese if the string 'type_name' matches
    if (type_name == "American Cheese")
        color_of_food = QColor::fromRgb(240,218,54);
    if (type_name == "Swiss Cheese")
        color_of_food = QColor::fromRgb(248,232,152);
    if (type_name == "Vegan Cheese")
        color_of_food = QColor::fromRgb(254,248,194);
}

QColor Cheese::getColor() const { return color_of_food; }

Veggies::Veggies(QString type_name) : Food(type_name) {
    // Sets color of specific type of veggie if the string 'type_name' matches
    if (type_name == "Lettuce")
        color_of_food = QColor::fromRgb(191,238,131);
    if (type_name == "Peppers")
        color_of_food = QColor::fromRgb(213,71,24);
    if (type_name == "Spinach")
        color_of_food = QColor::fromRgb(88,139,49);
}

QColor Veggies::getColor() const { return color_of_food; }
