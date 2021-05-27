#ifndef LINAL_VECTOR__MATRIX__MATRIX_H
#define LINAL_VECTOR__MATRIX__MATRIX_H

#include "Vector.h"

class Matrix {
    double** matrix;
    int rows, columns;
public:
    explicit Matrix(int _rows = 3, int _columns = 3);
    Matrix(const Matrix& m);
    Matrix(const Vector& v, int _rows);
    Matrix(double** array, int _rows, int _columns);
    ~Matrix();
    int getNumRows() const;
    int getNumColumns() const;
    double getValue(int posRow, int posColumn);
    void setValue(int posRow, int posColumn, double value);
    void generateRand() const;
    Matrix transposition() const;
    Matrix operator-() const;
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix operator*(double var) const;
    Vector operator*(const Vector& v) const;
    friend Matrix operator*(double var, const Matrix& m);
    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    double* operator[](int pos);
    friend std::ostream& operator<<(std::ostream& os, Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
    friend class Vector;
    friend class Solver;
};


#endif 