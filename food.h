#ifndef FOOD_H
#define FOOD_H
#include <QMainWindow>
#include <QString>

class Food : public QWidget {
public:
    Food();
    Food(QString);
    virtual void print() = 0;
    void store_type(QString);
    QString get_food_type();
private:
    QString type_of_food;
};

#endif // FOOD_H
