#include <iostream>
#include <string>
int main()
{
    /* code */
    struct
    {
        std::string femaleMessage = "Hi, you are female!";
        std::string maleMessage = "Hi, you are male!";
    } messageStruct;
    std::string gender = "Female";
    std::cout << "Hello, World!" << std::endl;
    if (gender == "You are a Male")
    {
        std::cout << gender << std::endl;
    }
    else if (gender == "Female")
    {
        std::cout << "You are a female" << std::endl;
    }

    return 0;
}
