#ifndef MEAT_BIN_H
#define MEAT_BIN_H
#include <QMainWindow>
#include <QPainter>
#include"bin.h"

class Meat_Bin : public Bin{
public:
    Meat_Bin(int,int, QString);
    void paintEvent(QPaintEvent* e);
private:
    QString name;
};

#endif // MEAT_BIN_H
