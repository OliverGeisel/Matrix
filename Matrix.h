

#ifndef PROGRAMM_MATRIX_H
#define PROGRAMM_MATRIX_H

#include <vector>
#include "random"
#include <string>

using namespace std;
class Matrix {
protected:
    unsigned int rowcount, columncount;
    vector<vector<double>> content;

public:
    Matrix();

    Matrix(unsigned int row, unsigned int column, bool random);

    Matrix(unsigned int row, unsigned int column, double value);

    void multiply(double factor);

    void setContent(unsigned int row, unsigned int column, double value);

    Matrix operator+(Matrix &other);

    Matrix operator*(Matrix &other);


    void print();

    double sumOfRow(int row);

private:
    double productCell(Matrix &other, int currentColumn, int currentRow);
};


#endif //PROGRAMM_MATRIX_H
