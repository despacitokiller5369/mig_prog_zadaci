#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    int rows, cols;
    vector<vector<float>> data;
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, const vector<vector<float>>& data);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(float scalar) const;
    Matrix operator/(float scalar) const;

    friend ostream& operator<<(ostream& o, const Matrix& m);

    static Matrix identity(int n);
    static Matrix transpose(const Matrix& m);
    static Matrix inverse(const Matrix& m);
    static int determinant(const Matrix& m);
};