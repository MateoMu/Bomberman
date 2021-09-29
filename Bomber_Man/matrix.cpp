#include "matrix.h"

Matrix::Matrix(int f, int c)
{
    fila = f;
    columna = c;
    mat = new int* [f];
    for(int fil=0; fil<f; fil++) mat[fil] = new int [c];
    srand(time(NULL));
}

void Matrix::generate_map()
{
    for(int f=0; f<fila; f++){
        for(int c=0; c<columna; c++){
            if(f*c==0||c==columna-1||f==fila-1||(f%2==0 && c%2==0)) mat[f][c]=0;
            else if (!aleatorio() || (f==1 && c==1) || (f==2 && c==1) || (f==1 && c==2)) mat[f][c] = 8;
            else  mat[f][c] = 1;

        }

    }
}

bool Matrix::aleatorio()
{
    int n=rand();
    float x = p*(RAND_MAX+1)-1;

    return n<=x;
}
