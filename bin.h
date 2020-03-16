#ifndef BIN_H
#define BIN_H
#include <QWidget>
#include <QPainter>

class Bin : public QWidget {
public:
   /*! Default Constructor */
    Bin();

   /*! Constructor
    *  @param x : the x coordinate of the Bin position
    *  @param y : the y coordinate of the Bin position*/
    Bin(int x, int y);

   /*! Copy Constructor */
    Bin(const Bin &a);

   /*! Virtual accessor function, accesses the value of pos_x
    *  @return pos_x : the current x-coord position of Bin object */
    virtual int get_bin_pos_x() const;

   /*! Virtual accessor function, accesses the value of pos_y
    *  @return pos_y : the current y-coord position of Bin object */
    virtual int get_bin_pos_y() const;

   /*! Sets the x coordinate position of the bin.
    *  Used for Copy Constructor of derived classes, Fire and Puddle.
    *  @param pos : the x-coord position to be set */
    void set_bin_pos_x(const int& pos);

   /*! Sets the y coordinate position of the bin.
    *  Used for Copy Constructor of derived classes, Fire and Puddle.
    *  @param pos : the y-coord position to be set */
    void set_bin_pos_y(const int& pos);

   /*! paintEvent that draws Trash Bin image */
    void paintEvent(QPaintEvent *event);

private:
    int pos_x;
    int pos_y;
};
#endif // BIN_H
