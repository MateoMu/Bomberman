#ifndef BLOCKS_H
#define BLOCKS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Blocks : public QObject, public QGraphicsPixmapItem
{
public:
    Blocks();
    void set_size(int w, int l);
    void set_img(int i);
private:
    QPixmap original, img;
    int width, length;
};

#endif // BLOCKS_H
