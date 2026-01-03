#ifndef FIXEDSIZESTACKAPP_HPP
#define FIXEDSIZESTACKAPP_HPP

#include "FixedSizeStack.hpp"
#include <string>
#include <iostream>

namespace FixedSizeStackSpace
{
 
std::string ReverseString(std::string str)
{
    FixedSizeStack<char> stack(100);
    char symbol;

    std::string str_reverse;

    for(int i=0; i<str.size(); i++)
    {
        stack.push((char)str[i]);
    }
    
    

    for(int i=0; i<str.size(); i++)
    {
        stack.pop(symbol);
        str_reverse += symbol;
    }
    return str_reverse;
}

void Demo()
{
    std::string str;

    std::cout << "ENTER THE STRING TO BE REVERSED" << std::endl;

    std::cin >> str;

    std::cout << "INPUT STRING : " << str << std::endl;

    std::cout << "REVERSED STRING : " << ReverseString(str) << std::endl;

}


}
#endif
