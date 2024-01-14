#include <fstream>
#include <vector>
#include "Person.h"


/*
 * In C++, 'auto' is a keyword that tells the compiler to automatically deduce the type of the variable at compile time based on the initializer. 
 * In the context of a range-based for loop, 'auto' is used to automatically deduce the type of the elements in the container being iterated over.
 *
 * For example, in the line:
 * for (const auto& person : people) {
 *
 * 'auto' is being used to automatically deduce the type of the elements in the 'people' container.
 *
 * The '&' symbol after 'auto' means that 'person' is a reference to the element, not a copy. This means that if you modify 'person' inside the loop, 
 * you're modifying the actual element in the 'people' container, not a copy of it. This is more efficient than copying the element, especially if the elements are large.
 *
 * The 'const' keyword before 'auto' means that 'person' is a constant reference, so you can't modify the elements of 'people' through 'person'. 
 * This is useful if you want to iterate over a container and access its elements without modifying them.
 *
 * So, this line of code is starting a loop that will iterate over each element in 'people', with 'person' being a constant reference to the current element.
 */
/**
 * Writes the contents of the given vector of Person objects to a file.
 *
 * @param people The vector of Person objects to be written to the file.
 * @param filename The name of the file to write the contents to.
 *
 * @throws None
 */
void writeToFile(const std::vector<Person*>& people, const std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& person : people) {
            file << person->serialize() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}