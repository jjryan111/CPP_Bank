#pragma once
#include <iostream>
#include <ctype.h>  // isdigit()
#include <sstream>  // stringstream
#include <string>
using namespace std;

class ValidNum
{
private:

public:
	ValidNum();
	~ValidNum();
	bool validNumber(string user_string_num);
	void clearInput();
	int validateEntry(string msg);
	double validateEntry(string msg, double transaction);
};

