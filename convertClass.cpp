#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "convertClass.h"
#include <boost/multiprecision/cpp_dec_float.hpp>

std::string Convert::MultiPrecisionFloatToString(boost::multiprecision::cpp_dec_float_100 mpFloat)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::digits) << mpFloat;
    std::string result = stream.str();

    return result;    
}

boost::multiprecision::cpp_dec_float_100 Convert::StringToMultiPrecisionFloat(const std::string s)
{
    std::stringstream stream;
    stream << s;
    boost::multiprecision::cpp_dec_float_100 result;
    stream >> result;

    return result;
}

std::string Convert::TwoStringsToDecimalNumberString(const std::string num1, const std::string num2)
{
std::stringstream stream;
stream << num1 << "." << num2;
std::string result;
stream >> result;

return result;
}
