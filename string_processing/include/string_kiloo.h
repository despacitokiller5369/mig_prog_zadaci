#pragma once

#include <iostream>

using namespace std;

class String {
	char *chars;
	unsigned int length;

public:
	String();
	String(const char *other);
	String(const String &other);
	~String();
	String operator=(const char *other);
	String operator=(const String &other);
	char& operator[](int index);
	friend ostream& operator<<(ostream &o, const String &other);

	// Implement KMP on the whole string
	int *findAllSubStr(const String &subStr);

	// Implement KMP until the first match
	int findFirstSubStr(const String &subStr);

	// Implement KMP in reverse (search from the end of both strings).
	// The lookup table should be done from last character
	int findLastSubStr(const String &subStr);

	int *findAllSubStrReverse(const char *subStr);
};