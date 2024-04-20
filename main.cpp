#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;

int main(){
    Matrix<int> M;
    cin >> M;
    cout << M;

    Matrix<double> K(2, 2);
    cin >> K;
    cout << K;

    Matrix<int> Z = Matrix<int>::zero(4);
    cout << Z;

    Matrix<int> U = Matrix<int>::unif(5);
    cout << U;
    return 0;
}