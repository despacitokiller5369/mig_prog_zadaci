#pragma once

#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

class Vector {
public:
    float x, y, z;

    Vector(float x = 0, float y = 0, float z = 0);

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(float scalar) const;
    Vector operator/(float scalar) const;

    friend ostream& operator<<(ostream& o, const Vector& v);

    float dot(const Vector& other) const;
    static Vector gaussian_elimination(Vector a, Vector b, Vector c, Vector d);
};