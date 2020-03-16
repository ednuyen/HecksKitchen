#ifndef PUDDLE_H
#define PUDDLE_H
#include <QPainter>
#include "bin.h"

class Puddle : public Bin {
public:
   /*! Constructor with parameters
    *  @param x : the x coordinate of the Puddle position
    *  @param y : the y coordinate of the Puddle position */
    Puddle(int x,int y);

   /*! Copy Constructor */
    Puddle(Puddle &a);

   /*! Draws Puddle image */
    void paintEvent(QPaintEvent* e);

   /*! Creates a Puddle pointer to a randomly located Puddle on the screen
    *  Called whenever game is reset to place Puddle in different locations.
    *  @return Puddle* a : the Puddle pointer */
    Puddle* set_random_location();

private:
    int rand_num = 0;
};
#endif // PUDDLE_H
