#include <string>
#include <vector>
#include <iostream>
#include "functions.h"
#include "testerClasses.h"
#include "processClasses.h"

int main()
{
    //////////////////////////////////////////////////////
    ///Test case /////////////////////////////////////////
    //////////////////////////////////////////////////////
    std::string testAnswer = "0";
    std::string testInput = "5^2 + ((2))(,0000000009 + ,0000000001)10000000000";
    Process::RemoveSpaces(testInput);
    Process::ReplaceCommasToDots(testInput);
    std::vector <std::string>testCalculation = GetCalculationVector(testInput);
        
    ShowCalculation(testInput, testCalculation);

    bool testOperatorIsFirst = Test::FirstInputIsOperator(testCalculation);
    if (testOperatorIsFirst == true && !testAnswer.empty() && testCalculation[0] != ".")
    {
        testCalculation.insert(testCalculation.begin(), testAnswer);
    }

    ShowCalculation(testInput, testCalculation);

    Process::JoinNumbersAndOperators(testCalculation);
    testAnswer = CalculationAnswer(testCalculation);
    std::cout << "ans = " << testAnswer << '\n';


    //////////////////////////////////////////////////////
    ///User case /////////////////////////////////////////
    //////////////////////////////////////////////////////

    std::cout << "Welcome to the basic calculator!\n Start calculations: ";

    std::string userInput = "";
    std::string calculationAnswer = "0";

    while (userInput != "quit")
    {
        std::getline(std::cin, userInput);
        Process::RemoveSpaces(userInput);
        Process::ReplaceCommasToDots(userInput);

        if (userInput == "q" || userInput == "exit" || userInput == "quit")
        {
            std::cout << "Exiting calculator...\n";
            break;
        }

        if (userInput.empty() == true)
        {
            continue;
        }
        
        if (userInput == "c" || userInput == "cl" || userInput == "clear")
        {
            calculationAnswer = "0";
            std::cout << "Clearing...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            continue;
        }
        std::vector <std::string>calculation = GetCalculationVector(userInput);

        bool sameAmountCharsInVectorAndInput = Test::CompareCharsFromInputWithCharsInVector(userInput, calculation);
        if (sameAmountCharsInVectorAndInput == false)
        {
            std::cout << "Invalid input, undefined character detected \n";
            continue;
        }

        if (calculation[0] == "." && calculation.size() == 1)
        {
            std::cout << "Invalid input, lone decimal operator \n";
            continue; 
        }

        bool validParanthesises = Test::Paranthesises(calculation);
        if (validParanthesises == false)
        {
            std::cout << "Invalid input, invalid paranthesis input \n";
            continue;
        }

        bool validParanthesisInside = Test::ParanthesisesOnlyOperator(calculation);
        if (validParanthesisInside == false)
        {
            std::cout << "Invalid input, invalid expression inside paranthesis \n";
            continue;
        }

        bool operatorIsFirst = Test::FirstInputIsOperator(calculation);
        if (operatorIsFirst == true && calculation.size() == 1)
        {
            std::cout << "Invalid input, operator without number \n";
            continue; 
        }

        if (operatorIsFirst == true)
        {
            calculation.insert(calculation.begin(), calculationAnswer);
        }

        Process::JoinNumbersAndOperators(calculation);

        bool dotTest = Test::DotTest(calculation);
        if (dotTest == false)
        {
            std::cout << "Invalid input, too many dots \n";
            continue;
        }

        bool operatorExpression = Test::OperatorExpressions(calculation);
        if (operatorExpression == false)
        {
            std::cout << "Invalid input, operators in invalid sequence \n";
            continue;
        }

        calculationAnswer = CalculationAnswer(calculation);

        std::cout << "ans = " << calculationAnswer << '\n';
    }

    return 0;
}



  
