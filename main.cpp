#include<iostream>
#include<fstream>
#include <string>
#include "Matrix.h"
using namespace std;

int main(){
    unsigned int rows, cols;
    cout << "Enter A_matrix size (n m)\n";
    cin >> rows >> cols;
    Matrix A(rows, cols);
    A.inputMatrix();
    A.outputMatrix();

    A.inverse();
    A.elemTransformation_3();
    A.inverse();
//    cout << "before elemTransformation\n";
//    A.elemTransformation_1();
//    A.outputMatrix();
//    A.elemTransformation_2();
//    A.outputMatrix();
//    A.elemTransformation_3();
//    A.outputMatrix();
//    cout << "after elemTransformation\n";
//
//    unsigned int rows1, cols1;
//    cout << "Enter B_matrix size (n m)\n";
//    cin >> rows1 >> cols1;
//    Matrix B(rows1, cols1);
//    B.inputMatrix();
//    B.outputMatrix();
//
//    Matrix C = A+B;
//    cout << "Matrix A + Matrix B\n";
//    C.outputMatrix();
//
//    Matrix D = A-B;
//    cout << "Matrix A - Matrix B\n";
//    D.outputMatrix();
//
//    Matrix E = A*B;
//    cout << "Matrix A * Matrix B\n";
//    E.outputMatrix();
//
//    int c;
//    cout << "Enter c\n";
//    cin >> c;
//    A*c;
//    A.outputMatrix();
//
//    unsigned int rows2, cols2;
//    cout << "Enter F_matrix size (n m)\n";
//    cin >> rows2 >> cols2;
//    Matrix F(rows, cols);
//    F.inputMatrix();
//    cout << (F==c) << ' ' << (F!=c) << ' ' << (F==A) << ' ' << (F!=A) <<'\n';
//
//    cout << A.determinant() << '\n';
//    Matrix H = A.inverse();
//    H.outputMatrix();

//    ввод/вывод из файла
//    unsigned int rows, cols;
//    string input_path = "example_input.txt", output_path = "example_output.txt";
//    ifstream input_file(input_path);
//    if (!input_file.is_open()){
//        cerr << "File does not open1\n";
//        exit(1);
//    }
//    input_file >> rows >> cols;
//    input_file.close();
//    Matrix A(rows, cols);
//    A.inputMatrix(input_path);
//    A.outputMatrix(output_path);
//    cout << A.determinant();
    return 0;
}
