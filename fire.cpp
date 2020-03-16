#include "fire.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*! Adds a randow number which is generated to be between 1-3 */
Fire::Fire(int x,int y): Bin(x,y) {
    rand_num = rand() % 3 + 1;
    srand(time(NULL));
}

void Fire:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap fire(":/fire.png");
    painter.drawPixmap(2,2,40,40, fire);
    return;
}

/*! Copy contructor for Fire that will change the x and y values of the objects location in the base class */
Fire::Fire(Fire &a) { this->set_bin_pos_x(a.get_bin_pos_x()); }

/*! Sets the current Fire pointer equal to a randomly generated fire pointer with one of the random Fire pointer locations */
Fire* Fire::set_random_location() {
    if (rand_num == 1) {
        Fire* a = new Fire(5,3);
        return a;
    } else if (rand_num == 2) {
        Fire* a = new Fire(6,8);
        return a;
    } else {
        Fire* a = new Fire(9,6);
        return a;
    }
}
