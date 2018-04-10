
#ifndef PROGRAMM_SQR_MATRIX_H
#define PROGRAMM_SQR_MATRIX_H

#include "Matrix.h"

class SQR_Matrix : public Matrix {

public:
    SQR_Matrix(unsigned int n);

    SQR_Matrix(unsigned int n, bool random);

    SQR_Matrix(unsigned int n, double value);

    static Matrix Union_Matrix(unsigned int size);
};


#endif //PROGRAMM_SQR_MATRIX_H
