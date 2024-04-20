#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

template<typename T>
class Matrix {
private:
    unsigned int rows, cols;
    std::vector<std::vector<T>> arr;
public:
    Matrix(unsigned int, unsigned int);
    Matrix();
    Matrix(const Matrix &);
    ~Matrix();

    void inputMatrix();
    [[maybe_unused]]void inputMatrix(const std::string&);
    void outputMatrix();
    [[maybe_unused]]void outputMatrix(const std::string&);

    [[maybe_unused]]void elemTransformation_1();
    [[maybe_unused]]void elemTransformation_2();
    [[maybe_unused]]void elemTransformation_3();

    Matrix & operator=(const Matrix &);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    void operator*(T);

    bool operator==(const Matrix&);
    bool operator==(T);
    bool operator!=(const Matrix&);
    bool operator!=(T);

    [[nodiscard]] bool isCube() const;
    double determinant();
    double minor(int, int);
    Matrix transposed();
    Matrix operator!();

    template<typename U>
    friend std::ostream &operator<< (std::ostream &, const Matrix<U>&);
    template<typename U>
    friend std::istream &operator>> (std::istream &, Matrix<U>&);

    // метод создания нулевой матрицы
    static Matrix zero(unsigned int size){
        Matrix<T> A(size, size);
        for(int i=0; i < size; i++){
            for (int j=0; j < size; j++){
                A.arr[i][j] = 0;
            }
        }
        return A;
    }

    // метод создания единичной матрицы
    static Matrix unif(unsigned int size){
        Matrix<T> A(size, size);
        for(int i=0; i < size; i++){
            for (int j=0; j < size; j++){
                if (i == j){
                    A.arr[i][j] = 1;
                } else{
                    A.arr[i][j] = 0;
                }
            }
        }
        return A;
    }

};

#endif
