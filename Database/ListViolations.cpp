#include "ListViolations.h"

std::ostream& operator<<(std::ostream& out, const ViolationsList& object)
{
	out << object.to_string();
	return out;
}

std::istream& operator>>(std::istream& in, ViolationsList& object)
{
	std::string tmp;
	getline(in, tmp);
	object.from_string(tmp);
	return in;
}


std::string ViolationsList::to_string() const
{
	std::ostringstream oss;
	oss << "номер т/з : " << std::setw(10) << std::left << number << "порушення: " << std::setw(30) << std::left << violation << std::setw(30);
	return oss.str();
}

void ViolationsList::from_string(const std::string& str)
{
	std::istringstream iss(str);
	iss >> number >> violation;
}

void ViolationsList::to_binary(std::ostream& out)
{
	size_t length;
	out.write((char*)&number, sizeof(number));
	length = violation.size();
	out.write((char*)&length, sizeof(size_t));
	out.write(violation.c_str(), length);
}

void ViolationsList::from_binary(std::istream& in)
{
	size_t length;
	in.read((char*)&number, sizeof(number));
	in.read((char*)&length, sizeof(length));
	violation = std::string(length, '\0');
	in.read((char*)violation.data(), length);
}
