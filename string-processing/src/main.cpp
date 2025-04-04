#include <iostream>
#include <chrono>
#include <Windows.h>

#include "string_kiloo.h"
#include "trie_kiloo.h"
#include "patricia_kiloo.h"

using namespace std;
using namespace chrono;

void printResults(int *res) {
    int n = sizeof(res) / sizeof(res[0]);
    for (int i = 0; i <= n; i++) {
        cout << res[i] << endl;
    }
}

template <typename Func>
void measureAndPrint(const string& funcName, Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    cout << funcName << " took " << duration<double, milli>(end - start).count() << " ms\n";
    cout << endl;
}

int main() {
    String s = "Hello World! World World";
    cout << s << "\n" << endl;

    measureAndPrint("findFirstSubStr", [&]() {
        cout << "First occurrence of World: " << s.findFirstSubStr("World") << endl;
    });

    measureAndPrint("findLastSubStr", [&]() {
        cout << "Last occurrence of World: " << s.findLastSubStr("World") << endl;
    });

    measureAndPrint("findAllSubStr", [&]() {
        cout << "All occurrences of World:" << endl;
        int *res = s.findAllSubStr("World");
        printResults(res);
    });

    measureAndPrint("findAllSubStrReverse", [&]() {
        cout << "All occurrences of World in reverse:" << endl;
        int *res_rev = s.findAllSubStrReverse("World");
        printResults(res_rev);
    });

    measureAndPrint("rabinKarpSum", [&]() {
        cout << "All occurrences of World with Rabin-Karp (sum):" << endl;
        int *res_rk_sum = s.rabinKarpSum("World");
        printResults(res_rk_sum);
    });

    measureAndPrint("rabinKarpPow", [&]() {
        cout << "All occurrences of World with Rabin-Karp (pow):" << endl;
        int *res_rk_pow = s.rabinKarpPow("World");
        printResults(res_rk_pow);
    });

    PatriciaTrie patriciaTrie;

    patriciaTrie.insert("Hello");
    patriciaTrie.insert("World");
    patriciaTrie.insert("Worlds");
    patriciaTrie.insert("HelloWorld");

    measureAndPrint("print", [&]() {
        patriciaTrie.print();
        bool found = patriciaTrie.search("HelloWorld");
        cout << "Found: " << found << endl;
    });

    SetConsoleOutputCP(CP_UTF8);

    Trie trie;

    trie.insert(L"Hello");
    trie.insert(L"World");
    trie.insert(L"Worlds");
    trie.insert(L"HelloWorld");

    loadWordsFromTxt("..\\src\\all.txt", trie);

    measureAndPrint("print", [&]() {
        trie.print();
        bool found = trie.search(L"аграр");
        cout << "Found: " << found << endl;
    });

    return 0;
}
