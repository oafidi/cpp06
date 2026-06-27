#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

int is_digits(std::string& str)
{
    bool dd = true;

    if ()
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}

void ScalarConverter::convert(const std::string &str)
{
    double value;

    if (str.length() == 1  && !std::isdigit(str[0]))
        value = static_cast<double>(value);
    else if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nan")
        return ; // call a function that print directly
    else if (str[])
}