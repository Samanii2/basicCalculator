#ifndef OUTPUTClass_H__
#define OUTPUTClass_H__
#include <string>
#include <vector>

class Output
{
    private:
        Output() {}
    public:
    static  void ShowCalculation(const std::string& userInput, const std::vector<std::string>& calculation);
    static  void WelcomeMessage();
    static  void HelpInstructions();
};

#endif