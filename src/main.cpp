#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "Person.h"
#include "DiskUtils.h"
using namespace std;

// Function Prototypes
void makeDefaultUser(string gender, Person &p);
void makeRandomUser();
void mainMenu();
void makePerson();
void listPeople();
void pauseThread(int seconds, string message);
void makePersonWithPointer();
void deleteAllPersonPointers();
void clearScreen();
void makeRandomUser();
void writeToDisk();
void wrongInputMessage(string message);
void readPeopleFromFile();
void intro();

// Global Variables
vector<Person> allCreatedPeoplelist;
vector<Person *> allCreatedPersonPointers;
struct
{
    string femaleMessage = "Hi, Soul Sister!";
    string maleMessage = "Hey, Brother!";
    string gender = "";
} genderStruct;

int main()
{
    intro();
    mainMenu();
    deleteAllPersonPointers();
    return 0;
}

/**
 * Displays the main menu and processes user input to execute various options.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void mainMenu()
{
    clearScreen();
    string userChoice = "";
    cout << endl
         << "----------------------------" << endl;
    cout << endl
         << "      Main Menu   " << endl;
    cout << endl
         << "----------------------------" << endl;
    cout << "1. New Person" << endl;
    cout << "2. List People" << endl;
    cout << "3. Store on file" << endl;
    cout << "4. Store in Postgres" << endl;
    cout << "5. Load from file" << endl;
    cout << "6. Native GUI Mode" << endl;
    cout << "7. Start Web Server - Backend Go" << endl;
    cout << "8. CLI Mode" << endl;
    cout << "9. Exit" << endl;
    cout << "Choose an option: " << endl;
    cin >> userChoice;
    clearScreen();

    switch (stoi(userChoice))
    {
    case 1:
        makePersonWithPointer();
        break;
    case 2:
        listPeople();
        break;
    case 3:
        writeToDisk();
        break;
    case 5:
        readPeopleFromFile();
        break;
    case 9:
        deleteAllPersonPointers();
        pauseThread(3, "Good Bye");
        exit(0);
        break;
    default:
        cout << "Invalid choice or in dev" << endl;
        break;
    }
    mainMenu();
}

/**
 * Reads people from a file and loads them into memory.
 *
 * @return void
 *
 * @throws ErrorType none
 */
void readPeopleFromFile()
{
    clearScreen();
    cout << "Reading from file" << endl;
    pauseThread(2, "Loading...");
    deleteAllPersonPointers();
    allCreatedPersonPointers = loadPeopleFromFile("people.txt");
    cout << "People loaded" << endl;
    pauseThread(3, "Redirecting to main menu");
    mainMenu();
}

/**
 * Prints a message indicating wrong input.
 *
 * @param message optional additional message to display
 *
 */
void wrongInputMessage(string message = "")
{
    cout << "Wrong input! " << message << endl;
}

/**
 * Writes data to disk after user confirmation.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void writeToDisk()
{
    clearScreen();
    cout << "Writing to disk will overwrite previous data. Are you sure?" << endl;
    string userChoice = "";
    cout << "Press enter to Yes/Y and No/N to return" << endl;
    while (userChoice != "y" || userChoice != "Yes")
    {
        getline(cin, userChoice);

        if (userChoice == "No" || userChoice == "N" || userChoice == "n")
        {
            pauseThread(3, "Redirecting to main menu");
            mainMenu();
            return;
        }
        if (userChoice == "Yes" || userChoice == "Y" || userChoice == "y")
        {
            break;
        }
        wrongInputMessage("Try again");
    }
    writeToFile(allCreatedPersonPointers, "people.txt");
    pauseThread(3, "Written to disk. Redirecting to main menu");
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

/**
 * Function to list all the created people and display them on the screen.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void listPeople()
{
    clearScreen();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
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
    getline(cin, userChoice);
    while (userChoice != "")
    {
        wrongInputMessage("Try again");
        getline(cin, userChoice);
    }
    pauseThread(3, "Redirecting to main menu");
    clearScreen();
}

/**
 * Pauses the current thread for the specified amount of time and prints a message.
 *
 * @param seconds the number of seconds to pause the thread
 * @param message the message to be printed
 *
 * @return void
 *
 * @throws None
 */
void pauseThread(int seconds, string message)
{
    cout << message << endl;
    // Simulating some processing time
    this_thread::sleep_for(chrono::seconds(seconds));
}

/**
 * Creates a new Person object using pointers, takes user input for the person's first name, last name, age, and salary, and adds the pointer to the allCreatedPersonPointers vector.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::exception if something goes wrong during the process
 */
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

/**
 * Clears the screen by executing the system command "cls".
 */
void clearScreen()
{
    system("cls");
}

/**
 * This code is used to create a default user and assign it to a Person object.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void intro()
{
    clearScreen();
    makeRandomUser();
    string skipIntro = "N";
    cout << "Do you want to skip default user intro? (Y/N)" << endl;
    cin >> skipIntro;
    while (skipIntro != "y" && skipIntro != "Y" && skipIntro != "n" && skipIntro != "N")
    {
        wrongInputMessage("Please enter Y or N");
        cin >> skipIntro;
    }
    if (skipIntro == "y" || skipIntro == "Y")
    {
        genderStruct.gender = "male";
        mainMenu();
    }
    clearScreen();
    // This code is used to create a default user and assign it to a Person object.

    // Create a Person object on the stack.
    // The 'Person' keyword is the name of the class, and 'person' is the name of the object being created.
    // The parentheses after 'Person' indicate that the constructor is being called with no arguments.
    Person person;
    cout << "What is your gender? (male/female)" << endl;
    cin >> genderStruct.gender;
    while (genderStruct.gender != "male" && genderStruct.gender != "female")
    {
        wrongInputMessage("Please enter male or female");
        cin >> genderStruct.gender;
    }
    // Call the 'makeDefaultUser' function.
    // This function is used to create a default user based on the gender specified by 'genderStruct.gender'.
    // The 'genderStruct.gender' expression accesses the 'gender' member of the 'genderStruct' object.
    // The 'person' object is passed to the function by reference, which means that any changes made to 'person' inside the function will affect the 'person' object here.
    // The '&' symbol in the function declaration indicates that the parameter is passed by reference.
    makeDefaultUser(genderStruct.gender, person);
}
/**
 * Creates a random user and adds the user to the list of all created person pointers.
 */
void makeRandomUser()
{
    // Create a new Person object on the heap.
    // The 'new' keyword is used to allocate memory on the heap.
    // This memory will persist even after the function ends, so you can still access the Person object later.
    // The parameters "Random", "Person", 0, 0 are passed to the Person constructor to initialize the new object.
    Person *randomPerson = new Person("Random", "Person", 0, 0);

    // 'randomPerson' is a pointer to the newly created Person object.
    // Pointers are variables that hold the memory address of an object, rather than the object itself.

    // 'allCreatedPersonPointers' is a global vector that holds pointers to all Person objects created so far.
    // The 'push_back' function is used to add a new element to the end of the vector.
    // In this case, it adds the 'randomPerson' pointer to the vector.
    allCreatedPersonPointers.push_back(randomPerson);
}

/**
 * A function that takes a gender and a Person object by reference to create a default user, including entering name, age, salary, and providing a shoutout option.
 *
 * @param gender the gender of the user
 * @param p the Person object to be updated with user information
 *
 * @return void
 *
 * @throws none
 */
void makeDefaultUser(string gender, Person &p) // Passing by refrence here , if you dont you wont be updating object you passed in
{
    clearScreen();
    string firstname = "";
    string lastname = "";
    int age = 0;
    string doShoutout = "";
    printf("Welcome, your gender is %s \n", gender.c_str()); // makes a c style char pointer since printf is c func
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
}

/**
 * Function to exit the program.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void exit()
{
    clearScreen();
    cout << "Bye" << endl;
    return;
}