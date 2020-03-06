#ifndef BIN_H
#define BIN_H
#include <QWidget>
#include <QPainter>

class Bin : public QWidget {
public:
    Bin();
    Bin(int,int);
    Bin(const Bin &a);
    virtual int get_bin_pos_x();
    virtual int get_bin_pos_y();
    void set_bin_pos_x(int);
    void set_bin_pos_y(int);
    void paintEvent(QPaintEvent *event);
private:
    int x;
    int y;
};
#endif // BIN_H
