#include "food.h"

Food::Food() {}

Food::Food(QString a)
    : QWidget(){
    type_of_food = a;
}

QString Food::get_food_type() {
    return type_of_food;
}

void Food::store_type(QString name) {
    type_of_food = name;
}
