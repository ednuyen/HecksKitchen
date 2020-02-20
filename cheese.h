#ifndef CHEESE_H
#define CHEESE_H
#include <QMainWindow>
#include <QLabel>
#include "food.h"

class Cheese : public Food {
public:
    Cheese(QString);
    void print();
};

#endif // CHEESE_H
