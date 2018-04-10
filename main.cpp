#include <iostream>
#include <iomanip>
#include <vector>
#include "random"
#include "string"
#include "time.h"
#include <chrono>
#include "Matrix.h"
#include "SQR_Matrix.h"

using namespace std;
double calc_time_ms(Matrix first, Matrix second);

int main() {
    cout << "Hello, World!" << endl;
    Matrix matrix = SQR_Matrix(10, true);
    matrix.print();
    Matrix add = SQR_Matrix(10, 1.0);
    add.print();
    Matrix result = matrix + add;
    result.print();
    Matrix uni = SQR_Matrix::Union_Matrix(10);
    uni.multiply(0.5);
    Matrix r = matrix * uni;
    r.print();
    Matrix big = SQR_Matrix(512, true);
    Matrix big2 = SQR_Matrix(512, true);
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
    Matrix max = SQR_Matrix(512*2, true);
    Matrix max2 = SQR_Matrix(512*2, true);
    cout<<"starte MAx Test"<<endl;
    high_resolution_clock::time_point start1 = high_resolution_clock::now();
    Matrix max_product = max * max2;
    high_resolution_clock::time_point end1 = high_resolution_clock::now();
    duration<double, std::milli> time_span1 = end1 - start1;
    cout << "Benötigte Zeit: " << time_span1.count()<<" ms"<< endl;
   /* Matrix epic = Matrix(512*4, true);
    Matrix epic2 = Matrix(512*4, true);
    cout<<"starte Epic Test"<<endl;
    high_resolution_clock::time_point start3 = high_resolution_clock::now();
    Matrix epic_product = epic * epic2;
    high_resolution_clock::time_point end3 = high_resolution_clock::now();
    duration<double, std::milli> time_span2 = end3 - start3;
    cout << "Benötigte Zeit: " << time_span2.count()<<" ms"<< endl;*/
    string a;
    cin >> a;
    return 0;
}

double calc_time_ms(Matrix first, Matrix second){
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Matrix product = first * second;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    return time_span.count();
}