#include "string_kiloo.h"

using namespace std;

String::String() {
    length = 0;
    chars = nullptr;
};

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
};

String::~String() {
    delete[] chars;
};

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
};

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
};

char& String::operator[](int index) {
	if (index < 0 || index >= length) {
		throw out_of_range("Index out of range!");
	}
	return chars[index];
};

ostream& operator<<(ostream &o, const String &other) {
	for (unsigned int i = 0; i < other.length; i++) {
		o << other.chars[i];
	}
	return o;
};

int* String::findAllSubStr(const String &subStr) {
    
};