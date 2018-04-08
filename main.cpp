#include <iostream>
#include <iomanip>
#include <vector>
#include "random"
#include "string"
#include "time.h"
#include <chrono>


using namespace std;


class Matrix {

private:
    unsigned int rowcount, columncount;
    string s = "hallo";
    vector<vector<double>> content;
public:
    void multiply(double factor) {
        for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                this->content[currentColumn][currentRow] *= factor;
            }
        }
    }


    Matrix operator+(Matrix &other) {
        Matrix back = Matrix(this->rowcount, 0.0);
        for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                back.content[currentColumn][currentRow] = this->content[currentColumn][currentRow] +
                                                          other.content[currentColumn][currentRow];
            }
        }
        return back;
    }

    Matrix operator*(Matrix &other) {
        Matrix back = Matrix(this->rowcount, 0.0);
        for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                back.content[currentColumn][currentRow] = this->productZell(other, currentColumn, currentRow);
            }
        }
        return back;
    }


    Matrix(unsigned int size, bool random = false) {
        columncount = rowcount = size;
        content = vector<vector<double >>();
        for (int row = 0; row < size; row++) {
            content.emplace_back(vector<double>());
            for (int column = 0; column < size; column++) {
                content[row].push_back(random ? rand() % 100 : 0.0);
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //   cout << content[i][j] << ";";
            }
            // cout.flush();
            //cout << endl;

        }
    }

    static Matrix Union_Matrix(unsigned int size) {
        Matrix back = Matrix(size, 0.0);
        for (int i = 0; i < size; i++) {
            back.content[i][i] = 1.0;
        }
        return back;
    }

    Matrix(unsigned int size, double value = 0.0) {
        columncount = rowcount = size;
        content = vector<vector<double >>();
        for (int row = 0; row < size; row++) {
            content.emplace_back(vector<double>());
            for (int column = 0; column < size; column++) {
                content[row].emplace_back(value);
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //   cout << content[i][j] << ";";
            }
            // cout.flush();
            //cout << endl;

        }
    }

    void print() {
        for (int currentRow = 0; currentRow < this->columncount; currentRow++) {
            for (int currentColumn = 0; currentColumn < this->rowcount; currentColumn++) {
                cout << setw(3) << this->content[currentColumn][currentRow] << ";";
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    double sumOfRow(int row) {
        double back = 0.0;
        for (int currentColumn = 0; currentColumn < this->columncount; currentColumn++) {
            back += this->content[currentColumn][row];
        }
        return back;
    }

    double productZell(Matrix &other, int currentColumn, int currentRow) {
        double back = 0.0;
        for (int run = 0; run < this->columncount; run++) {
            back += this->content[run][currentRow] * other.content[currentColumn][run];
        }
        return back;
    }
};


int main() {
    cout << "Hello, World!" << endl;
    Matrix matrix = Matrix(10, true);
    matrix.print();
    Matrix add = Matrix(10, 1.0);
    add.print();
    Matrix result = matrix + add;
    result.print();
    Matrix uni = Matrix::Union_Matrix(10);
    uni.multiply(0.5);
    Matrix r = matrix * uni;
    r.print();
    Matrix big = Matrix(512, true);
    Matrix big2 = Matrix(512, true);
    long start = time(0);
    Matrix big_result = big + big2;
    long end = time(0);
    cout << "Benötigte Zeit: " << end - start << endl;
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Matrix big_product = big * big2;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    cout << "Benötigte Zeit: " << time_span.count()<<" ms"<< endl;
    Matrix max = Matrix(512*2, true);
    Matrix max2 = Matrix(512*2, true);
    cout<<"starte MAx Test"<<endl;
    high_resolution_clock::time_point start1 = high_resolution_clock::now();
    Matrix max_product = max * max2;
    high_resolution_clock::time_point end1 = high_resolution_clock::now();
    duration<double, std::milli> time_span1 = end1 - start1;
    cout << "Benötigte Zeit: " << time_span1.count()<<" ms"<< endl;
    Matrix epic = Matrix(512*4, true);
    Matrix epic2 = Matrix(512*4, true);
    cout<<"starte Epic Test"<<endl;
    high_resolution_clock::time_point start3 = high_resolution_clock::now();
    Matrix epic_product = epic * epic2;
    high_resolution_clock::time_point end3 = high_resolution_clock::now();
    duration<double, std::milli> time_span2 = end3 - start3;
    cout << "Benötigte Zeit: " << time_span2.count()<<" ms"<< endl;
    string a;
    cin >> a;
    return 0;
}