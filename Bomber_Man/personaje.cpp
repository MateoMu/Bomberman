#include "personaje.h"


Personaje::Personaje(QString name, int w, int h)
{
    setPixmap(QPixmap(name).scaled(w,h));
}
