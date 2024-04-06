#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>

template<typename T>
class Matrix {
private:
    unsigned int rows, cols;
    T** arr;
public:
    Matrix(unsigned int, unsigned int);
    Matrix();
    Matrix(const Matrix &);
    ~Matrix();

    void inputMatrix();
    void inputMatrix(const std::string&);
    void outputMatrix();
    void outputMatrix(const std::string&);

    void elemTransformation_1();
    void elemTransformation_2();
    void elemTransformation_3();

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    void operator*(T);
    Matrix operator*(const Matrix&);

    bool operator==(const Matrix&);
    bool operator==(T);
    bool operator!=(const Matrix&);
    bool operator!=(T);

    [[nodiscard]] bool isCube() const;
    double determinant();
    double minor(int, int);
    Matrix transposed();
    Matrix operator!();
};

#endif
