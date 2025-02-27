#include <iostream>

#include "sieve.h"
#include "large_int.h"
#include "vector_kiloo.h"

using namespace std;

int main() {
    vector<int> primes = sieve_of_eratosthenes(1000);

    for (auto p : primes) {
        cout << p << endl;
    }

    LargeInt a("-300000000000000000000");
    LargeInt b("10000");

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    cout << a.LCM(a, b) << endl;
    cout << a.GCD(a, b) << endl;
    
    vector<pair<LargeInt, int>> factors = a.prime_factors();
    for (auto f : factors) {
        cout << f.first << "^" << f.second << " ";
    }
    cout << endl;

    Vector v1(0, 3, -6);
    Vector v2(2, 4, -2);
    Vector v3(-1, -7, 2);
    Vector v4(-21, 16, -27);

    cout << "Sum of " << v1 << " and " << v2 << " = " << v1 + v2 << endl;
    cout << "Difference of " << v2 << " and " << v1 << " = " << v2 - v1 << endl;
    cout << "Product of " << v1 << " and 2 = " << v1 * 2 << endl;
    cout << "Division of " << v2 << " by 2 = " << v2 / 2 << endl;
    cout << "Dot product of " << v1 << " and " << v2 << " = " << v1.dot(v2) << endl;

    Vector res = Vector::gaussian_elimination(v1, v2, v3, v4);
    cout << "Result: x = " << res.x << ", y = " << res.y << ", z = " << res.z << endl;

    return 0;
}
