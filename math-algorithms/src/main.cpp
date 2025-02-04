#include <iostream>

#include "sieve.h"
#include "large_int.h"

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


    return 0;
}
