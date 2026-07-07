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

std::string ScalarConverter::trim(const std::string &str)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    size_t start = str.find_first_not_of(WHITESPACE);
    size_t end = str.find_last_not_of(WHITESPACE);

    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

bool ScalarConverter::isChar(const std::string &s)
{
    return (s.size() == 1 && !std::isdigit(static_cast<int>(s[0])));
}

bool ScalarConverter::isInt(const std::string &s)
{
    size_t i = 0;

    if (s.empty())
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.size(); i++)
        if (!std::isdigit(static_cast<int>(s[i])))
            return false;
    return true;
}
 
bool ScalarConverter::isFloat(const std::string &s)
{
    bool has_dot = false;
    bool has_digit = false;
    size_t i = 0;

    if (s.empty())
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.size(); i++)
    {
        if (std::isdigit(static_cast<int>(s[i])))
            has_digit = true;
        else if (s[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (s[i] == 'f' && i == s.size() - 1)
            return (has_dot && has_digit);
        else
            return false;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &s)
{
    bool has_dot = false;
    bool has_digit = false;
    size_t i = 0;

    if (s.empty())
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.size(); i++)
    {
        if (std::isdigit(static_cast<int>(s[i])))
            has_digit = true;
        else if (s[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else
            return false;
    }
    return (has_dot && has_digit);
}

bool ScalarConverter::isPseudoLiteral(const std::string &s)
{
    return (s == "-inf" || s == "+inf" || s == "-inff"
            || s == "+inff" || s == "nan" || s == "nanf");
}

void ScalarConverter::printFloat(float f)
{
    if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        std::ostringstream oss;
        oss << f;
        std::string s = oss.str();
        if (s.find('.') == std::string::npos
            && s.find('e') == std::string::npos)
            std::cout << "float: " << s << ".0f" << std::endl;
        else
            std::cout << "float: " << s << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d)
{
    if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::ostringstream oss;
        oss << d;
        std::string s = oss.str();
        if (s.find('.') == std::string::npos
            && s.find('e') == std::string::npos)
            std::cout << "double: " << s << ".0" << std::endl;
        else
            std::cout << "double: " << s << std::endl;
    }
}

void ScalarConverter::printPseudoLiteral(const std::string &s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::string sign = (s == "+inf" || s == "+inff") ? "+" : "-";
        std::cout << "float: " << sign << "inff" << std::endl;
        std::cout << "double: " << sign << "inf" << std::endl;
    }
}

void ScalarConverter::printInvalid(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printAll(char c)
{
    if (std::isprint(static_cast<int>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::printAll(int i)
{
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::printAll(float f)
{
    if (std::isinf(f) || f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (std::isinf(f)
        || f < static_cast<float>(std::numeric_limits<int>::min())
        || f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::printAll(double d)
{
    if (std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (std::isinf(d)
        || d < static_cast<double>(std::numeric_limits<int>::min())
        || d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::convert(const std::string &s)
{
    std::string str = trim(s);

    if (isPseudoLiteral(str))
        printPseudoLiteral(str);
    else if (isChar(str))
        printAll(str[0]);
    else if (isInt(str))
    {
        char *end;
        long lval = std::strtol(str.c_str(), &end, 10);

        if (*end != '\0'
            || lval < std::numeric_limits<int>::min()
            || lval > std::numeric_limits<int>::max())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            double d = std::strtod(str.c_str(), NULL);
            printFloat(static_cast<float>(d));
            printDouble(d);
            return ;
        }
        printAll(static_cast<int>(lval));
    }
    else if (isFloat(str))
        printAll(static_cast<float>(std::strtod(str.c_str(), NULL)));
    else if (isDouble(str))
        printAll(std::strtod(str.c_str(), NULL));
    else
        printInvalid();
}