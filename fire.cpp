#include "fire.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Fire::Fire(int x,int y): Bin(x,y) {rand_num = rand() % 3 +1;srand(time(NULL));}

void Fire:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
        QPixmap bread(":/fire.png");
        painter.drawPixmap(2,2,40,40, bread);
    return;
}
 Fire::Fire(Fire &a){ this->set_bin_pos_x(a.get_bin_pos_x());}

Fire* Fire::set_random_location(){
  if (rand_num==1){Fire* a=new Fire (5,3); return a;}
  else if(rand_num==2){Fire* a=new Fire(6,8);return a;}
  else {Fire* a=new Fire(9,6);return a;}

}
