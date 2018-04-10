

#include "SQR_Matrix.h"

SQR_Matrix::SQR_Matrix(unsigned int n=1) : Matrix(n, n, 0.0) {
}

SQR_Matrix::SQR_Matrix(unsigned int n, bool random = false) : Matrix(n, n, random) {

}

SQR_Matrix::SQR_Matrix(unsigned int n, double value = 0.0) : Matrix(n, n, value) {}


Matrix SQR_Matrix::Union_Matrix(unsigned int size) {
    Matrix back = SQR_Matrix(size, 0.0);
    for (unsigned int i = 0; i < size; i++) {
        back.setContent(i,i,1.0);
    }
    return back;
}

