#ifndef FIRE_H
#define FIRE_H
#include <QPainter>
#include "bin.h"

class Fire : public Bin {
public:
   /*! Constructor with parameters
    *  @param x : the x coordinate of the Fire position
    *  @param y : the y coordinate of the Fire position */
    Fire(int x,int y);

   /*! Copy Constructor */
    Fire(Fire &a);

   /*! paintEvent that draws Fire image */
    void paintEvent(QPaintEvent* e);

   /*! Creates a Fire pointer to a randomly located Fire on the screen
    *  Called whenever game is reset to place Fire in different locations.
    *  @return Fire* a : the Fire pointer  */
    Fire* set_random_location();

private:
    int rand_num = 0;
};
#endif // FIRE_H
