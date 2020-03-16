#ifndef BREAD_BIN_H
#define BREAD_BIN_H
#include <QPainter>
#include "bin.h"

class Bread_Bin : public Bin {
public:
    /*! Constructor with parameters
     *  @param     x : the x coordinate of the Bread_Bin position
     *  @param     y : the y coordinate of the Bread_Bin position
     *  @param _name : QString of the food name */
    Bread_Bin(int x, int y, QString _name);

   /*! paintEvent that draws Bread images */
    void paintEvent(QPaintEvent* e);

private:
    QString name;
};

#endif // BREAD_BIN_H
