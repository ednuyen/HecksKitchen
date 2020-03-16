#include "puddle.h"

/*! Adds a randow number which is generated to be between 1-5 */
Puddle::Puddle(int x,int y): Bin(x,y) { rand_num = rand() % 5 + 1; srand(time(NULL)); }

void Puddle:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap puddle(":/puddle.png");
    painter.drawPixmap(2,2,40,40, puddle);
    return;
}

/*! Copy contructor for the Puddle that will change the x and y values of the objects location in the base class */
Puddle::Puddle(Puddle &a) { this->set_bin_pos_x(a.get_bin_pos_x());}

/*! Sets the current Puddle pointer equal to a randomly generated Puddle pointer with one of the random Puddle pointer locations */
Puddle* Puddle::set_random_location() {
    if (rand_num == 1) {
        Puddle* a=new Puddle (4,3);
        return a;
    } else if(rand_num == 2) {
        Puddle* a=new Puddle(7,4);
        return a;
    } else if (rand_num == 3) {
        Puddle* a=new Puddle(5,6);
        return a;
    } else if (rand_num == 4) {
        Puddle* a=new Puddle(7,8);
        return a;
    } else {
        Puddle* a=new Puddle(8,5);
        return a;
    }
}
