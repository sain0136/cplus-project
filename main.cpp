#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include "Person.h" // Include the Person class
#include <vector>
using namespace std;

void userInput(string gender, Person &p);
void mainMenu();
void makePerson();
void listPeople();

vector<Person> allCreatedPeoplelist;
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
    Person randomPerson("Random", "Person", 0, 0);
    allCreatedPeoplelist.push_back(randomPerson);
    mainMenu();
    cout << "Bye, " << person.firstname << endl
         << "Who is " << person.age << " years old" << endl;
    cout << "All your data will be cleared " << endl;
    return 0;
}

void userInput(string gender, Person &p) // Passing by refrence here , if you dont you wont be updating object you passed in
{
    string firstname = "";
    string lastname = "";
    int age = 0;
    string doShoutout = "";
    printf("Welcome, your gender was %s \n", gender.c_str()); // makes a c style char pointer since printf is c func
    cout << "Tell us your first name and last name" << endl;
    cin >> firstname >>  lastname;
    cout << "Cool nice to meet you:" << firstname << " " << lastname << endl;
    p.firstname = firstname;
    p.lastname = lastname;
    cout << "Whats your age?" << endl;
    cin >> age;
    p.age = age;
    string ageResponse = "IDK";
    if (age <= 30)
    {
        ageResponse = "a young fool!";
    }
    else if (age >= 31)
    {
        ageResponse = "old as fuck my guy!";
    }
    cout << "Cool you are " << ageResponse << endl;
    cout << "Enter your salary" << endl;
    cin >> p.salary;
    cout << "You have been added" << endl;
    p.toString();
    allCreatedPeoplelist.push_back(p);
    cout << "Would you like a shoutout?" << endl;
    cin >> doShoutout;
    if (doShoutout == "yes")
    {
        p.shoutOut();
    }
    else
    {
        cout << "Ok, bye" << endl;
    }
}

void mainMenu()
{
    string userChoice = "";
    cout << "Main Menu" << endl;
    cout << "1. New Person" << endl;
    cout << "2. List People" << endl;
    cout << "3. Store on file" << endl;
    cout << "4. Store in Postgres" << endl;
    cout << "5. Load from file" << endl;
    cout << "6. Native GUI Mode" << endl;
    cout << "7. Start Web Server - Backend Go" << endl;
    cout << "8. CLI Mode" << endl;
    cout << "9. Cli Mode" << endl;
    cout << "10. Exit" << endl;
    cout << "Choose an option: " << endl;
    cin >> userChoice;
    if (userChoice == "1")
    {
        makePerson();
    }
    else if (userChoice == "2")
    {
        listPeople();
    }
    else if (userChoice == "10")
    {
        cout << "Bye" << endl;
        return;
    }
    else
    {
        cout << "Invalid choice or in dev" << endl;
    }
    mainMenu();
}

void makePerson()
{
    try
    {
        Person person;
        cout << "Enter the person first name: " << endl;
        cin >> person.firstname;
        cout << "Enter the person last name: " << endl;
        cin >> person.lastname;
        cout << "Enter the age: " << endl;
        cin >> person.age;
        cout << "Enter the persons Salary: " << endl;
        cin >> person.salary;
        allCreatedPeoplelist.push_back(person);
    }
    catch (const std::exception &e)
    {
        cout << "Something went wrong" << endl;
        std::cerr << e.what() << '\n';
        clog << e.what() << '\n';
        return;
    }
}

void listPeople()
{
    cout << "There a total of " << allCreatedPeoplelist.size() << " people in the list of created people!" << endl;
    for (int i = 0; i < allCreatedPeoplelist.size(); i++)
    {
        allCreatedPeoplelist[i].toString();
    }
}