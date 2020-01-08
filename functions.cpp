#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "operatorClasses.h"
#include "testerClasses.h"
#include "processClasses.h"

//Calculation 

std::string CalculationAnswer(std::vector<std::string> calculation)
{
    Process::JoinNumbersAndOperators(calculation);
    Process::HandleFirstOperator(calculation);

    for (int i = 0; i < calculation.size(); i++)
    {
        if (calculation[i] == "(" )
        {
            std::vector<std::string> paranthesisCalculation;
            int j = i + 1;
            while (calculation[j] != ")")
            {
                paranthesisCalculation.push_back(calculation[j]);
                std::cout << calculation[j] << "\n";
                j += 1;
            }

            calculation.erase (calculation.begin() + i, calculation.begin() + j + 1);
            calculation.insert (calculation.begin() + i, CalculationAnswer(paranthesisCalculation));
        }
    }
    
    for (int i = 1; i < calculation.size(); i += 2 )
    {
        if(calculation[i] == "/" && Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i-1]))
        {
            std::string divisionResult = Math::GetDivisionResult(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;
            calculation.erase (it, it+3);
            calculation.insert (it, divisionResult);
            i -= 2;
        }

        else if(calculation[i] == "*" && Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i-1]))
        {
            std::string multiplicationResult = Math::GetMultiplicationResult(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;
            calculation.erase (it, it+3);
            calculation.insert (it, multiplicationResult);
            i -= 2;
        }

        else if(calculation[i] == "^" && Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i-1]))
        {
            std::string powerOfResult = Math::GetPowerOfResult(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;
            calculation.erase (it, it+3);
            calculation.insert (it, powerOfResult);
            i -= 2;
        }
    }

    for (int i = 1; i < calculation.size(); i += 2 )
    {
        if(calculation[i] == "+" && Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i-1]))
        {
            std::string additionResult = Math::GetAdditionResult(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;
            calculation.erase (it, it+3);
            calculation.insert (it, additionResult);
            i -= 2;
        }
   
        else if(calculation[i] == "-" && Test::OnlyNumbers(calculation[i-1]) && Test::OnlyNumbers(calculation[i-1]))
        {
            std::string subtractionResult = Math::GetSubtractionResult(calculation[i-1], calculation[i+1]);
            std::vector< std::string >::iterator it = calculation.begin() - 1 + i;
            calculation.erase (it, it+3);
            calculation.insert (it, subtractionResult);
            i -= 2;
        }
    }
    return calculation.back();
}

//Get functions

std::vector<std::string> GetCalculationVector(std::string userInput)
{
    std::string operatorOrNumber = "";
    std::vector<std::string> calculation;
    std::vector<char> validOperators{'+','-','*','/', '^','.', '(', ')'};

	for (int i = 0; i < userInput.length(); i++) 
    {
        if (isdigit(userInput[i]))
        {
            operatorOrNumber += userInput[i];
        }

        else if(isdigit(userInput[i-1]))
        {
            calculation.push_back(operatorOrNumber);
            operatorOrNumber = "";
            for(int j = 0; j < validOperators.size(); j++)
            {
                if (userInput[i] == validOperators[j])
                {
                    operatorOrNumber.push_back(userInput[i]);
                    calculation.push_back(operatorOrNumber);
                    operatorOrNumber = "";
                    break;
                }
            } 
        }

        else if (!isdigit(userInput[i]))
        {
            for(int j = 0; j < validOperators.size(); j++)
            {
                if (userInput[i] == validOperators[j])
                {
                    operatorOrNumber.push_back(userInput[i]);
                    calculation.push_back(operatorOrNumber);
                    operatorOrNumber = "";
                    break;
                }
            }    
        }
    }

    if (!operatorOrNumber.empty()) 
    {
        calculation.push_back(operatorOrNumber);
    }
    return calculation;
}

//Prestenters

void ShowCalculation(std::string userInput, std::vector<std::string> calculation)
{
    std::cout << "Displaying calculation from string \"" << userInput << "\"" << "\n";
    for (int i = 0 ; i < calculation.size(); i++) 
    {
        std::cout << "calculation[" << i << "] = " << calculation[i] << "\n";
    }
}
