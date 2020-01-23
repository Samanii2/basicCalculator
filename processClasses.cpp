#include <vector>
#include <string>
#include "processClasses.h"
#include <algorithm>
#include "testerClasses.h"
#include "operatorClasses.h"
#include <iostream>

void Process::JoinNumbersAndOperators(std::vector<std::string>& calculation)
{
    Process::HandleFirstOperator(calculation);

    Process::MakeDecimalNumbers(calculation);

    Process::RemoveExtraAddition(calculation);

    Process::MakeNumberNegative(calculation);

    Process::InsertMultiplicationAtParanthesises(calculation);
}

void Process::RemoveExtraAddition(std::vector<std::string>& calculation)
{
    for (int i = 0; i < calculation.size() - 1; i += 1)
    {
        if(calculation[i-1] != "" && calculation[i] == "+" && !Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i+1]))
        {
            std::vector< std::string >::iterator it = calculation.begin() + i;
            std::string joinedNum = Math::GetAdditionResult("0", calculation[i + 1]);

            calculation.erase (it, it + 2);
            calculation.insert (it, joinedNum);
        }
    }
}
void Process::MakeDecimalNumbers(std::vector<std::string>& calculation)
{
    for (int i = 1; i < calculation.size() - 1; i += 1)
    {
        if(calculation[i] == "." && !Test::OnlyNumbers(calculation[i-1]) && Test::OnlyIntegers(calculation[i+1]))
        {
            std::vector< std::string >::iterator it = calculation.begin() + i;
            std::string joinedNum = Math::GetJoinedDecimalNumber("0", calculation[i + 1]);

            calculation.erase (it, it + 2);
            calculation.insert (it, joinedNum);
        }
    }

    for (int i = 1; i < calculation.size(); i += 1)
    {
        if(calculation[i] == "." && Test::OnlyIntegers(calculation[i-1]) && Test::OnlyIntegers(calculation[i+1]))
        {
            std::string decimalNumberResult = Math::GetJoinedDecimalNumber(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;

            calculation.erase (it, it + 3);
            calculation.insert (it, decimalNumberResult);
        }
    }
}

void Process::MakeNumberNegative(std::vector<std::string>& calculation)
{
    for (int i = 0; i < calculation.size() - 1; i += 1)
    {
        if(calculation[i-1] != "" && calculation[i] == "-" && !Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i+1]))
        {
            std::vector< std::string >::iterator it = calculation.begin() + i;
            std::string joinedNum = Math::GetSubtractionResult("0", calculation[i + 1]);

            calculation.erase (calculation.begin() + i, it + 2);
            calculation.insert (calculation.begin() + i, joinedNum);
        }
    }
}

void Process::InsertMultiplicationAtParanthesises(std::vector<std::string>& calculation)
{
    for (int i = 0; i < calculation.size() - 1; i += 1)
    {
        if(calculation[i-1] != "" && calculation[i] == "(" && Test::OnlyNumbers(calculation[i-1]))
        {
            calculation.insert (calculation.begin() + i, "*");  
        }
        else if(calculation[i-1] != "" && calculation[i] == "(" && calculation[i-1] == ")")
        {
            calculation.insert (calculation.begin() + i, "*");  
        }
    }

    for (int i = 0; i < calculation.size() - 1; i += 1)
    {
        if(calculation[i] == ")" && Test::OnlyNumbers(calculation[i+1]))
        {
            calculation.insert (calculation.begin() + i + 1, "*");  
        }
    }
}

void Process::HandleFirstOperator(std::vector<std::string>& calculation)
{
    if (calculation[0] == "." && Test::OnlyIntegers(calculation[1]))
    {
            std::string decimalNumberResult = Math::GetJoinedDecimalNumber("0", calculation[1]);
            calculation.erase (calculation.begin(), calculation.begin() + 2);
            calculation.insert (calculation.begin(), decimalNumberResult);
    }

    else if (calculation[0] == "+" && Test::OnlyNumbers(calculation[1]))
    {
            std::string additionResult = Math::GetAdditionResult("0", calculation[1]);
            calculation.erase (calculation.begin(), calculation.begin() + 2);
            calculation.insert (calculation.begin(), additionResult);
    }

    else if (calculation[0] == "-" && Test::OnlyNumbers(calculation[1]))
    {
            std::string subtractionResult = Math::GetSubtractionResult("0", calculation[1]);
            calculation.erase (calculation.begin(), calculation.begin() + 2);
            calculation.insert (calculation.begin(), subtractionResult);
    }

    else if (calculation[0] == "")
    {
            calculation.erase (calculation.begin());
    }

    else if (calculation[0] == "(")
    {
            calculation.insert (calculation.begin(), "1");
    }
    
}

void Process::RemoveSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void Process::ReplaceCommasToDots(std::string& str)
{
    std::replace(str.begin(), str.end(), ',' , '.');
}