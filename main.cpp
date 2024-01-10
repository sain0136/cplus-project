#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

struct Person
{
    string name;
    int age;
    float salary;
};

void userInput(string gender, Person &p);
int main()
{
    /* code */
    Person person;
    srand(time(NULL));
    int token = rand() % 2 + 1;
    struct
    {
        string femaleMessage = "Hi, Lady!";
        string maleMessage = "Hey Bro!";
        string gender = "";
    } messageStruct;

    messageStruct.gender = (token == 1) ? "Female" : "Male";
    cout << "Hello, World!" << endl;
    if (messageStruct.gender == "Male")
    {
        cout << messageStruct.maleMessage << endl;
    }
    else if (messageStruct.gender == "Female")
    {
        cout << messageStruct.femaleMessage << endl;
    }
    userInput(messageStruct.gender, person);
    cout << "Bye, " << person.name << endl;
    return 0;
}

void userInput(string gender, Person &p) // Passing by refrence here cool
{
    string name = "";
    printf("Welcome, your gender was %s \n", gender.c_str()); // makes a c style char pointer since printf is c func
    cout << "Tell us your fullname" << endl;
    cin >> name;
    cout << "Cool nice to meet you:" << name << endl;
    p.name = name;
}
