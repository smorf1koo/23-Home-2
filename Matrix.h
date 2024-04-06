#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>

class Matrix {
private:
    unsigned int rows, cols;
    double** arr;
public:
    Matrix(unsigned int, unsigned int);
    Matrix();
    Matrix(const Matrix &);
    void inputMatrix();
    void inputMatrix(const std::string&);
    void outputMatrix();
    void outputMatrix(const std::string&);
    void elemTransformation_1();
    void elemTransformation_2();
    void elemTransformation_3();
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    void operator*(const double);
    Matrix operator*(const Matrix&);
    bool operator==(const Matrix&);
    bool operator==(const double);
    bool operator!=(const Matrix&);
    bool operator!=(const double);
    bool isCube() const;
    double determinant();
    double minor(int, int);
    Matrix transposed();
    Matrix inverse();
    ~Matrix();
};

#endif