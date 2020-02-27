#ifndef BIN_H
#define BIN_H
#include <QWidget>
#include <QPainter>

class Bin : public QWidget {
public:
    Bin(int,int);
    virtual int get_bin_pos_x();
    virtual int get_bin_pos_y();
    void paintEvent(QPaintEvent *event);
private:
    int x;
    int y;
};
#endif // BIN_H
