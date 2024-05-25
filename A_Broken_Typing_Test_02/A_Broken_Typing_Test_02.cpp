#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to show mistakes
void showMistakes(const string& input, const string& correct) {
    for (size_t i = 0; i < correct.size(); ++i) {
        if (i < input.size() && input[i] == correct[i]) {
            cout << input[i];
        } else {
            cout << "\033[31m" << (i < input.size() ? input[i] : '_') << "\033[0m";
        }
    }
    cout << endl;
}

// Function to save score to file
void saveScore(double score) {
    ofstream file("scores.txt", ios::app);
    if (file.is_open()) {
        file << score << endl;
        file.close();
    } else {
        cerr << "Unable to open file for writing.\n";
    }
}

// Function to load scores from file
vector<double> loadScores() {
    vector<double> scores;
    ifstream file("scores.txt");
    if (file.is_open()) {
        double score;
        while (file >> score) {
            scores.push_back(score);
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading.\n";
    }
    return scores;
}

// Function to display scores
void displayScores() {
    vector<double> scores = loadScores();
    if (scores.empty()) {
        cout << "No scores available.\n";
    } else {
        cout << "\nPrevious scores:\n";
        sort(scores.begin(), scores.end());
        for (double score : scores) {
            cout << score << " seconds\n";
        }
    }
}

// Function to perform the typing test
void typingTest() {
    const string correctAlphabet = "abcdefghijklmnopqrstuvwxyz";

    // Display instructions
    cout << "Typing Test: Type the alphabet (a-z) as fast as you can starting with 'a'.\n";
    cout << "Start typing...\n";

    // Capture the start time when the user types 'a'
    char firstChar;
    do {
        cin >> firstChar;
    } while (firstChar != 'a');

    auto start = chrono::high_resolution_clock::now();

    // Capture the rest of the user input
    string input;
    getline(cin, input);
    input = 'a' + input;  // Include the 'a' as the first character

    // Capture the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    chrono::duration<double> elapsed = end - start;
    double timeTaken = elapsed.count();

    // Check if the input is correct
    if (input == correctAlphabet) {
        cout << "You typed the alphabet correctly!\n";
    } else {
        cout << "You did not type the alphabet correctly.\n";
        cout << "Mistakes: ";
        showMistakes(input, correctAlphabet);
    }

    // Display the elapsed time
    cout << "Time taken: " << timeTaken << " seconds.\n";

    // Save the score
    saveScore(timeTaken);
}

// Main menu
void displayMenu() {
    int choice;
    do {
        cout << "1. Typing Test\n";
        cout << "2. Check Scores\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Ignore remaining newline character from previous input
                typingTest();
                break;
            case 2:
                displayScores();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
    return 0;
}
