#include "string_kiloo.h"

using namespace std;

String::String() {
    length = 0;
    chars = nullptr;
}

String::String(const char *other) {
	int len = 0;
	while (other[len] != '\0') {
		len++;
	}
	length = len;
	chars = new char[length + 1];
	for (unsigned int i = 0; i < length; i++) {
		chars[i] = other[i];
	}
	chars[length] = '\0';
}

String::String(const String &other) {
    length = other.length;
    chars = new char[length + 1];
    for (unsigned int i = 0; i < length; i++) {
        chars[i] = other.chars[i];
    }
    chars[length] = '\0';
}

String::~String() {
    delete[] chars;
}

String String::operator=(const char *other) {
	int len = 0;
	while (other[len] != '\0') {
		len++;
	}
	length = len;
	delete[] chars;
	chars = new char[length + 1];
	for (unsigned int i = 0; i < length; i++) {
		chars[i] = other[i];
	}
	chars[length] = '\0';
	return *this;
}

String String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }
    delete[] chars;
    length = other.length;
    chars = new char[length + 1];
    for (unsigned int i = 0; i < length; i++) {
        chars[i] = other.chars[i];
    }
    chars[length] = '\0';
    return *this;
}

char& String::operator[](unsigned int index) {
	if (index < 0 || index >= length) {
		throw out_of_range("Index out of range!");
	}
	return chars[index];
}

const char& String::operator[](unsigned int index) const {
	if (index < 0 || index >= length) {
		throw out_of_range("Index out of range!");
	}
	return chars[index];
}

ostream& operator<<(ostream &o, const String &other) {
	for (unsigned int i = 0; i < other.length; i++) {
		o << other.chars[i];
	}
	return o;
}

void String::computeLPSArray(const String &subStr, int lps[]) {
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < subStr.length; i++) {
        while (len > 0 && subStr[i] != subStr[len]) {
            len = lps[len - 1];
        }
        if (subStr[i] == subStr[len]) {
            len++;
        }
        lps[i] = len;
    }
}

void String::computeLPSArrayReverse(const String &subStr, int lps[]) {
    int len = subStr.length - 1;
    lps[len] = 0;
    for (int i = len - 1; i >= 0; i--) {
        while (len > 0 && subStr[i] != subStr[len]) {
            len = lps[len - 1];
        }
        if (subStr[i] == subStr[len]) {
            len++;
        }
        lps[i] = len;
    }
}

int* String::findAllSubStr(const String &subStr) {
    int *res = new int[length];
    int *lps = new int[subStr.length];
    int count = 0;
    computeLPSArray(subStr, lps);

    int j = 0;
    for (int i = 0; i < length; i++) {
        while (j > 0 && chars[i] != subStr[j]) {
            j = lps[j - 1];
        }
        if (chars[i] == subStr[j]) {
            j++;
        }
        if (j == subStr.length) {
            res[count++] = i - j + 1;
            j = lps[j - 1];
        }
    }

    int *final_res = new int[count];
    for (int i = 0; i < count; i++) {
        final_res[i] = res[i];
    }
    delete[] res;
    delete[] lps;
    return final_res;
}

int String::findFirstSubStr(const String &subStr) {
    int *lps = new int[subStr.length];
    computeLPSArray(subStr, lps);

    int j = 0;
    for (int i = 0; i < length; i++) {
        while (j > 0 && chars[i] != subStr[j]) {
            j = lps[j - 1];
        }
        if (chars[i] == subStr[j]) {
            j++;
        }
        if (j == subStr.length) {
            delete[] lps;
            return i - j + 1;
        }
    }

    delete[] lps;
    return -1;
}

int String::findLastSubStr(const String &subStr) {
    int *lps = new int[subStr.length];
    computeLPSArray(subStr, lps);

    int j = 0;
    int last_index = -1;
    for (int i = 0; i < length; i++) {
        while (j > 0 && chars[i] != subStr[j]) {
            j = lps[j - 1];
        }
        if (chars[i] == subStr[j]) {
            j++;
        }
        if (j == subStr.length) {
            last_index = i - j + 1;
            j = lps[j - 1];
        }
    }

    delete[] lps;
    return last_index;
}

int* String::findAllSubStrReverse(const String &subStr) {
    int *res = new int[length];
    int *lps = new int[subStr.length];
    int count = 0;
    computeLPSArrayReverse(subStr, lps);

    int j = subStr.length - 1;
    for (int i = length - 1; i >= 0; i--) {
        while (j > 0 && chars[i] != subStr[j]) {
            j = lps[j - 1];
        }
        if (chars[i] == subStr[j]) {
            j--;
        }
        if (j == -1) {
            res[count++] = i + 1;
            j = lps[j + 1];
        }
    }

    int *final_res = new int[count];
    for (int i = 0; i < count; i++) {
        final_res[i] = res[i];
    }
    delete[] res;
    delete[] lps;
    return final_res;
}