#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib> // For system()

using namespace std;

class TypingTest {
private:
    vector<double> scores;

    void clearScreen() const {
        #if defined(_WIN32) || defined(_WIN64)
            system("CLS");
        #else
            system("clear");
        #endif
    }

public:
    void displayMenu() {
        while (true) {
            clearScreen();
            cout << "1. Typing Test\n";
            cout << "2. Check Scores\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    runTest();
                    break;
                case 2:
                    showScores();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    cin.ignore(); // Ignore the newline character left by previous input
                    cin.get(); // Wait for user to press Enter
            }
        }
    }

    void runTest() {
        while (true) {
            clearScreen();
            // Display instructions
            cout << "Typing Test: Type the alphabet (a-z) as fast as you can and press Enter.\n";
            cout << "Press Enter to start...\n";
            cin.ignore(); // Ignore the newline character left by previous input
            cin.ignore(); // Wait for user to press Enter

            // Indicate that the test has started
            cout << ">> ";

            // Capture the start time
            auto start = chrono::high_resolution_clock::now();

            // Capture the user input
            string input;
            getline(cin, input);

            // Capture the end time
            auto end = chrono::high_resolution_clock::now();

            // Calculate the elapsed time
            chrono::duration<double> elapsed = end - start;

            cout<<endl;
            // Check if the input is correct
            if (input == "abcdefghijklmnopqrstuvwxyz") {
                cout << "****<You typed the alphabet correctly!>****\n";
                scores.push_back(elapsed.count());
                cout << "         Time taken: " << elapsed.count() << " seconds.\n";
            } else {
                cout << "?????? #You did not type the alphabet correctly.# ??????\n";
                cout << "                  ~Try Again~\n";
            }

            // Display the elapsed time
            //cout << "Time taken: " << elapsed.count() << " seconds.\n";

            // Navigation options
            cout<<endl;
            cout << "1. Restart Test\n";
            cout << "2. Home Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 2) {
                break;
            } else if (choice != 1) {
                cout << "Invalid choice. Returning to home menu...\n";
                break;
            }
        }
    }

    void showScores() {
        clearScreen();
        if (scores.empty()) {
            cout << "No scores available.\n";
        } else {
            cout << "Scores:\n";
            for (size_t i = 0; i < scores.size(); ++i) {
                cout << "Attempt " << (i + 1) << ": " << scores[i] << " seconds\n";
            }
        }
        cout << "Press Enter to return to the menu...";
        cin.ignore(); // Ignore the newline character left by previous input
        cin.get(); // Wait for user to press Enter
    }
};

int main() {
    TypingTest test;
    test.displayMenu();
    return 0;
}
