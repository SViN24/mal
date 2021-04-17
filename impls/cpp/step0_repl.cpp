#include <iostream>
#include <string>

#include "linenoise.hpp"

std::string READ(std::string input){ return input; }

std::string EVAL(std::string input){ return input; }

std::string PRINT(std::string input){ return input; }

std::string rep(std::string input)
{ 
    auto readline = READ(input);
    auto result = EVAL(readline);
    return PRINT(result);
}


int main()
{

    const auto histpath = "malhist";

    linenoise::SetHistoryMaxLen(4);
    linenoise::LoadHistory(histpath);

    std::string input;

    for(;;)
    {

        auto quit = linenoise::Readline("user> ", input);
        if (quit)
            break;

        linenoise::AddHistory(input.c_str());
        std::cout << rep(input) << std::endl;
    }
    linenoise::SaveHistory(histpath);
    return 0; 
}
