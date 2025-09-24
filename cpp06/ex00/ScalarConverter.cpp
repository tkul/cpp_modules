#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && literal[1] != '\'')
        return true;
    
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    
    return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    for (size_t i = start; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    size_t dotCount = 0;
    size_t start = 0;
    
    if (withoutF[0] == '+' || withoutF[0] == '-')
        start = 1;
    
    if (start >= withoutF.length())
        return false;
    
    for (size_t i = start; i < withoutF.length(); i++)
    {
        if (withoutF[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (!std::isdigit(withoutF[i]))
            return false;
    }
    return dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t dotCount = 0;
    size_t start = 0;
    
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    for (size_t i = start; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return dotCount == 1;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
            literal == "-inf" || literal == "+inf" || literal == "nan");
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else
    {
        float f = static_cast<float>(value);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "double: " << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::convertFromChar(char c)
{
    double value = static_cast<double>(c);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromInt(int i)
{
    double value = static_cast<double>(i);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromFloat(float f)
{
    double value = static_cast<double>(f);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromDouble(double d)
{
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
    double value;
    
    if (literal == "nanf" || literal == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inff" || literal == "+inf")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inff" || literal == "-inf")
        value = -std::numeric_limits<double>::infinity();
    else
        return;
    
    convertFromDouble(value);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudoLiteral(literal);
    }
    else if (isChar(literal))
    {
        char c;
        if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
            c = literal[1];
        else
            c = literal[0];
        convertFromChar(c);
    }
    else if (isInt(literal))
    {
        long long temp = std::atoll(literal.c_str());
        if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
        {
            double d = std::atof(literal.c_str());
            convertFromDouble(d);
        }
        else
        {
            int i = static_cast<int>(temp);
            convertFromInt(i);
        }
    }
    else if (isFloat(literal))
    {
        float f = static_cast<float>(std::atof(literal.c_str()));
        convertFromFloat(f);
    }
    else if (isDouble(literal))
    {
        double d = std::atof(literal.c_str());
        convertFromDouble(d);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}