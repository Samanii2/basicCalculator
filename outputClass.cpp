#include <string>
#include <vector>
#include <iostream>
#include "outputClass.h"

void Output::ShowCalculation(const std::string& userInput,const std::vector<std::string>& calculation)
{
    std::cout << "Displaying calculation from string \"" << userInput << "\"" << "\n";
    for (int i = 0 ; i < calculation.size(); i++) 
    {
        std::cout << "calculation[" << i << "] = " << calculation[i] << "\n";
    }
}

void Output::WelcomeMessage()
{
    std::cout << "\n\n\n\n\n\n\n\n\n";
    std::cout << "////////////////////////////////////////\n";
    std::cout << "/// Welcome to the basic calculator! ///\n";
    std::cout << "////////////////////////////////////////\n\n";
}

void Output::HelpInstructions()
{
    std::cout << "Input q, quit or exit to exit calculator. \n";
    std::cout << "Input c, cl or clear to clear calculation. \n";
    std::cout << "Input h, or help to see instructions again. \n";
    std::cout << "Valid operations are + - * / ^ \n\n";
    std::cout << "Start calculating! \n";
}