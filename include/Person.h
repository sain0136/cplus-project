/*
Person.h file will contain the class definition (declarations of the class and its members)
but not the full implementation of the methods. It's placed in the include directory.
*/
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class Person
{
public:
    std::string firstname;
    std::string lastname;
    int age;
    double salary;
    bool mainUser = false;

    /**
     * Default constructor for the Person class.
     *
     * @param paramName description of parameter
     *
     * @return description of return value
     *
     * @throws ErrorType description of error
     */
    Person();

    /**
     * Constructor for the Person class.
     *
     * @param n the name of the person
     * @param a the age of the person
     * @param s the salary of the person
     *
     * @throws None
     */
    Person(std::string fn, std::string ln, int a, double s, bool mu = false);
    /**
     * Destructor for the Person class.
     *
     * @return None
     *
     * @throws None
     */
    ~Person();

    void shoutOut();
    void toString();
    std::string serialize() const; // Serialization function declaration
    static Person* deserialize(std::string serialized);
};

#endif
