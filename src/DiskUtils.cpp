#include "DiskUtils.h"

void writeToFile(const std::vector<Person *> &people, const std::string filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &person : people)
        {
            file << person->serialize() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

std::vector<Person *> loadPeopleFromFile(const std::string filename)
{
    std::ifstream file(filename);
    std::vector<Person *> people;
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            Person *person = Person::deserialize(line);
            people.push_back(person);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return people;
}