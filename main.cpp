#include <iostream>
#include <vector>
#include "random"
#include "string"

using namespace std;


class Matrix {

private:
    unsigned int rowcount, columcount;
    string s = "hallo";
    vector <vector<double>> content;
public:
    void multiply(double factor) {
        for (int currentColumn = 0; currentColumn < this->columcount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                this->content[currentColumn][currentRow] *= factor;
            }
        }
    }



    Matrix operator+(Matrix &other) {
        Matrix back = Matrix(this->rowcount, 0.0);
        for (int currentColumn = 0; currentColumn < this->columcount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                back.content[currentColumn][currentRow] = this->content[currentColumn][currentRow] +
                                                          other.content[currentColumn][currentRow];
            }
        }
        return back;
    }

    Matrix operator*(Matrix &other) {
        Matrix back = Matrix(this->rowcount, 0.0);
        for (int currentColumn = 0; currentColumn < this->columcount; currentColumn++) {
            for (int currentRow = 0; currentRow < this->rowcount; currentRow++) {
                back.content[currentColumn][currentRow] = this->productZell(other, currentColumn, currentRow);
            }
        }
        return back;
    }


    Matrix(unsigned int size, bool random = false) {
        columcount = rowcount = size;
        content = vector < vector < double >> ();
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
        columcount = rowcount = size;
        content = vector < vector < double >> ();
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
        for (int currentRow = 0; currentRow < this->columcount; currentRow++) {
            for (int currentColumn = 0; currentColumn < this->rowcount; currentColumn++) {
                cout << this->content[currentColumn][currentRow] << ";";
            }
            cout << endl;
        }
    }

private:
    double sumOfRow(int row) {
        double back = 0.0;
        for (int currentColumn = 0; currentColumn < this->columcount; currentColumn++) {
            back += this->content[currentColumn][row];
        }
        return back;
    }

    double productZell(Matrix &other, int currentColumn, int currentRow) {
        double back = 0.0;
        for (int run = 0; run < this->columcount; run++) {
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
    string a;
    cin >> a;
    return 0;
}