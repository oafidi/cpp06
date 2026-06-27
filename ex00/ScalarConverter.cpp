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

const char *ScalarConverter::ValueError::what() const throw()
{
    return "Invalid Number";
}

std::string ScalarConverter::trim(const std::string& str)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    size_t start = str.find_first_not_of(WHITESPACE);
    size_t end = str.find_last_not_of(WHITESPACE);

    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

double ScalarConverter::parseNumber(const std::string& str)
{
    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (str.empty())
        throw ValueError();
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
            hasDigit = true;
        else if (str[i] == '.')
        {
            if (hasDot)
                throw ValueError();
            hasDot = true;
        }
        else if (str[i] == 'f' && i == str.size() - 1)
            break;
        else
            throw ValueError();
    }
    if (!hasDigit)
        throw ValueError();

    return std::strtod(str.c_str(), NULL);
}

void ScalarConverter::printChar(double d)
{
    std::cout << "char: ";

    if (d < 0 || d > 127)
        std::cout << "Impossible\n";
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::convert(const std::string &s)
{
    double value;
    std::string str = trim(s);

    if (str.length() == 1  && !std::isdigit(str[0]))
        value = static_cast<double>(str[0]);
    else if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nan" || str == "nanf")
        return printPseudoLiteral(str);
    else
    {
        try
        {
            value = parseNumber(str);
        }
        catch (std::exception &e)
        {
            return printInvalid();
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}