#include "vector_kiloo.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(float scalar) const {
    return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::operator/(float scalar) const {
    return Vector(x / scalar, y / scalar, z / scalar);
}

ostream& operator<<(ostream& o, const Vector& v) {
    o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return o;
}

float Vector::dot(const Vector& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::gaussian_elimination(Vector a, Vector b, Vector c, Vector d) {
    float A[3][4] = {
        {a.x, a.y, a.z, d.x},
        {b.x, b.y, b.z, d.y},
        {c.x, c.y, c.z, d.z}
    };

    for (int i = 0; i < 3; i++) {
        int max_row = i;
        for (int j = i + 1; j < 3; j++) {
            if (abs(A[j][i]) > abs(A[max_row][i])) {
                max_row = j;
            }
        }

        for (int j = 0; j < 4; j++) {
            swap(A[i][j], A[max_row][j]);
        }

        if (A[i][i] == 0) {
            cerr << "Nema reshenie!" << endl;
            return Vector();
        }

        for (int j = i + 1; j < 4; j++) {
            A[i][j] /= A[i][i];
        }
        A[i][i] = 1;

        for (int j = i + 1; j < 3; j++) {
            float factor = A[j][i];
            for (int k = i; k < 4; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    float z = A[2][3] / A[2][2];
    float y = (A[1][3] - A[1][2] * z) / A[1][1];
    float x = (A[0][3] - A[0][2] * z - A[0][1] * y) / A[0][0];

    return Vector(x, y, z);
}