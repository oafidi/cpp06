#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <limits>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static std::string  trim(const std::string &s);
        static bool         isChar(const std::string &s);
        static bool         isInt(const std::string &s);
        static bool         isFloat(const std::string &s);
        static bool         isDouble(const std::string &s);
        static bool         isPseudoLiteral(const std::string &s);

        static void         printFloat(float f);
        static void         printDouble(double d);
        static void         printAll(char c);
        static void         printAll(int i);
        static void         printAll(float f);
        static void         printAll(double d);
        static void         printPseudoLiteral(const std::string &s);
        static void         printInvalid(void);

    public:
        static void convert(const std::string &s);
};

#endif