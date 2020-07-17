#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
#include"Tree.h"

class ViolationsList
{
	std::string violation, idx;
	int number = 0;
	tree<int, ViolationsList> tree_car;

public:
	ViolationsList() = default;
	ViolationsList(int number, const std::string& viol) : number(number), violation(viol)
	{}

	std::string to_string() const;
	void from_string(const std::string& str);

	void to_binary(std::ostream& out);
	void from_binary(std::istream& in);

	int key() { return number; }

	friend std::ostream& operator<<(std::ostream& out, const ViolationsList& object);
	friend std::istream& operator>>(std::istream& in, ViolationsList& object);
};
