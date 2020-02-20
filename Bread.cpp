#include "bread.h"

Bread::Bread(QString a): Food(a) {}

void Bread::print() {
    QLabel* testing = new QLabel ("This is testing if bread was added to the vector");
    testing->show();
}
