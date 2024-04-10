#include <iostream> // This library helps with input/output
#include <fstream> // This library helps with file operations
#include <string> // This library helps with string manipulation
#include <vector> // This library helps with arrays
#include <limits> // This library helps with input validation
#include <cctype> // This library helps with character type checks
#include <sstream> // This library helps with string streams

// Function to check if a string contains only alphabetic characters
bool is_all_alpha(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false; // This returns false if any character is not alphabetic
        }
    }
    return true; // This returns true if all characters are alphabetic
}

// Function to check if a string contains only digits
bool is_all_digit(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; // This returns false if any character is not a digit
        }
    }
    return true; // This returns true if all characters are digits
}

// Function to delete a friend from the database
void delete_a_friend() {
    const std::string filename = "friends_database.txt"; // This is the file to be modified
    std::ifstream inputFile(filename); // This opens the file stream

    // Check if file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for deleting friend" << std::endl; // This prints an error message
        return; // This exits the function
    }

    std::string nameToDelete, surnameToDelete; // These are the details of the friend to delete

    // Input validation loop for name
    do {
        std::cout << "Enter name: ";
        std::cin >> nameToDelete; // This inputs the name
    } while (!is_all_alpha(nameToDelete)); // This checks if all characters are alphabetic

    // Input validation loop for surname
    do {
        std::cout << "Enter surname: ";
        std::cin >> surnameToDelete; // This inputs the surname
    } while (!is_all_alpha(surnameToDelete)); // This checks if all characters are alphabetic

    std::string line; // This stores the line read from the file
    std::vector<std::string> remainingFriends; // This vector stores non-matching friends

    // Read and find non-matching friends from file
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, surname;
        iss >> name >> surname;
        if (name == nameToDelete && surname == surnameToDelete) {
            std::cout << "Friend found:\n" << line << std::endl; // Show friend details
            char confirm;
            std::cout << "Are you sure you want to delete this friend? (y/n): ";
            std::cin >> confirm; // Confirm deletion
            if (confirm == 'y' || confirm == 'Y') {
                continue; // Skip adding to remainingFriends vector
            } else {
                remainingFriends.push_back(line); // Add back to remainingFriends vector
            }
        } else {
            remainingFriends.push_back(line); // Add to remainingFriends vector
        }
    }

    inputFile.close(); // This closes the file

    // Check if any matching friends found
    if (remainingFriends.empty()) {
        std::cout << "No friends found with the given name and surname." << std::endl; // This prints a message
        return; // This exits the function
    }

    // Open file again in write mode to overwrite the data
    std::ofstream outputFile(filename);

    // Write all remaining friends back to the file
    for (const std::string& friendData : remainingFriends) {
        outputFile << friendData << '\n'; // This writes remaining friends back to the file
    }

    outputFile.close(); // This closes the file

    std::cout << "Friend deletion process completed." << std::endl; // This prints a success message
}

// Function to read and display the database
void read_database() {
    const std::string filename = "friends_database.txt"; // This is the file to be read
    std::ifstream file(filename); // This opens the file for reading

    // Check if file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl; // This prints an error message
        return; // This exits the function
    }

    std::string line; // This stores the line read from the file

    // Read and print lines from file
    while (std::getline(file, line)) {
        std::cout << line << std::endl; // This prints a line from the file
    }

    file.close(); // This closes the file
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

// Function to add a friend to the database
void add_a_friend() {
    const std::string filename = "friends_database.txt"; // This is the file to be modified
    std::ofstream outputFile(filename, std::ios::app); // This opens the file stream in append mode

    // Check if file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for adding friend" << std::endl; // This prints an error message
        return; // This exits the function
    }

    std::string name, surname, ageStr, weightStr, heightStr, grade; // These are the details of the friend

    // Input validation loop for name
    do {
        std::cout << "Enter name: ";
        std::cin >> name; // This inputs the name
    } while (!is_all_alpha(name)); // This checks if all characters are alphabetic

    // Input validation loop for surname
    do {
        std::cout << "Enter surname: ";
        std::cin >> surname; // This inputs the surname
    } while (!is_all_alpha(surname)); // This checks if all characters are alphabetic

    // Input validation loop for age
    do {
        std::cout << "Enter age: ";
        std::cin >> ageStr; // This inputs the age
    } while (!is_all_digit(ageStr)); // This checks if all characters are digits
    int age = std::stoi(ageStr); // This converts age string to integer

    // Input validation loop for weight
    do {
        std::cout << "Enter weight (kg): ";
        std::cin >> weightStr; // This inputs the weight
    } while (!is_all_digit(weightStr)); // This checks if all characters are digits
    int weight = std::stoi(weightStr); // This converts weight string to integer

    // Input validation loop for height
    do {
        std::cout << "Enter height (cm): ";
        std::cin >> heightStr; // This inputs the height
    } while (heightStr.find_first_not_of("0123456789.") != std::string::npos); // This checks if height contains only digits and dot
    double height = std::stod(heightStr); // This converts height string to double

    // Input validation loop for grade
    do {
        std::cout << "Enter grade (capital letter optionally followed by + or -): ";
        std::cin >> grade; // This inputs the grade
    } while (grade.length() < 1 || grade.length() > 2 || !std::isupper(grade[0]) || (grade.length() == 2 && grade[1] != '+' && grade[1] != '-'));

    // Write friend details to file with consistent format using spaces
    outputFile << name << " " << surname << " " << age << " " << weight << " " << height << " " << grade << "\n"; // This writes friend details to the file

    outputFile.close(); // This closes the file

    std::cout << "Friend added successfully." << std::endl; // This prints a success message
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
    outputFile << "Name\tSurname\tAge\tWeight(kg)\tHeight(cm)\tGrade\n";
    outputFile << "Stephen\tFry\t22\t67\t180.7\tB\n";
    outputFile << "Phoebe\tWaller-Bridge\t18\t70\t199\tA\n";
    outputFile << "Rowan\tAtkinson\t20\t68.2\t168\tB\n";
    outputFile << "Sean\tLock\t19\t74\t173\tC\n";
    outputFile << "Sindhu\tVee\t21\t62.8\t170\tB\n";
    outputFile << "Diane\tMorgan\t18\t64.4\t169\tA\n";
    outputFile << "Trevor\tNoah\t17\t69\t160\tC\n";
    outputFile << "Hugh\tLaurie\t19\t63\t184\tB\n";
    outputFile << "Robin\tWilliams\t17\t66.8\t167.2\tA\n";
    outputFile << "Steve\tCarell\t20\t67\t175.6\tC\n";
    outputFile << "Jon\tStewart\t18\t70.7\t163\tB\n";
    outputFile << "Tina\tFey\t18\t66\t166\tB\n";
    outputFile << "Maz\tOliver\t21\t67\t171.5\tB\n";
    outputFile << "Maz\tJobrani\t19\t65\t179\tA\n";

    outputFile.close(); // This closes the file

    std::cout << "Database file created." << std::endl; // This prints a success message
}

// Function to exit the main menu loop
void exit_menu(bool& exitLoop) {
    exitLoop = true; // This sets exit flag to true
}

// Function to display the main menu and handle user choices
void main_menu() {
    int choice; // This stores the user choice
    bool exitLoop = false; // This controls the main menu loop

    // Main menu loop
    while (!exitLoop) {
        std::cout << "1. List database\n";
        std::cout << "2. Add a friend\n";
        std::cout << "3. Delete a friend\n";
        std::cout << "4. Drop database\n";
        std::cout << "5. Align database\n"; // Placeholder for future functionality
        std::cout << "6. Load database sample\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice : ";
        // Input validation for menu choice
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl; // This prints an error message
            std::cin.clear(); // This clears error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // This discards invalid input
            continue; // This continues the loop
        }

        // Switch case for menu choices
        switch (choice) {
        case 1:
            read_database(); // This lists database
            break;
        case 2:
            add_a_friend(); // This adds a friend
            break;
        case 3:
            delete_a_friend(); // This deletes a friend
            break;
        case 4:
            drop_database(); // This drops the database
            break;
        case 5:

            break;
        case 6:
            load_database_sample(); // This loads a database sample
            break;
        case 7:
            exit_menu(exitLoop); // This exits the program
            break;
        default:
            std::cout << "Invalid choice" << std::endl; // This prints an error message
            break;
        }
    }
}

// Main function
int main() {
    main_menu(); // This displays and handles the main menu
    return 0; // This exits with success status
}