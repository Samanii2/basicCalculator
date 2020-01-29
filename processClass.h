#ifndef PROCESSClass_H__
#define PROCESSClass_H__
#include <string>

class Process
{
    private:
        Process() {}
    public:
        static  void JoinNumbersAndOperators(std::vector<std::string>& calculation);
        static  void HandleFirstOperator(std::vector<std::string>& calculation);
        static  void InsertMultiplicationAtParanthesises(std::vector<std::string>& calculation);
        static  void MakeNumberNegative(std::vector<std::string>& calculation);
        static  void MakeDecimalNumbers(std::vector<std::string>& calculation);
        static  void RemoveExtraAddition(std::vector<std::string>& calculation);
        static  void RemoveSpaces(std::string& str);
        static  void ReplaceCommasToDots(std::string& str);
};

#endif