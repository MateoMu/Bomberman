#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include "time.h"

class Matrix
{
public:
    Matrix(int f, int c);
    void generate_map();
    int **mat;

private:
    int fila, columna;
    float p=0.3;
    bool aleatorio();
};

#endif // MATRIX_H
