#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, vector<float>(cols)) {}
Matrix::Matrix(int rows, int cols, const vector<vector<float>>& data) : rows(rows), cols(cols), data(data) {}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cerr << "Razlicni dimenzii na matricite!" << endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cerr << "Razlicni dimenzii na matricite!" << endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        cerr << "Nevalidno mnozhenje na matrici!" << endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(float scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(float scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

ostream& operator<<(ostream& o, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            o << m.data[i][j] << " ";
        }
        o << endl;
    }
    return o;
}

Matrix Matrix::identity(int n) {
    Matrix result(n, n);
    for (int i = 0; i < n; i++) {
        result.data[i][i] = 1;
    }
    return result;
}

Matrix Matrix::transpose(const Matrix& m) {
    Matrix result(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::inverse(const Matrix& m) {
    if (m.rows != m.cols) {
        cerr << "Matrica ne e kvadratna!" << endl;
        return Matrix(0, 0);
    }

    int n = m.rows;
    Matrix result = identity(n);
    Matrix copy = m;

    for (int i = 0; i < n; i++) {
        float diag = copy.data[i][i];
        if (diag == 0) {
            cerr << "Matrica ne e invertibilna!" << endl;
            return Matrix(0, 0);
        }

        for (int j = 0; j < n; j++) {
            copy.data[i][j] /= diag;
            result.data[i][j] /= diag;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = copy.data[k][i];
                for (int j = 0; j < n; j++) {
                    copy.data[k][j] -= factor * copy.data[i][j];
                    result.data[k][j] -= factor * result.data[i][j];
                }
            }
        }
    }

    return result;
}

int Matrix::determinant(const Matrix& m) {
    if (m.rows != m.cols) {
        cerr << "Matrica ne e kvadratna!" << endl;
        return 0;
    }

    int n = m.rows;
    if (n == 1) {
        return m.data[0][0];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        Matrix submatrix(n - 1, n - 1);
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    submatrix.data[j - 1][k] = m.data[j][k];
                } else if (k > i) {
                    submatrix.data[j - 1][k - 1] = m.data[j][k];
                }
            }
        }

        int sign = (i % 2 == 0) ? 1 : -1;
        result += sign * m.data[0][i] * determinant(submatrix);
    }

    return result;
}