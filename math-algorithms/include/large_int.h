#include <iostream>
#include <vector>

using namespace std;

class LargeInt {
    bool is_negative;
    vector<int> data;
public:
    LargeInt();
    LargeInt(const string& x);

    LargeInt abs(const LargeInt& other) const;
    LargeInt GCD(const LargeInt& a, const LargeInt& b) const;
    LargeInt LCM(const LargeInt& a, const LargeInt& b) const;
    LargeInt operator+(const LargeInt& other) const;
    LargeInt operator-() const;
    LargeInt operator-(const LargeInt& other) const;
    LargeInt operator*(const LargeInt& other) const;
    LargeInt operator/(const LargeInt& other) const;
    LargeInt operator=(const LargeInt& other);
    LargeInt operator%(const LargeInt& other) const;
    bool operator==(const LargeInt& other) const;
    bool operator<(const LargeInt& other) const;
    bool operator>(const LargeInt& other) const;
    bool operator<=(const LargeInt& other) const;
    bool operator>=(const LargeInt& other) const;
    friend ostream& operator<<(ostream &o, const LargeInt &n);
    vector<pair<LargeInt, int>> prime_factors() const;
};