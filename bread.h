#ifndef BREAD_H
#define BREAD_H
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include "food.h"

class Bread : public Food {
public:
    Bread(QString);
    void print();
};

#endif // BREAD_H
