#include "veggies.h"

Veggies::Veggies(QString a):Food(a) {}

void Veggies::print() {
    QLabel* testing = new QLabel("This is testing if veggies was added to the vector");
    testing->show();
}
