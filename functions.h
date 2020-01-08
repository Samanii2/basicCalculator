#include <string>
#include <vector>

//Calculate

std::string CalculationString(std::vector<std::string> calculation);

std::string CalculationAnswer(std::vector<std::string> calculation);

void RemoveSpaces(std::string& str);

void ReplaceCommasToDots(std::string& str);

//Get functions

std::vector <std::string> GetCalculationVector(std::string userInput);

//Presenters

void ShowCalculation(std::string userInput, std::vector<std::string> calculation);
