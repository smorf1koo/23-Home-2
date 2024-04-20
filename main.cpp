#include<iostream>
#include<fstream>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;

int main(){
    cout << "Enter Matrix M\n";
    Matrix<double> M;
    cin >> M;
    cout << M;

    cout << "Enter Matrix K\n";
    Matrix<double> K(2, 2);
    cin >> K;
    cout << K;

    cout << "Sum, product, difference of matrices M and K\n";
    Matrix<double> A = M + K;
    Matrix<double> B = M * K;
    Matrix<double> C = M - K;
    A.outputMatrix();
    B.outputMatrix();
    cout << C;

    cout << "Matrix multiplication by scalar\n";
    Matrix<double> D = A*4;
    cout << A << D;

    cout << "Zero matrix of order 4\n";
    Matrix<int> Z = Matrix<int>::zero(4);
    cout << Z;

    cout << "Unit matrix of order 5\n";
    Matrix<int> U = Matrix<int>::unif(5);
    cout << U;

    cout << "Inverse matrix\n";
    Matrix<double> E = !A;
    cout << E;

    cout << "Assignment\n";
    cout << "Matrix B\n" << B << "Matrix A\n" << A;
    B = A;
    cout << "Matrix B after assignment\n" << B;
    return 0;
}