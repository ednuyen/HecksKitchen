#ifndef FOOD_H
#define FOOD_H
#include <QMainWindow>
#include <QString>

class Food : public QWidget {
public:
    Food();
    Food(QString, QColor color);
    virtual void print() = 0;
    void store_type(QString);
    QString get_food_type();
    QColor getColor();

private:
    QString type_of_food;
    QColor color_of_food;
};


class Bread : public Food {
public:
    Bread(QString);
    void print();
};


class Cheese : public Food {
public:
    Cheese(QString);
    void print();
};

class Meat : public Food {
public:
    Meat(QString);
    void print();
};

class Veggies: public Food {
public:
    Veggies(QString);
    void print();
};

#endif // FOOD_H
