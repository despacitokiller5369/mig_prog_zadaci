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

	String operator+(const char *other);
	String operator+(const String &other);
	String operator=(const char *other);
	String operator=(const String &other);
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;
	friend ostream& operator<<(ostream &o, const String &other);

	void computeLPSArray(const String &subStr, int lps[]);
	void computeLPSArrayReverse(const String &subStr, int lps[]);

	int* findAllSubStr(const String &subStr);
	int findFirstSubStr(const String &subStr);
	int findLastSubStr(const String &subStr);
	int* findAllSubStrReverse(const String &subStr);

	int* rabinKarpSum(const String &subStr);
	int* rabinKarpPow(const String &subStr); 
};