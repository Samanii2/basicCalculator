#include <string>
#include "operatorClass.h"
#include "convertClass.h"
#include <math.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

std::string Math::GetJoinedDecimalNumber(std::string n1, std::string n2)
{
    try
    {
        std::string resultString = Convert::TwoStringsToDecimalNumberString(n1, n2);   
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }
    
    std::string resultString = Convert::TwoStringsToDecimalNumberString(n1, n2);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

std::string Math::GetSubtractionResult(std::string n1, std::string n2)
{
    try
    {
        boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
        boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }

    boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
    boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    boost::multiprecision::cpp_dec_float_100 result = num1 - num2;

    std::string resultString = Convert::MultiPrecisionFloatToString(result);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

std::string Math::GetAdditionResult(std::string n1, std::string n2)
{
    try
    {
        boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
        boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }
    boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
    boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    boost::multiprecision::cpp_dec_float_100 result = num1 + num2;

    std::string resultString = Convert::MultiPrecisionFloatToString(result);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

std::string Math::GetDivisionResult(std::string n1, std::string n2)
{
    try
    {
        boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
        boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }
    boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
    boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    boost::multiprecision::cpp_dec_float_100 result = num1 / num2;

    std::string resultString = Convert::MultiPrecisionFloatToString(result);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

std::string Math::GetMultiplicationResult(std::string n1, std::string n2)
{
    try
    {
        boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
        boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }
    boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
    boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    boost::multiprecision::cpp_dec_float_100 result = num1 * num2;

    std::string resultString = Convert::MultiPrecisionFloatToString(result);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

std::string Math::GetPowerOfResult(std::string n1, std::string n2)
{
    try
    {
        boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
        boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "Invalid Expression";
    }
    boost::multiprecision::cpp_dec_float_100 num1 = Convert::StringToMultiPrecisionFloat(n1);
    boost::multiprecision::cpp_dec_float_100 num2 = Convert::StringToMultiPrecisionFloat(n2);
    boost::multiprecision::cpp_dec_float_100 result = pow(num1, num2);

    std::string resultString = Convert::MultiPrecisionFloatToString(result);
    if ( resultString.size() > 200)
    {
        return "Error, too large number";
    }
    return resultString;
}

