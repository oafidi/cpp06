#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <string>

class ScalarConverter
{
	private:
		static std::string	trim(const std::string& s);
		static double		parseNumber(const std::string &s);
		static void			printInvalid(void);
		static void			printDouble(double val);
		static void			printFloat(double val);
		static void			printInt(double val);
		static void			printChar(double val);
		static void			printPseudoLiteral(const std::string &s);

    public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

		class ValueError : public std::exception
		{
			public:
				const char *what() const throw();
		};

        static void	convert(const std::string &str);
};

#endif