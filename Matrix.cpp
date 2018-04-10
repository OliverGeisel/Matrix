
#include <iomanip>
#include <vector>
#include "random"
#include "string"
#include "ctime"
#include <chrono>
#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::multiply(double factor) {
    for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
        for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
            this->content[currentRow][currentColumn] *= factor;
        }
    }
}

Matrix Matrix::operator+(Matrix &other) {
    Matrix back = Matrix(this->rowcount, this->columncount, 0.0);
    for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
        for (int currentRow = 0; currentRow < Matrix::rowcount; currentRow++) {
            back.content[currentColumn][currentRow] = this->content[currentColumn][currentRow] +
                                                      other.content[currentColumn][currentRow];
        }
    }
    return back;
}

Matrix Matrix::operator*(Matrix &other) {
    Matrix back = Matrix(this->rowcount, this->columncount, 0.0);
    for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
        for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
            back.content[currentColumn][currentRow] = this->productCell(other, currentColumn, currentRow);
        }
    }
    return back;
}

Matrix::Matrix() {
    rowcount=columncount=0;
    content = vector<vector<double>>();
}


Matrix::Matrix(unsigned int row, unsigned int column, bool random = false) {
    columncount = column;
    rowcount = row;
    content = std::vector<std::vector<double >>();
    for (int currrentrow = 0; currrentrow < row; currrentrow++) {
        content.emplace_back(std::vector<double>());
        for (int currentcolumn = 0; currentcolumn < column; currentcolumn++) {
            content[currrentrow].push_back(random ? rand() % 100 : 0.0);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            //   cout << content[i][j] << ";";
        }
        // cout.flush();
        //cout << endl;
    }
}


Matrix::Matrix(unsigned int row, unsigned int column, double value = 0.0) {
    columncount = rowcount = row;
    content = vector<vector<double >>();
    for (int currentrow = 0; currentrow < row; currentrow++) {
        content.emplace_back(vector<double>());
        for (int currentcolumn = 0; currentcolumn < column; currentcolumn++) {
            content[currentrow].emplace_back(value);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            //   cout << content[i][j] << ";";
        }
        // cout.flush();
        //cout << endl;

    }
}

void Matrix::print() {
    for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
        for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
            std::cout << std::setw(4) << this->content[currentRow][currentColumn] << ";";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


double Matrix::sumOfRow(int row) {
    double back = 0.0;
    for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
        back += this->content[currentColumn][row];
    }
    return back;
}

double Matrix::productCell(Matrix &other, int currentColumn, int currentRow) {
    double back = 0.0;
    for (int run = 0; run < this->columncount; run++) {
        back += this->content[run][currentRow] * other.content[currentColumn][run];
    }
    return back;
}


void Matrix::setContent(unsigned int row, unsigned int column, double value) {
    this->content[row][column] = value;
}
