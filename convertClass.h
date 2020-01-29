#ifndef CONVERTClass_H__
#define CONVERTClass_H__
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

class Convert
{
    private:
        Convert() {}
    public:
        static std::string TwoStringsToDecimalNumberString(const std::string num1, const std::string num2);
        static std::string MultiPrecisionFloatToString(boost::multiprecision::cpp_dec_float_100 mpFloat);
        static boost::multiprecision::cpp_dec_float_100 StringToMultiPrecisionFloat(const std::string s);
        
};

#endif