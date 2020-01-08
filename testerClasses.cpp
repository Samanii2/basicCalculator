#include <string>
#include <vector>
#include "testerClasses.h"

bool Test::OnlyNumbers(const std::string s)
{
    bool testResult = s.find_first_not_of( "0123456789.-" ) == std::string::npos;
    if (s == "." || s == "-")
    {
        testResult = false;
    }

    return testResult;
}

bool Test::OnlyIntegers(const std::string s)
{
    bool testResult = s.find_first_not_of( "0123456789" ) == std::string::npos;

    return testResult;
}

bool Test::FirstInputIsOperator(const std::vector<std::string>& calculation)
{
    std::vector<std::string> validOperators{ "+", "-", "*", "/", "^", ".", "(", ")" };

    bool testResult = false;

    for (int i = 0; i < validOperators.size(); i++)
    {
        if (calculation[0] == validOperators[i])
        {
            testResult = true;
        }
            
    }

    return testResult;
}

bool Test::CompareCharsFromInputWithCharsInVector(const std::string& userInput, const std::vector<std::string>& calculation)
{
    int charsInVector = 0;
    for(int i = 0; i < calculation.size(); ++i) 
    {
    charsInVector += calculation[i].size();
    }

    int charsInString = userInput.size();

    return charsInVector == charsInString;
}

///////////////////////////////////////////////////////7
////////////TODO parathesis testers, . - + testers
//////////////////////////////////////////////////////////
