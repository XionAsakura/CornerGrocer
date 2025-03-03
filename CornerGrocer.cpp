/* 
* Ruben Rodriguez
* 2/22/2025
* CS210 Project 3 
* This program helps the Corner Grocer analyze grocery sales data by reading an input file containing a list of purchased items.
* A menu is created to provide for accessibility to this data and processes this data to determine how frequently each produce item was purchased.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency; // Stores item frequencies
    string inputFile = "CS210_Project_Three_Input_File.txt";
    string outputFile = "frequency.dat";

public:
    // Constructor to load data and create backup file
    GroceryTracker() {
        if (loadItems()) {
            saveFrequencyToFile();
        }
    }

    // Function to convert string to lowercase for case-insensitive comparison
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Load item frequencies from the input file
    bool loadItems() {
        ifstream file(inputFile);
        string item;

        if (!file) {
            cerr << "Error: Unable to open " << inputFile << ". Ensure the file exists.\n";
            return false;
        }

        while (file >> item) {
            itemFrequency[toLowerCase(item)]++;  // Convert item names to lowercase before storing
        }

        file.close();
        return true;
    }

    // Save frequency data to output file
    void saveFrequencyToFile() {
        ofstream outFile(outputFile);
        if (!outFile) {
            cerr << "Error: Unable to create " << outputFile << endl;
            return;
        }

        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

    // Search for an item's frequency with case insensitivity
    void searchItem() {
        string item;
        cout << "Enter item name to search: ";
        cin >> item;
        item = toLowerCase(item); // Convert input to lowercase for comparison

        if (itemFrequency.find(item) != itemFrequency.end()) {
            cout << item << " was purchased " << itemFrequency[item] << " times.\n";
        }
        else {
            cout << item << " was not found in the records.\n";
        }
    }

    // Display all items with their frequencies
    void displayAllItems() {
        if (itemFrequency.empty()) {
            cout << "No data available.\n";
            return;
        }

        cout << "\nItem Frequency List:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Display histogram
    void displayHistogram() {
        if (itemFrequency.empty()) {
            cout << "No data available.\n";
            return;
        }

        cout << "\nItem Purchase Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << string(pair.second, '*') << endl;
        }
    }

    // Function to get a valid integer choice from the user
    int getValidChoice() {
        int choice;
        while (true) {
            cout << "\nEnter your choice: ";
            cin >> choice;

            // Check for valid input
            if (cin.fail() || choice < 1 || choice > 4) {
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            }
            else {
                return choice;
            }
        }
    }

    // Menu for user interaction
    void menu() {
        int choice;
        do {
            cout << "\n--- Corner Grocer Tracking System ---\n";
            cout << "1. Search for an item\n";
            cout << "2. Display all items and their frequency\n";
            cout << "3. Display histogram\n";
            cout << "4. Exit\n";

            choice = getValidChoice(); // Get validated user choice

            switch (choice) {
            case 1: searchItem(); break;
            case 2: displayAllItems(); break;
            case 3: displayHistogram(); break;
            case 4: cout << "Exiting program...\n"; break;
            }
        } while (choice != 4);
    }
};

int main() {
    GroceryTracker tracker;
    tracker.menu();
    return 0;
}
