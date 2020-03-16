#ifndef VEGGIE_BIN_H
#define VEGGIE_BIN_H
#include "bin.h"
#include <QPainter>

class Veggie_Bin : public Bin {
public:
    /*! Constructor with parameters
     *  @param     x : the x coordinate of the Veggie_Bin position
     *  @param     y : the y coordinate of the Veggie_Bin position
     *  @param _name : QString of the food name */
    Veggie_Bin(int,int, QString);

    /*! paintEvent that draws Veggie images */
    void paintEvent(QPaintEvent* e);
private:
     QString name;
};

#endif // VEGGIE_BIN_H
