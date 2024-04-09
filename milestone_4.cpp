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

bool is_all_alpha(const std::string& str) {
    // This function checks whether a given string contains only alphabetic characters.
    // It iterates through each character in the string and checks if it is alphabetic.
    // If any character is found that is not alphabetic, the function returns false,
    // indicating that the string does not contain only alphabetic characters.
    // If all characters in the string are alphabetic, the function returns true.

    for (char c : str) {
        if (!std::isalpha(c)) {
            return false; // Return false if any character is not alphabetic
        }
    }
    return true; // Return true if all characters are alphabetic
}

bool is_all_digit(const std::string& str) {
    // This function checks whether a given string contains only numeric digits.
    // It iterates through each character in the string and checks if it is a digit.
    // If any character is found that is not a digit, the function returns false,
    // indicating that the string does not contain only numeric digits.
    // If all characters in the string are digits, the function returns true.
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; // Return false if any character is not a digit
        }
    }
    return true; // Return true if all characters are digits
}

void search_friends() {
    // This function searches for friends based on specified criteria.
    // It reads data from a file containing friends' information and allows the user to search for friends
    // based on one or multiple criteria such as age, weight, height, or grade.

    std::string filename = "friends_database.txt"; // File containing friends' data
    std::ifstream inputFile(filename); // Opening file for reading

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for searching friends" << std::endl; // Error message if file cannot be opened
        return;
    }

    std::string line; // Variable to store each line from the file
    std::vector<Friend> matchingFriends; // Vector to store matching friends

    std::cout << "Criteria for searching friends:\n"; // Displaying search criteria
    std::cout << "1. Age\n";
    std::cout << "2. Weight\n";
    std::cout << "3. Height\n";
    std::cout << "4. Grade\n";

    std::string searchChoice; // Variable to store user's search choice
    std::cout << "Do you want to search based on one or multiple criteria? (one/mult/exit): ";
    std::cin >> searchChoice; // User inputs search choice

    if (searchChoice == "one") {
        std::string variableToSearch; // Variable to store the variable to search for
        std::cout << "Enter the variable to search: ";
        std::cin >> variableToSearch; // User inputs variable to search for

        // Handling different search criteria
        if (variableToSearch == "Age") {
            double age;
            std::cout << "Enter age: ";
            std::cin >> age; // User inputs age to search for
            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                Friend friendData;
                iss >> friendData.name >> friendData.surname >> friendData.age >> friendData.weight >> friendData.height >> friendData.grade;
                if (friendData.age == age) {
                    matchingFriends.push_back(friendData); // Adding matching friend to vector
                }
            }
        }
        else if (variableToSearch == "Weight") {
            double weight;
            std::cout << "Enter weight: ";
            std::cin >> weight; // User inputs weight to search for
            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                Friend friendData;
                iss >> friendData.name >> friendData.surname >> friendData.age >> friendData.weight >> friendData.height >> friendData.grade;
                if (friendData.weight == weight) {
                    matchingFriends.push_back(friendData); // Adding matching friend to vector
                }
            }
        }
        else if (variableToSearch == "Height") {
            double height;
            std::cout << "Enter height: ";
            std::cin >> height; // User inputs height to search for
            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                Friend friendData;
                iss >> friendData.name >> friendData.surname >> friendData.age >> friendData.weight >> friendData.height >> friendData.grade;
                if (friendData.height == height) {
                    matchingFriends.push_back(friendData); // Adding matching friend to vector
                }
            }
        }
        else if (variableToSearch == "Grade") {
            char grade;
            std::cout << "Enter grade: ";
            std::cin >> grade; // User inputs grade to search for
            while (std::getline(inputFile, line)) {
                std::istringstream iss(line);
                Friend friendData;
                iss >> friendData.name >> friendData.surname >> friendData.age >> friendData.weight >> friendData.height >> friendData.grade;
                if (friendData.grade == grade) {
                    matchingFriends.push_back(friendData); // Adding matching friend to vector
                }
            }
        }
    }
    else if (searchChoice == "mult") {
        double age = -1;
        double weight = -1;
        double height = -1;
        char grade = '\0';

        std::cout << "Enter age (or -1 to skip): ";
        std::cin >> age;
        std::cout << "Enter weight (or -1 to skip): ";
        std::cin >> weight;
        std::cout << "Enter height (or -1 to skip): ";
        std::cin >> height;
        std::cout << "Enter grade (or '0' to skip): ";
        std::cin >> grade;

        while (std::getline(inputFile, line)) {
            // While iterating through each line of the file, this block of code extracts friend data from the line.
            // It then checks if the extracted friend's attributes match the criteria specified by the user (age, weight, height, grade).
            // If any of the criteria are specified as -1 or '\0' (indicating that the user skipped that criterion), the corresponding match variable is set to true.
            // If all criteria match (or are skipped), the friend data is added to the vector of matching friends.
            std::istringstream iss(line);
            Friend friendData;
            iss >> friendData.name >> friendData.surname >> friendData.age >> friendData.weight >> friendData.height >> friendData.grade;
            // Matching criteria for age, weight, height, and grade
            bool ageMatch = (age == -1 || friendData.age == age);
            bool weightMatch = (weight == -1 || friendData.weight == weight);
            bool heightMatch = (height == -1 || friendData.height == height);
            bool gradeMatch = (grade == '\0' || friendData.grade == grade);

            if (ageMatch && weightMatch && heightMatch && gradeMatch) {
                matchingFriends.push_back(friendData); // Adding matching friend to vector
            }
        }
    }
    else if (searchChoice == "exit") {
        inputFile.close(); // Closing file
        return; // Exiting function
    }
    inputFile.close();

    if (matchingFriends.empty()) {
        std::cout << "No friends found with the specified parameters." << std::endl;
    }
    else {
        std::cout << "Matching friends:\n";
        for (const auto& friendData : matchingFriends) {
            std::cout << friendData.name << " " << friendData.surname << " " << friendData.age << " "
                << friendData.weight << " " << friendData.height << " " << friendData.grade << std::endl;
        }
    }
}

// Function to calculate BMI
double calculate_bmi(double weight, double height) {
    // BMI formula: weight (kg) / (height (m) * height (m))
    return weight / ((height / 100.0) * (height / 100.0)); // Calculating BMI
}

// Function to determine BMI category
std::string bmi_category(double bmi) {
    if (bmi < 18.5) {
        return "Underweight"; // BMI category: Underweight
    }
    else if (bmi < 25) {
        return "Normal weight"; // BMI category: Normal weight
    }
    else if (bmi < 30) {
        return "Overweight"; // BMI category: Overweight
    }
    else {
        return "Obesity"; // BMI category: Obesity
    }
}

/// BMI calculator function
void just_bmi_calculator() {
    double weight, height;

    do {
        std::cout << "Enter weight (kg): ";
        std::cin >> weight; // User inputs weight
        if (weight <= 0) {
            std::cout << "Weight must be greater than zero. Please try again." << std::endl; // Error message if weight is invalid
        }
    } while (weight <= 0);

    do {
        std::cout << "Enter height (cm): ";
        std::cin >> height; // User inputs height
        if (height <= 0) {
            std::cout << "Height must be greater than zero. Please try again." << std::endl; // Error message if height is invalid
        }
    } while (height <= 0);

    double bmi = calculate_bmi(weight, height); // Calculating BMI
    std::string category = bmi_category(bmi); // Determining BMI category

    std::cout << "Your BMI: " << bmi << std::endl; // Displaying BMI
    std::cout << "BMI Category: " << category << std::endl; // Displaying BMI category
}

// Function to calculate BMI for a friend
void calculate_bmi_for_friend() {
    std::string nameToCalculate, surnameToCalculate; // Details of the friend to calculate BMI for

    // Input validation loop for name
    do {
        std::cout << "Enter name: ";
        std::cin >> nameToCalculate; // Input name
    } while (!is_all_alpha(nameToCalculate)); // Check if all characters are alphabetic

    // Input validation loop for surname
    do {
        std::cout << "Enter surname: ";
        std::cin >> surnameToCalculate; // Input surname
    } while (!is_all_alpha(surnameToCalculate)); // Check if all characters are alphabetic

    std::string filename = "friends_database.txt"; // Database file name
    std::ifstream inputFile(filename); // Open file stream

    // Check if file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for calculating BMI" << std::endl; // Print error message
        return; // Exit the function
    }

    std::string line; // Store the line read from the file
    bool friendFound = false; // Flag to indicate if friend is found

    // Read friend details from file
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Friend friendDetails;
        iss >> friendDetails.name >> friendDetails.surname >> friendDetails.age >> friendDetails.weight >> friendDetails.height >> friendDetails.grade;

        // Check if details match the entered name and surname
        if (friendDetails.name == nameToCalculate && friendDetails.surname == surnameToCalculate) {
            friendFound = true; // Set friend found flag
            double bmi = calculate_bmi(friendDetails.weight, friendDetails.height); // Calculate BMI
            std::string category = bmi_category(bmi); // Determine BMI category

            // Print friend's details and calculated BMI
            std::cout << "Friend found:\n"
                << "Name: " << friendDetails.name << "\n"
                << "Surname: " << friendDetails.surname << "\n"
                << "Age: " << friendDetails.age << "\n"
                << "Weight: " << friendDetails.weight << " kg\n"
                << "Height: " << friendDetails.height << " cm\n"
                << "BMI: " << bmi << " (" << category << ")\n";
            break; // Exit the loop
        }
    }

    inputFile.close(); // Close the file

    // If friend not found, print message
    if (!friendFound) {
        std::cout << "No friend found with the given name and surname." << std::endl;
    }
}

void show_save_results_files() {
    std::ifstream databasesFile("databases.txt");
    std::string line;

    if (databasesFile.is_open()) {
        std::cout << "List of saved search result files:\n";
        while (std::getline(databasesFile, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "\n";
        databasesFile.close();
    }
    else {
        std::cerr << "Error opening databases file." << std::endl;
    }
}

void open_database_file() {
    std::string filename;
    std::cout << "Enter the filename to open (or 0 to exit): ";
    std::cin >> filename;

    if (filename == "0") {
        std::cout << "Exiting." << std::endl;
        return;
    }

    std::ifstream inputFile(filename); // Open the specified file

    if (inputFile.is_open()) {
        std::string line;
        std::cout << "Contents of " << filename << ":\n";
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "\n";
        inputFile.close();
    }
    else {
        std::cerr << "Error opening file." << std::endl;
    }
}

// Function menu for BMI options
void bmi_calculator_choice() {
    int choice; // This stores the user choice

    // Main menu loop
    while (true) {
        std::cout << "0. main menu\n";
        std::cout << "1. BMI for a friend\n";
        std::cout << "2. BMI calculator\n";
        std::cout << "Enter your choice: ";

        do {
            std::cin >> choice; // Input surname
        } while (!is_all_digit(std::to_string(choice))); // Check if all characters are alphabetic

        // Switch case for menu choices
        switch (choice) {
        case 0:
            return;
        case 1:
            calculate_bmi_for_friend(); //Calls function to calculate bmi for a friend
            return;
        case 2:
            just_bmi_calculator(); // Call normal BMI calculator
            break;
        default:
            std::cout << "Invalid choice" << std::endl; // This prints an error message
            break;
        }
    }
}

// Function to add a friend
void add_a_friend() {
    const std::string filename = "friends_database.txt"; // Database file name
    std::ofstream outputFile(filename, std::ios::app); // Opening file for appending

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for adding friend" << std::endl; // Error message if file cannot be opened
        return;
    }

    Friend newFriend;

    do {
        std::cout << "Enter name: ";
        std::cin >> newFriend.name;
    } while (!is_all_alpha(newFriend.name)); // Input validation for name

    do {
        std::cout << "Enter surname: ";
        std::cin >> newFriend.surname;
    } while (!is_all_alpha(newFriend.surname)); // Input validation for surname

    do {
        std::string ageStr;
        std::cout << "Enter age: ";
        std::cin >> ageStr;
        if (is_all_digit(ageStr)) {
            newFriend.age = std::stod(ageStr);
            break;
        }
    } while (true); // Input validation for age

    do {
        std::string weightStr;
        std::cout << "Enter weight (kg): ";
        std::cin >> weightStr;
        if (is_all_digit(weightStr)) {
            newFriend.weight = std::stod(weightStr);
            break;
        }
    } while (true); // Input validation for weight

    do {
        std::string heightStr;
        std::cout << "Enter height (cm): ";
        std::cin >> heightStr;
        if (heightStr.find_first_not_of("0123456789.") == std::string::npos) {
            newFriend.height = std::stod(heightStr);
            break;
        }
    } while (true); // Input validation for height

    do {
        std::cout << "Enter grade (a single capital letter): ";
        std::cin >> newFriend.grade;
    } while (!std::isalpha(newFriend.grade) || !std::isupper(newFriend.grade)); // Ensure it's a single capital letter

    // Write friend details to file
    outputFile << newFriend.name << " " << newFriend.surname << " " << newFriend.age << " " << newFriend.weight << " " << newFriend.height << " " << newFriend.grade << std::endl;

    outputFile.close(); // Close the file

    std::cout << "Friend added successfully." << std::endl; // Success message
}

// Function to delete a friend
void delete_a_friend() {
    const std::string filename = "friends_database.txt"; // Database file name
    std::ifstream inputFile(filename); // Opening file for reading

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for deleting friend" << std::endl; // Error message if file cannot be opened
        return;
    }

    std::string nameToDelete, surnameToDelete;
    std::vector<Friend> friends;

    do {
        std::cout << "Enter name: ";
        std::cin >> nameToDelete; // Input name
    } while (!is_all_alpha(nameToDelete)); // Input validation for name

    do {
        std::cout << "Enter surname: ";
        std::cin >> surnameToDelete; // Input surname
    } while (!is_all_alpha(surnameToDelete)); // Input validation for surname

    Friend friendToDelete;

    // Read friends from file and store in vector except the one to delete
    Friend tempFriend;
    while (inputFile >> tempFriend.name >> tempFriend.surname >> tempFriend.age >> tempFriend.weight >> tempFriend.height >> tempFriend.grade) {
        if (tempFriend.name == nameToDelete && tempFriend.surname == surnameToDelete) {
            std::cout << "Friend found:\n" << tempFriend.name << " " << tempFriend.surname << " " << tempFriend.age << " " << tempFriend.weight << " " << tempFriend.height << " " << tempFriend.grade << std::endl;
            char confirm;
            std::cout << "Are you sure you want to delete this friend? (y/n): ";
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                continue; // Skip writing this friend to vector
            }
        }
        friends.push_back(tempFriend);
    }

    inputFile.close(); // Close the file

    if (friends.empty()) {
        std::cout << "No friends found with the given name and surname." << std::endl; // Message if no friends found
        return;
    }

    std::ofstream outputFile(filename); // Opening file for writing

    for (const Friend& friendData : friends) {
        outputFile << friendData.name << " " << friendData.surname << " " << friendData.age << " " << friendData.weight << " " << friendData.height << " " << friendData.grade << '\n';
    }

    outputFile.close(); // Close the file

    std::cout << "Friend deletion process completed." << std::endl; // Success message
}

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
    std::cout << "2. Add a friend\n"; // This option adds a friend to the database
    std::cout << "3. Delete a friend\n"; // This option deletes a friend from the database
    std::cout << "4. Search for friends\n"; // This option searches for friends based on criteria
    std::cout << "5. Calculate BMI\n"; // This option calculates the BMI of a friend or user
    std::cout << "6. Read database\n"; // This option reads and displays the entire database
    std::cout << "7. Drop database\n"; // This option deletes the entire database
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
            add_a_friend(); // This adds a friend to the database
            break;
        case 3:
            delete_a_friend(); // This deletes a friend from the database
            break;
        case 4:
            search_friends(); // This searches for friends based on criteria
            break;
        case 5:
            bmi_calculator_choice(); // This calculates BMI for a friend or the user
            break;
        case 6:
            read_database(); // This reads and displays the entire database
            break;
        case 8:
            drop_database(); // This deletes the entire database
            break;
        default:
            std::cout << "Invalid choice" << std::endl; // This prints an error message
            break;
        }
    }
}5
