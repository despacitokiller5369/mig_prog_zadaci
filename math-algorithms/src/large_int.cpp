#include "large_int.h"

#include <iostream>
#include <vector>

using namespace std;

LargeInt::LargeInt() : is_negative(false) {}
LargeInt::LargeInt(const string& x) {
    is_negative = x[0] == '-';
    for (int i = x.size() - 1; i >= is_negative; --i) {
        data.push_back(x[i] - '0');
    }
    if (data.empty()) {
        data.push_back(0);
        is_negative = false;
    }
}

LargeInt LargeInt::operator+(const LargeInt& other) const {
    if (is_negative == other.is_negative) {
        LargeInt result;
        result.is_negative = is_negative;
        int carry = 0;
        for (int i = 0; i < max(data.size(), other.data.size()) || carry; ++i) {
            int sum = carry;
            if (i < data.size()) sum += data[i];
            if (i < other.data.size()) sum += other.data[i];
            result.data.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    } else {
        if (is_negative) {
            return other - (-(*this));
        } else {
            return *this - (-other);
        }
    }
}

LargeInt LargeInt::operator-(const LargeInt& other) const {
    if (is_negative != other.is_negative) {
        return *this + (-other);
    } else {
        if (abs(*this) >= abs(other)) {
            LargeInt result;
            result.is_negative = is_negative;
            int borrow = 0;
            for (int i = 0; i < max(data.size(), other.data.size()); ++i) {
                int left = 0;
                if (i < data.size()) left = data[i];
                int right = 0;
                if (i < other.data.size()) right = other.data[i];
                int diff = left - right - borrow;

                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }

                result.data.push_back(diff);
            }

            while (result.data.size() > 1 && result.data.back() == 0) {
                result.data.pop_back();
            }

            return result;
        } else {
            return -(other - *this);
        }
    }
}

LargeInt LargeInt::operator*(const LargeInt& other) const {
    LargeInt result;
    result.data.resize(data.size() + other.data.size(), 0);

    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < other.data.size(); ++j) {
            int prod = data[i] * other.data[j] + result.data[i + j];
            result.data[i + j] = prod % 10;
            result.data[i + j + 1] += prod / 10;
        }
    }

    while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }

    result.is_negative = is_negative != other.is_negative;
    return result;
}

LargeInt LargeInt::operator/(const LargeInt& other) const {
    if (other == LargeInt("0")) {
        return LargeInt("0");
    }

    LargeInt result;
    LargeInt current;
    LargeInt dividend = abs(*this);
    LargeInt divisor = abs(other);

    result.data.resize(dividend.data.size(), 0);

    for (int i = dividend.data.size() - 1; i >= 0; --i) {
        current.data.insert(current.data.begin(), dividend.data[i]);
        if (current.data.size() > 1 && current.data.back() == 0) {
            current.data.pop_back();
        }

        int x = 0;
        while (current >= divisor) {
            current = current - divisor;
            ++x;
        }
        result.data[i] = x;
    }

    while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }

    result.is_negative = is_negative != other.is_negative;
    if (result.data.size() == 1 && result.data[0] == 0) {
        result.is_negative = false;
    }

    return result;
}

LargeInt LargeInt::operator=(const LargeInt& other) {
    data = other.data;
    is_negative = other.is_negative;
    return *this;
}

LargeInt LargeInt::operator-() const {
    LargeInt result = *this;
    result.is_negative = !is_negative;
    return result;
}

LargeInt LargeInt::operator%(const LargeInt& other) const {
    if (other == LargeInt("0")) {
        return LargeInt("0");
    }
    LargeInt result = *this - (*this / other) * other;
    return abs(result);
}

bool LargeInt::operator==(const LargeInt& other) const {
    return data == other.data && is_negative == other.is_negative;
}

bool LargeInt::operator<(const LargeInt& other) const {
    if (is_negative != other.is_negative) {
        return is_negative;
    }
    if (data.size() != other.data.size()) {
        return (data.size() < other.data.size()) ^ is_negative;
    }
    for (int i = data.size() - 1; i >= 0; --i) {
        if (data[i] != other.data[i]) {
            return (data[i] < other.data[i]) ^ is_negative;
        }
    }
    return false;
}

bool LargeInt::operator>(const LargeInt& other) const {
    return other < *this;
}

bool LargeInt::operator<=(const LargeInt& other) const {
    return !(*this > other);
}

bool LargeInt::operator>=(const LargeInt& other) const {
    return !(*this < other);
}

ostream& operator<<(ostream &o, const LargeInt &n) {
    if (n.is_negative) o << '-';
    for (int i = n.data.size() - 1; i >= 0; --i) {
        o << n.data[i];
    }
    return o;
}

LargeInt LargeInt::abs(const LargeInt& other) const {
    LargeInt result = other;
    result.is_negative = false;
    return result;
}

LargeInt LargeInt::GCD(const LargeInt& a, const LargeInt& b) const {
    if (b == LargeInt("0")) {
        return a;
    }
    return GCD(b, a % b);
}

LargeInt LargeInt::LCM(const LargeInt& a, const LargeInt& b) const {
    if (a == LargeInt("0") || b == LargeInt("0")) {
        return LargeInt("0");
    }

    return abs(a * b) / GCD(a, b);
}