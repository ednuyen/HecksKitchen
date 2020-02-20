#include "meat.h"

Meat::Meat(QString a):Food(a) {}

void Meat::print(){
    QLabel* testing = new QLabel ("This is testing if meat was added to the vector");
    testing->show();
}
