#include <iostream> // Library to help with input/output
#include <fstream> // Library for file operations
#include <string> // Library for manipulating strings
#include <vector> // Library for arrays
#include <limits> // Library for input validation
#include <cctype> // Library for checking character types
#include <sstream> // Library for string streams
#include <filesystem> // Library for filesystem operations


struct Friend {
    // Define a structure to represent attributes of a friend.
    // Includes fields for name, surname, age, weight, height, and grade.
    std::string name; // Friend's name
    std::string surname; // Friend's surname
    double age; // Friend's age
    double weight; // Friend's weight
    double height; // Friend's height
    char grade; // Friend's grade
};

// Function to read and display the database
void read_database() {
    // Read data from the file and store it in Friend objects
    std::ifstream inputFile("friends_database.txt");
    Friend friends[1000]; //Setts maximum number of friends 

    std::string line;
    int i = 0;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        if (!(iss >> friends[i].name >> friends[i].surname >> friends[i].age >> friends[i].weight >> friends[i].height >> friends[i].grade)) {
            break; // If unable to read data, exit loop
        }
        ++i;
    }

    // Print out the friend details
    for (int j = 0; j < i; ++j) {
        std::cout << "Name: " << friends[j].name << " " << friends[j].surname << std::endl;
        std::cout << "Age: " << friends[j].age << std::endl;
        std::cout << "Weight: " << friends[j].weight << std::endl;
        std::cout << "Height: " << friends[j].height << std::endl;
        std::cout << "Grade: " << friends[j].grade << std::endl;
        std::cout << std::endl;
    }

    inputFile.close(); // Close the file
}

// Function to delete the entire database
void drop_database() {
    const std::string filename = "friends_database.txt"; // This is the file to be modified
    std::ifstream inputFile(filename); // This opens the file stream

    // Attempt to drop the file
    // Confirm dropping database
    char confirm; // This stores the confirmation choice
    std::cout << "Are you sure you want to drop your database? (y/n): ";
    std::cin >> confirm; // This inputs the confirmation

    if (confirm == 'y' || confirm == 'Y') {
        if (std::remove(filename.c_str()) != 0) {
            std::cerr << "Error deleting database file" << std::endl; // This prints an error message
        }
        else {
            std::cout << "Database file deleted successfully" << std::endl; // This prints a success message
        }
    }
    else {
        std::cout << "Deletion cancelled." << std::endl; // This prints a cancellation message
    }
    inputFile.close(); // This closes the file
}

// Function to create initial database if it doesn't exist
void load_database_sample() {
    std::string filename = "friends_database.txt"; // This defines the name of the database file
    std::ifstream inputFile(filename); // This checks if file exists

    // Check if file already exists
    if (inputFile.good()) {
        std::cout << "Database file already exists." << std::endl; // This prints a message
        return; // This exits the function
    }

    std::ofstream outputFile(filename); // This opens the file

    // Check if file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error creating file" << std::endl; // This prints an error message
        return; // This exits the function
    }

    // Write sample data to file

    outputFile << "Stephen\tFry\t22\t67\t180.7\tB\n";
    outputFile << "Phoebe\tWaller-Bridge\t18\t70\t199\tA\n";
    outputFile << "Rowan\tAtkinson\t20\t68.2\t168\tB\n";
    outputFile << "Sean\tLock\t19\t74\t173\tC\n";
    outputFile << "Sindhu\tVee\t21\t82\t185\tA\n";
    outputFile << "Sandeep\tSingh\t22\t90\t180\tB\n";
    outputFile << "Eddie\tIzzard\t23\t88\t178\tA\n";
    outputFile << "Louis\tCK\t25\t85\t179\tC\n";
    outputFile << "John\tOliver\t22\t76\t181\tB\n";
    outputFile << "Bill\tBurr\t19\t75\t175\tC\n";
    outputFile << "Trevor\tNoah\t24\t73\t182\tB\n";
    outputFile << "Bo\tBurnham\t21\t71\t177\tA\n";
    outputFile << "Jim\tGaffigan\t20\t84\t187\tC\n";
    outputFile << "Chris\tRock\t22\t81\t183\tB\n";

    outputFile.close(); // This closes the file
}

// Function to display the main menu
void display_menu() {
    // Display the main menu options
    std::cout << "Choose an option below:\n"; // This prompts the user
    std::cout << "1. Load database sample\n";
    std::cout << "2. Read database\n"; // This option reads and displays the entire database
    std::cout << "3. Drop database\n"; // This option deletes the entire database
    std::cout << "0. Exit\n"; // This option exits the program
    std::cout << "Enter your choice: "; // This prompts the user to enter a choice
}

int main() {
    int choice; // This stores the user choice

    // Main menu loop
    while (true) {
        display_menu(); // This displays the main menu
        std::cin >> choice; // This inputs the user choice

        // Switch case for menu choices
        switch (choice) {
        case 0:
            std::cout << "Exiting program." << std::endl; // This prints a message
            return 0; // This exits the program
        case 1:
            load_database_sample(); // This loads the initial sample data into the database
            break;
        case 2:
            read_database(); // This reads and displays the entire database
            break;
        case 3:
            drop_database(); // This deletes the entire database
            break;
        default:
            std::cout << "Invalid choice" << std::endl; // This prints an error message
            break;
        }
    }
}
