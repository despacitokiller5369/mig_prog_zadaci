#pragma once

#include "point.h"

#include <iostream>
#include <vector>
#include <cmath>

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

    Point operator*(const Point& p) const;

    friend ostream& operator<<(ostream& o, const Matrix& m);

    static Matrix scale(float x, float y, float z);
    static Matrix translate(float x_deg, float y_deg, float z_deg);
    static Matrix rotate(int yaw, int pitch, int roll);

    static Matrix identity(int n);
    static Matrix transpose(const Matrix& m);
    static Matrix inverse(const Matrix& m);
    static int determinant(const Matrix& m);
};