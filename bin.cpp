#include "bin.h"

Bin::Bin(int a, int b){
    x = a;
    y = b;
}

int Bin::get_bin_pos_x() { return x; }

int Bin::get_bin_pos_y() { return y; }
