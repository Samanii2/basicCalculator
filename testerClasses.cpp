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

bool Test::ParanthesisesOnlyOperator(const std::vector<std::string>& calculation)
{
    bool testResult = true;
    for(int i = 0; i < calculation.size(); i++)
    {
        if(calculation[i] == "(")
        {
            std::vector<std::string> validOperators{ "+", "-", "*", "/", "^", "."};
            for(int j = 0; j < validOperators.size(); j++)
            {
                if(calculation[i+1] == validOperators[j] && calculation[i+2] == ")")
                {
                    testResult = false;
                }
            }
        }
    }

    return testResult;
}

bool Test::Paranthesises(const std::vector<std::string>& calculation)
{
    bool testResult = true;
    int leftCount = 0;
    int rightCount = 0;
    for(int i = 0; i < calculation.size(); i++)
    {
        if(calculation[i] == "(")
        {
            leftCount +=1;
            if(calculation[i+1] == ")")
            {
                testResult = false;
                break;
            }
        }

        else if(calculation[i] == ")")
        {
            rightCount +=1;
        }

        if(rightCount > leftCount)
        {
            testResult = false;
            break;
        }
    }

    if(leftCount != rightCount)
    {
        testResult = false;
    }

    return testResult;
}

bool Test::OperatorExpressions(const std::vector<std::string>& calculation)
{
    bool testResult = true;
    std::vector<std::string> validOperators{ "+", "-", "*", "/", "^"};
    for(int i = 0; i < calculation.size(); i++)
    {
        for (int j = 0; j < validOperators.size(); j++)
        {
            if (calculation[i] == validOperators[j])
            {
                for (int k = 0; k < validOperators.size(); k++)
                {
                    if (calculation[i+1] == validOperators[k])
                    {
                        testResult = false;
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return testResult;
}

bool Test::DotTest(const std::vector<std::string>& calculation)
{
    bool testResult = true;
    for (int i = 0; i < calculation.size(); i++)
    {
        if ( calculation[i] == ".")
        {
            testResult = false;
        }
    }

    return testResult;
}