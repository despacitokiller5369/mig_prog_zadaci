#include <iostream>

#include "string_kiloo.h"

using namespace std;

int main() {
    String s = "Hello World! World World";
    cout << s << endl;

    cout << "First occurence of World: " << s.findFirstSubStr("World") << endl;
    cout << "Last occurence of World: " << s.findLastSubStr("World") << endl;
    
    cout << "All occurences of World:" << endl;
    int *res = s.findAllSubStr("World");
    int n = sizeof(res) / sizeof(res[0]);
    for (int i = 0; i <= n; i++) {
        cout << res[i] << endl;
    }

    cout << "All occurences of World in reverse:" << endl;
    int *res_rev = s.findAllSubStrReverse("World");
    int n_rev = sizeof(res_rev) / sizeof(res_rev[0]);
    for (int i = 0; i <= n_rev; i++) {
        cout << res_rev[i] << endl;
    }

    cout << "All occurences of World with Rabin-Karp (sum):" << endl;
    int *res_rk_sum = s.rabinKarpSum("World");
    int n_rk_sum = sizeof(res_rk_sum) / sizeof(res_rk_sum[0]);
    for (int i = 0; i <= n_rk_sum; i++) {
        cout << res_rk_sum[i] << endl;
    }

    cout << "All occurences of World with Rabin-Karp (pow):" << endl;
    int *res_rk_pow = s.rabinKarpPow("World");
    int n_rk_pow = sizeof(res_rk_pow) / sizeof(res_rk_pow[0]);
    for (int i = 0; i <= n_rk_pow; i++) {
        cout << res_rk_pow[i] << endl;
    }

    return 0;
}