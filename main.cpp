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
    std::string testInput = "5^2 + (,0000000009 + ,0000000001)10000000000";
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
        
        std::vector <std::string>calculation = GetCalculationVector(userInput);

        bool sameAmountCharsInVectorAndInput = Test::CompareCharsFromInputWithCharsInVector(userInput, calculation);
        if (sameAmountCharsInVectorAndInput == false)
        {
            std::cout << "Invalid input, undefined character detected \n";
            continue;
        }
        
        bool operatorIsFirst = Test::FirstInputIsOperator(calculation);
        if (operatorIsFirst == true && !calculationAnswer.empty() && calculation[0] != "." && calculation[0] != ")")
        {
            calculation.insert(calculation.begin(), calculationAnswer);
        }

        calculationAnswer = CalculationAnswer(calculation);

        std::cout << "ans = " << calculationAnswer << '\n';
    }

    return 0;
}



  
