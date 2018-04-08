#include <iostream>
#include <vector>

using namespace std;


class Matrix {

private:
    unsigned int rowcount, columcount;
    vector<vector<double>> content;
public:

    Matrix(unsigned int size) {
        columcount = rowcount = size;
        content = vector<vector<double>>(size);
        for (int row = 0; row < size; row++){
            content.push_back(vector<double>());
            for (int colum =0;colum<size;colum++){
                content[row].push_back(0.0);
            }
        }
        for (int i = 0; i < size; i++) {
            // content.push_back(vector(size));
            for (int j = 0; j < size; j++) {
                cout << content[i][j] << ";";
            }
            cout << endl;
        }
    }

};

int main() {
    cout << "Hello, World!" << endl;
    Matrix matrix = Matrix(5);
    return 0;
}