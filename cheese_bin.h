#ifndef CHEESE_BIN_H
#define CHEESE_BIN_H
#include <QPainter>
#include "bin.h"

class Cheese_Bin : public Bin {
public:
    /*! Constructor with parameters
     *  @param     x : the x coordinate of the Cheese_Bin position
     *  @param     y : the y coordinate of the Cheese_Bin position
     *  @param _name : QString of the food name */
    Cheese_Bin(int x, int y,QString _name);

   /*! paintEvent that draws Cheese images */
    void paintEvent(QPaintEvent* e);

private:
    QString name;
};

#endif // CHEESE_BIN_H
