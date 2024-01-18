#include "Person.h"
// Initialization Lists: Both constructors use initialization lists (: syntax), which is an efficient way of initializing class members.

Person::Person() : firstname(""), lastname(""), age(0), salary(0.0), mainUser(false)
{
    std::clog << "User Created Using Default Constructor" << std::endl;
}
Person::Person(std::string fn, std::string ln, int a, double s, bool mainUser) : firstname(fn), lastname(ln), age(a), salary(s), mainUser(mainUser)
{
    std::clog << "User Created Using Parameterized Constructor" << std::endl;
}

Person::~Person()
{
    std::clog << "User Destroyed" << std::endl;
}

void Person::shoutOut()
{
    std::cout << "Shout to the people!!!" << std::endl;
}

void Person::toString()
{
    std::cout << firstname << " " << lastname << " " << age << " $" << salary << std::endl;
}

std::string Person::serialize() const
{
    return firstname + "," + lastname + "," + std::to_string(age) + "," + std::to_string(salary) + "," + (mainUser ? "1" : "0");
};

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

Person* Person::deserialize(std::string serialized)
{
    Person *person = new Person();
    std::vector<std::string> tokens = split(serialized, ',');
    person->firstname = tokens[0];
    person->lastname = tokens[1];
    person->age = std::stoi(tokens[2]);
    person->salary = std::stod(tokens[3]);
    person->mainUser = tokens[4] == "1" ? true : false;

    return person;
}
