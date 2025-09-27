#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstring>

class ScalarConverter 
{
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};