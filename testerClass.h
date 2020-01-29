#ifndef TESTClass_H__
#define TESTClass_H__
#include <string>

class Test
{
    private:
        Test() {}
    public:
        static  bool OnlyNumbers(const std::string s);
        static  bool OnlyIntegers(const std::string s);
        static  bool OnlyLetters(const std::string s);
        static  bool FirstInputIsOperator(const std::vector<std::string>& calculation);
        static  bool CompareCharsFromInputWithCharsInVector(const std::string& userInput, const std::vector<std::string>& calculation);
        static  bool Paranthesises(const std::vector<std::string>& calculation);
        static  bool ParanthesisesOnlyOperator(const std::vector<std::string>& calculation);
        static  bool OperatorExpressions(const std::vector<std::string>& calculation);
        static  bool DotTest(const std::vector<std::string>& calculation);
};

#endif