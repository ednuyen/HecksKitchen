#ifndef FOOD_H
#define FOOD_H
#include <QWidget>
#include <QString>

class Food : public QWidget {
public:
    /*! Default Constructor */
    Food();

    /*! Constructor with parameters
     *  @param type : the name of the food type */
    Food(QString type);

    /*! Accessor function, accesses the value of type_of_food.
     *  @return type_of_food : a string of the food name  */
    QString get_food_type() const;

    /*! Pure virtual accessor function.
     *  Accesses QColor value for derived classes. */
    virtual QColor getColor() const = 0;

private:
    QString type_of_food;
};


/*! Child classes of Food: Bread, Cheese, Meat, Veggies */

class Bread : public Food {
public:
    Bread(QString);

    /*! Accessor function, accesses the value of color_of_food
     *  @return color_of_food : the QColor of the specific food */
    QColor getColor() const;

private:
    QColor color_of_food;
};

class Cheese : public Food {
public:
    Cheese(QString);

    /*! Accessor function, accesses the value of color_of_food
     *  @return color_of_food : the QColor of the specific food */
    QColor getColor() const;

private:
    QColor color_of_food;
};

class Meat : public Food {
public:
    Meat(QString);

    /*! Accessor function, accesses the value of color_of_food
     * @return color_of_food : the QColor of the specific food */
    QColor getColor() const;

private:
    QColor color_of_food;
};

class Veggies: public Food {
public:
    Veggies(QString);

    /*! Accessor function, accesses the value of color_of_food
     * @return color_of_food : the QColor of the specific food */
    QColor getColor() const;

private:
    QColor color_of_food;
};

#endif // FOOD_H
