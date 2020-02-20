#ifndef VEGGIES_H
#define VEGGIES_H
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include "food.h"

class Veggies: public Food{
public:
    Veggies(QString);
    void print();
};

#endif // VEGGIES_H
