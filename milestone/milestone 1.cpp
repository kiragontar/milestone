#include <iostream> // For input/output
#include <fstream> // For file operations
#include <string> // For string manipulation
#include <limits>// For input validation


// Function to read data from the database file
void read_database() {
    std::ifstream databaseFile("friends_database.txt"); // Open the database file for reading

    if (!databaseFile.is_open()) { // Check if the file is opened successfully
        std::cerr << "Error opening file" << std::endl; // Print error message if file opening fails
        return; // Exit the function
    }

    std::string line; // Variable to store each line of the file
    while (std::getline(databaseFile, line)) { // Read each line from the file
        std::cout << line << std::endl; // Print the line to the console
    }

    databaseFile.close(); // Close the file after reading
}

// Function to create a new database file with sample data
void creating_database() {
    std::string filename = "friends_database.txt"; // Define the name of the database file
    std::ofstream outputFile(filename); // Open a new file for writing

    if (!outputFile.is_open()) { // Check if the file is opened successfully
        std::cerr << "error creating" << std::endl; // Print error message if file creation fails
        return; // Exit the function
    }

    // Write sample data to the file

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

    outputFile.close(); // Close the file after writing
    std::cout << "File created\n"; // Print success message
}
// Function to check if the database file exists, if not, create it
void first_run_check() {
    std::string filename = "friends_database.txt"; // Define the name of the database file

    std::ifstream inputfile(filename); // Open the file for reading

    if (!inputfile.good()) { // Check if the file is not opened successfully
        creating_database(); // Call function to create the database file
    }
    else {
        std::cout << " File Already exists\n"; // Print message if the file already exists
    }
}

// Function to exit the main menu loop
void exit_menu(bool& exitLoop) {
    exitLoop = true; // Set the loop exit flag to true
}
// Function to display the main menu and handle user input
void main_menu() {
    int choice; // Variable to store user choice
    bool exitLoop = false; // Flag to control loop termination

    while (!exitLoop) { // Main menu loop
        std::cout << "1. List database" << std::endl; // Display option to list database
        std::cout << "2. Exit" << std::endl; // Display option to exit

        if (!(std::cin >> choice)) { // Check if user input is not an integer
            std::cout << "Invalid input. Please enter a number." << std::endl; // Print error message
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue; // Skip to next iteration of the loop
        }

        switch (choice) { // Switch based on user choice
        case 1: // If user chooses option 1
            read_database(); // Call function to read and display the database
            break; // Exit the switch statement
        case 2: // If user chooses option 2
            exit_menu(exitLoop); // Call function to exit the menu loop
            break; // Exit the switch statement
        default: // If user choice is invalid
            std::cout << "Invalid choice" << std::endl; // Print error message
            break; // Exit the switch statement
        }
    }
}
// Main function
int main() {
    first_run_check(); // Check if it's the first run and create the database if necessary
    main_menu(); // Display the main menu
    return 0; // Return 0 to indicate successful program execution
}