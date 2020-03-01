#ifndef BREAD_BIN_H
#define BREAD_BIN_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Bread_Bin : public Bin {
public:
    Bread_Bin(int,int,QString);
    void paintEvent(QPaintEvent* e);
private:
    QString name;
};

#endif // BREAD_BIN_H
