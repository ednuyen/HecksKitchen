#ifndef MEAT_H
#define MEAT_H
#include <QMainWindow>
#include <QLabel>
#include "food.h"

class Meat : public Food {
public:
    Meat(QString);
    void print();
};

#endif // MEAT_H
