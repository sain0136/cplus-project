#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    string firstname;
    string lastname;
    int age;
    double salary;
    /**
     * Default constructor for the Person class.
     *
     * @param paramName description of parameter
     *
     * @return description of return value
     *
     * @throws ErrorType description of error
     */
    Person() : firstname(""), lastname(""), age(0), salary(0.0)
    {
        clog << "User Created Using Default Constructor" << endl;
    }
    /**
     * Constructor for the Person class.
     *
     * @param n the name of the person
     * @param a the age of the person
     * @param s the salary of the person
     *
     * @throws None
     */
    Person(std::string fn, std::string ln, int a, float s) : firstname(fn), lastname(ln), age(a), salary(s)
    {
        clog << "User Created Using Parameterized Constructor" << endl;
    }
    /**
     * Destructor for the Person class.
     *
     * @return None
     *
     * @throws None
     */
    ~Person()
    {
        clog << "User Destroyed" << endl;
    }

    void shoutOut()
    {
        cout << "Shout to the people!!!" << endl;
    }

    void toString()
    {
        cout << firstname << " " << lastname << " " << age << " " << salary << endl;
    }
};

#endif
