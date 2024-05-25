#include <iostream>
#include <chrono>
#include <vector>
#include <conio.h> // For _getch() on Windows

using namespace std;

class TypingTest {
private:
    vector<double> scores;

public:
    void displayMenu() {
        while (true) {
            cout << "1. Typing Test\n";
            cout << "2. Check Scores\n";
            cout << "3. Exit\n";
            cout << "Choose an option: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                startTypingTest();
            } else if (choice == 2) {
                checkScores();
            } else if (choice == 3) {
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void startTypingTest() {
        cout << "Typing Test: Type the alphabet (a-z) as fast as you can.\n";
        cout << "Start typing... (type 'a' to start)\n";

        string input;
        char firstChar;

        // Wait for the user to press 'a'
        while (true) {
            firstChar = _getch(); // Use _getch() to capture a single character input without waiting for Enter
            if (firstChar == 'a') {
                break;
            }
        }

        // Capture the start time
        auto start = chrono::high_resolution_clock::now();
        input.push_back(firstChar);

        // Capture the rest of the user input
        for (int i = 1; i < 26; ++i) { // We already have 'a', so we need 25 more characters
            char nextChar = _getch();
            input.push_back(nextChar);
        }

        // Capture the end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate the elapsed time
        chrono::duration<double> elapsed = end - start;

        // Check if the input is correct
        if (input == "abcdefghijklmnopqrstuvwxyz") {
            cout << "You typed the alphabet correctly!\n";
            scores.push_back(elapsed.count());
        } else {
            cout << "You did not type the alphabet correctly.\n";
        }

        // Display the elapsed time
        cout << "Time taken: " << elapsed.count() << " seconds.\n";
    }

    void checkScores() {
        if (scores.empty()) {
            cout << "No scores available.\n";
        } else {
            cout << "Scores:\n";
            for (size_t i = 0; i < scores.size(); ++i) {
                cout << "Attempt " << i + 1 << ": " << scores[i] << " seconds\n";
            }
        }
    }
};

int main() {
    TypingTest typingTest;
    typingTest.displayMenu();
    return 0;
}
