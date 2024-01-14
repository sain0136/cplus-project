#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "Person.h" // Include the Person class

using namespace std;

// Function Prototypes
void makeDefaultUser(string gender, Person &p);
void guessAndDisplayGender();
void makeRandomUser();
void mainMenu();
void makePerson();
void listPeople();
void pauseThread(int seconds, string message);
void makePersonWithPointer();
void deleteAllPersonPointers();
void clearScreen();
void makeRandomUser();
void guessAndDisplayGender();
void writeToFile(const vector<Person *> &people, const string filename);

// Global Variables
vector<Person> allCreatedPeoplelist;
vector<Person *> allCreatedPersonPointers;
struct
{
    string femaleMessage = "Hi, Soul Sister!";
    string maleMessage = "Hey, Brother!";
    string gender = "";
} randomMessage;
int main()
{
    /* code */
    string skipIntro = "n";
    cout << "Do you want to skip intro? (y/n)" << endl;
    cin >> skipIntro;
    makeRandomUser();
    if (skipIntro == "y")
    {
        mainMenu();
    }
    clearScreen();
    Person person;
    guessAndDisplayGender();
    makeDefaultUser(randomMessage.gender, person);
    mainMenu();
    cout << "Bye, " << person.firstname << endl
         << "Who is " << person.age << " years old" << endl;
    cout << "All your data will be cleared " << endl;
    deleteAllPersonPointers();
    return 0;
}
/**
 * Writes the vector of Person pointers to a file.
 *
 * @param people The vector of Person pointers to be written to file. -
 * constant reference to a vector of pointers to Person objects.
 * The const indicates that the vector should not be modified inside the function.
 * Pointers are used to refer to Person objects
 * @param filename The name of the file to which the data will be written.
 *
 * @throws ErrorType A description of the error that can occur during the writing process.
 */
void writeToFile(const vector<Person *> &people, const string filename)
{
}

void makeRandomUser()
{
    Person *randomPerson = new Person("Random", "Person", 0, 0);
    allCreatedPersonPointers.push_back(randomPerson);
}

void guessAndDisplayGender()
{
    srand(time(NULL));
    int token = rand() % 2 + 1;
    randomMessage.gender = (token == 1) ? "Female" : "Male";
    cout << "Hello, Welcome To My C++ Program - IMU Verdavity" << endl;
    pauseThread(3, "Loading... I am gussing your gender!");
    if (randomMessage.gender == "Male")
    {
        cout << randomMessage.maleMessage << endl;
    }
    else if (randomMessage.gender == "Female")
    {
        cout << randomMessage.femaleMessage << endl;
    }
    pauseThread(2, "Was I right? Lol now make me a user! ..You!");
}

void makeDefaultUser(string gender, Person &p) // Passing by refrence here , if you dont you wont be updating object you passed in
{
    string firstname = "";
    string lastname = "";
    int age = 0;
    string doShoutout = "";
    printf("Welcome, your gender guess was %s \n", gender.c_str()); // makes a c style char pointer since printf is c func
    cout << "Now, enter your first name and last name" << endl;
    cin >> firstname >> lastname;
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
    pauseThread(3, "Ok, you are all set! Saving data...");
    clearScreen();
    p.toString();
    Person *defaulUserPtr = &p;
    allCreatedPersonPointers.push_back(defaulUserPtr);
    cout << "Would you like a shoutout? Type yes or y" << endl;
    cin >> doShoutout;
    if (doShoutout == "yes" || doShoutout == "y")
    {
        p.shoutOut();
    }
    else
    {
        cout << "Ok, bye no shoutout!" << endl;
    }
    pauseThread(3, "Ok redirecting to main menu");
    clearScreen();
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
    clearScreen();
    if (userChoice == "1")
    {
        makePersonWithPointer();
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
// Not used anymore because of pointers practice in C++
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "There a total of " << allCreatedPersonPointers.size() << " people in the list of created people!" << endl;
    cout << "\n";
    for (int i = 0; i < allCreatedPersonPointers.size(); i++)
    {
        cout << "\n";
        cout << i + 1 << ". ";
        allCreatedPersonPointers[i]->toString();
        cout << "\n";
    }
    string userChoice = "NO";
    cout << "Press enter to continue" << endl;
    while (userChoice != "")
    {
        getline(cin, userChoice);
    }
    pauseThread(3, "Redirecting to main menu");
    clearScreen();
}

void pauseThread(int seconds, string message)
{
    cout << message << endl;
    // Simulating some processing time
    this_thread::sleep_for(chrono::seconds(seconds));
}

void makePersonWithPointer()
{
    try
    {
        Person *person = new Person;
        cout << "Enter the person first name: " << endl;
        cin >> person->firstname;
        cout << "Enter the person last name: " << endl;
        cin >> person->lastname;
        cout << "Enter the age: " << endl;
        cin >> person->age;
        cout << "Enter the persons Salary: " << endl;
        cin >> person->salary;

        allCreatedPersonPointers.push_back(person);
    }
    catch (const std::exception &e)
    {
        cout << "Something went wrong" << endl;
        std::cerr << e.what() << '\n';
        clog << e.what() << '\n';
        return;
    }
}

/**
 * Deletes all the Person pointers in the allCreatedPersonPointers list.
 * This deletes each Person object and removes all pointers from the vector.
 * After this, you can safely let the vector go out of scope or delete it.
 * @throws None
 */
void deleteAllPersonPointers()
{
    for (Person *person : allCreatedPersonPointers)
    {
        delete person;
    }
    allCreatedPeoplelist.clear();
}

void clearScreen()
{
    system("cls");
}