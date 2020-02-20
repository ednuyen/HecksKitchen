#include "cheese.h"

Cheese::Cheese(QString a):Food(a) {}

void Cheese::print() {
    QLabel* testing = new QLabel ("This is testing if cheese was added to the vector");
    testing->show();
}
