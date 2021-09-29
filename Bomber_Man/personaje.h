#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class Personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Personaje(QString name, int w, int h);
};

#endif // PERSONAJE_H
