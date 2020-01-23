#ifndef OPERATORCLASSES_H__
#define OPERATORCLASSES_H__
#include <string>

class Math
{
    private:
        Math() {}
    public:
        static  std::string GetJoinedDecimalNumber(std::string n1, std::string n2);
        static  std::string GetSubtractionResult(std::string n1, std::string n2);
        static  std::string GetAdditionResult(std::string n1, std::string n2);
        static  std::string GetDivisionResult(std::string n1, std::string n2);
        static  std::string GetMultiplicationResult(std::string n1, std::string n2);
        static  std::string GetPowerOfResult(std::string n1, std::string n2);
};

#endif