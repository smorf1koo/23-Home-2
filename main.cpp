#include<iostream>
#include<fstream>
#include <string>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;

int main(){
    Matrix<double> A(3, 3);
    A.inputMatrix();
    A.outputMatrix();
    return 0;
}