#ifndef MEAT_BIN_H
#define MEAT_BIN_H
#include <QPainter>
#include "bin.h"

class Meat_Bin : public Bin {
public:
    /*! Constructor with parameters
     *  @param     x : the x coordinate of the Meat_Bin position
     *  @param     y : the y coordinate of the Meat_Bin position
     *  @param _name : QString of the food name */
    Meat_Bin(int,int, QString);

    /*! paintEvent that draws Meat images */
    void paintEvent(QPaintEvent* e);

private:
    QString name;
};

#endif // MEAT_BIN_H
