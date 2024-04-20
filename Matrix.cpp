#include "Matrix.h"

using namespace std;

template<typename T>
Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols)
        :rows(_rows), cols(_cols), arr(vector<vector<T>>(_rows, vector<T>(_cols))){}

template<typename T>
Matrix<T>::Matrix() : cols(0), rows(0), arr(){}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) : cols(other.cols), rows(other.rows), arr(other.arr){}

template<typename T>
Matrix<T>::~Matrix(){arr.clear();}

// ввод матрицы из консоли
template<typename T>
void Matrix<T>::inputMatrix() {
    if ((rows == 0) && (cols == 0)){
        printf("Yor matrix is empty. Enter rows and cols");
        cin >> rows >> cols;
        if ((rows <= 0) or (cols <= 0)) throw invalid_argument("Arguments must be > 0");
        arr.resize(rows, vector<T>(cols));
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element at position [%i][%i]\n", i+1, j+1);
            cin >> arr[i][j];
        }
    }
}

// ввод матрицы из файла
template<typename T>
void Matrix<T>::inputMatrix(const string& path) {
    ifstream file(path);
    if (!file.is_open()){
        throw invalid_argument("File does not open to input\n");
    }
    file.ignore(100,'\n'); // типа мы игнорируем первые 100 символов до '\n'
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            T elem;
            file >> elem;
            arr[i][j] = elem;
        }
    }
    file.close();
}


//перегрузка опреатора ввода матрицы в поток
template<typename T>
std::istream &operator>>(std::istream &is, Matrix<T>& A) {
    if ((A.rows == 0) && (A.cols == 0)){
        printf("Yor matrix is empty. Enter rows and cols: ");
        is >> A.rows >> A.cols;
        if ((A.rows <= 0) or (A.cols <= 0)) throw invalid_argument("Arguments must be > 0");
        A.arr.resize(A.rows, vector<T>(A.cols));
    }
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            printf("Enter element at position [%i][%i]\n", i+1, j+1);
            is >> A.arr[i][j];
        }
    }
    return is;
}


// вывод матрицы в консоль
template<typename T>
void Matrix<T>::outputMatrix() {
    cout << "Your Matrix: " << "\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// вывод матрицы в файл
template<typename T>
void Matrix<T>::outputMatrix(const string& path) {
    fstream file(path);
    if (!file.is_open()){
        throw invalid_argument("File does not open to output\n");
    }
    file << rows << ' ' << cols << '\n';
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            file << arr[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
}


//перегрузка опреатора вывода матрицы в поток
template<typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T>& A) {
    os << "Your Matrix: " << "\n";
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            os << A.arr[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}

// элементарное преобразование 1 (смена строк местами)
template<typename T>
void Matrix<T>::elemTransformation_1() {
    unsigned int a, b;
    cout << "Enter line numbers (a b)\n";
    cin >> a >> b;
    if ((a > rows)||(b > cols)){
        throw invalid_argument("Input error (a > rows) or (b > cols)\n");
    }
    a--, b--;
    for (int j=0; j < cols; j++){
        swap(arr[a][j], arr[b][j]);
    }
}

// элеметраное преобразование 2 (умножение на значение отличное от 0)
template<typename T>
void Matrix<T>::elemTransformation_2() {
    unsigned int a;
    T c;
    cout << "Enter line number and value != 0 \n";
    cin >> a >> c;
    if ((a > rows)||(c == 0)){
        throw invalid_argument("Input error (a > rows) or (c == 0)\n");
    }
    a--;
    for (int j=0; j < cols; j++) arr[a][j]*=c;
}

// элеметраное преобразование 3 (сложение строки на строку, умноженную на значение отличное от 0)
template<typename T>
void Matrix<T>::elemTransformation_3() {
    unsigned int a, b;
    T c;
    cout << "Enter line numbers and value != 0 \n";
    cin >> a >> b >> c;
    if ((a > rows)||(b > cols)||(c == 0)){
        throw invalid_argument("Input error (a > rows) or (b > cols) or (c==0)\n");
    }
    a--, b--;
    for (int j=0; j < cols; j++) arr[b][j] += arr[a][j]*c;
}

//оператор присваивания
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix &A){
    if (this == &A){
        throw invalid_argument("Self-appropriation\n");
    }
    rows = A.rows;
    cols = A.cols;
    for (int i = 0; i < rows; i++) arr[i] = A.arr[i];
    return *this;
}

// + сложение матриц
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& A) {
    if ((cols != A.cols)||(rows != A.rows)){
        throw invalid_argument("Different matrix dimensions\n");
    }
    Matrix<T> C(rows, cols);
    for (int i=0; i < C.rows; i++){
        for (int j=0; j < C.cols; j++){
            C.arr[i][j] = arr[i][j] + A.arr[i][j];
        }
    }
    return C;
}

// - разница матриц
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& A) {
    if ((cols != A.cols)||(rows != A.rows)){
        throw invalid_argument("Different matrix dimensions\n");
    }
    Matrix<T> C(rows, cols);
    for (int i=0; i < C.rows; i++){
        for (int j=0; j < C.cols; j++){
            C.arr[i][j] = arr[i][j] - A.arr[i][j];
        }
    }
    return C;
}
// * умножение матрицы на скаляр
template<typename T>
Matrix<T> Matrix<T>::operator*(const T c) {
    if (c == 0){
        throw invalid_argument("Zeroing\n");
    }
    Matrix<T> C(rows, cols);
    for (int i=0; i < rows; i++){
        for (int j=0; j < cols; j++){
            C.arr[i][j] = c*arr[i][j];
        }
    }
    return C;
}

// * перемножение матриц
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& A) {
    unsigned int rows1, cols1, rows2, cols2;
    rows1 = rows, cols1 = cols, rows2 = A.rows, cols2 = A.cols;
    if (cols1 != rows2){
        throw invalid_argument("Different matrix dimensions\n");
    }
    Matrix<T> C(rows1, cols2);

    for (int i=0; i < rows1; i++){
        for (int j=0; j < cols2; j++){
            for (int k = 0; k < cols1; k++) {
                C.arr[i][j] += arr[i][k] * A.arr[k][j];
            }
        }
    }
    return C;
}

// == проверка равенства матриц
template<typename T>
bool Matrix<T>::operator==(const Matrix& A) {
    if ((A.rows != rows)||(A.cols != cols)){
        return false;
    }
    for (int i = 0; i < rows; i++){
        for (int j=0; j < cols; j++){
            if (arr[i][j] != A.arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

// == проверка равенства матрицы и скаляра
template<typename T>
bool Matrix<T>::operator==(const T c) {
    if (!isCube()){
        return false;
    }
    for (int i=0; i < rows; i++){
        for (int j=0; j < cols; j++){
            if ((arr[i][j] != c) & (i == j)||(arr[i][j] != 0)&&(i != j)) return false;
        }
    }
    return true;
}

// != проверка неравенства матриц
template<typename T>
bool Matrix<T>::operator!=(const Matrix& A) {
    return !(*this==A);
}

// !- проверка неравенства матрицы и скаляра
template<typename T>
bool Matrix<T>::operator!=(const T c) {
    return !(*this == c);
}

// является ли матрица кмадратной
template<typename T>
bool Matrix<T>::isCube() const {
    return cols*cols == cols*rows;
}

// вычисление определителя
template<typename T>
double Matrix<T>::determinant(){
    if (!isCube()){
        throw invalid_argument("Matrix must be square\n");
    }
    if (cols == 1) return arr[0][0];
    if (cols == 2) return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
    double det = 0;
    for (int i=0; i < cols; i++) det+=arr[0][i] * minor(0, i); // вычеркиваем первую строку и i+1-ый столбец
    return det;
}

// вычисление минора
template<typename T>
double Matrix<T>::minor(int row, int col){ // вычеркнутые строка и колонка
    Matrix<T> A(rows-1, cols-1);
    int A_i = 0; // индекс строки minor
    for (int i=0; i < rows; i++){
        if (i == row) continue; // пропустит строку row
        int A_j = 0; // индекс столбца minor
        for (int j=0; j < cols; j++){
            if (j == col) continue; // пропустит колонку col
            A.arr[A_i][A_j] = arr[i][j];
            A_j++;
        }
        A_i++;
    }

    // знак минора
    int sign;
    if ((col+row)%2 == 0) sign = 1;
    else sign = -1;

    return sign * A.determinant();
}

// транспонирование матрицы
template<typename T>
Matrix<T> Matrix<T>::transposed() {
    if (!isCube()){
        throw invalid_argument("Matrix must be square\n");
    }
    Matrix<T> A(rows, cols);
    for (int i=0; i < rows; i++){
        for (int j=0; j < cols; j++){
            A.arr[i][j] = arr[j][i];
        }
    }
    return A;
}

// поиск обратной матрицы
template<typename T>
Matrix<T> Matrix<T>::operator!(){
    double det = determinant();
    if (det == 0) {
        throw invalid_argument("Determinant = 0\n");
    }
    Matrix<double> A(rows, cols);
    if (!isCube()) {
        throw invalid_argument("Matrix must be square\n");
    }
    for (int i=0; i<rows;i++){
        for (int j=0;j<cols;j++){
            A.arr[i][j] = minor(j,i); // составляем матрицу миноров
        }
    }
    A.transposed();
    A*(1/det);
    return A;
}