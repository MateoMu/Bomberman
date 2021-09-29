#include "blocks.h"

Blocks::Blocks()
{
    original.load(":/imagenes/bloques.png");
}

void Blocks::set_size(int w, int l)
{
    width = w;
    length = l;
}

void Blocks::set_img(int i)
{
    if(i==8) img = original.copy(126, 14, 1, 1);
    else if(i==9) img = original.copy(0, 0, 1, 1);
    else img = original.copy(16*i, 0, 16, 16);

    setPixmap(img.scaled(width, length));
}
