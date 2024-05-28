#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib> // For system()
#include <sstream>
#include <algorithm>

using namespace std;

class KeyMaster {
private:
    string scoresFile = "scores.txt";

    void clearScreen() const {
        #if defined(_WIN32) || defined(_WIN64)
            system("CLS");
        #else
            system("clear");
        #endif
    }

    void saveScore(const string& name, double timeTaken) {
        ofstream outFile(scoresFile, ios::app);
        if (outFile.is_open()) {
            auto now = chrono::system_clock::now();
            time_t now_time = chrono::system_clock::to_time_t(now);
            outFile << name << " " << timeTaken << " " << ctime(&now_time);
            outFile.close();
        } else {
            cout << "Unable to open file to save scores.\n";
        }
    }

    struct ScoreEntry {
        string name;
        double timeTaken;
        string dateTime;

        bool operator<(const ScoreEntry& other) const {
            return timeTaken < other.timeTaken;
        }
    };

    vector<ScoreEntry> loadScores() {
        vector<ScoreEntry> scores;
        ifstream inFile(scoresFile);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                string name;
                double timeTaken;
                string dateTime;
                iss >> name >> timeTaken;
                getline(iss, dateTime);
                if (!iss.fail()) {
                    scores.push_back({name, timeTaken, dateTime});
                }
            }
            inFile.close();
        }
        return scores;
    }

    void displayScores(const vector<ScoreEntry>& scores) const {
        for (const auto& score : scores) {
            cout << " > " << score.name << " - " << score.timeTaken << " " << score.dateTime << endl;
        }
    }

    static time_t parseDateTime(const string& dateTime) {
        struct tm tm;
        strptime(dateTime.c_str(), " %a %b %d %H:%M:%S %Y\n", &tm);
        return mktime(&tm);
    }

public:
    void displayMenu() {
        while (true) {
            clearScreen();
            cout << "    >>~< KeyMaster >~<<";
            cout << endl;
            cout << endl;
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
            cout << "    >>~< KeyMaster >~<<";
            cout << endl;
            cout << endl;
            // Display instructions
            cout << " >> Type the alphabet (a-z) as fast as you can and press Enter.\n";
            cout << " >> Press Enter to start >>\n";
            cin.ignore(); // Ignore the newline character left by previous input
            cin.ignore(); // Wait for user to press Enter

            // Indicate that the test has started
            cout << " >> ";

            // Capture the start time
            auto start = chrono::high_resolution_clock::now();

            // Capture the user input
            string input;
            getline(cin, input);

            // Capture the end time
            auto end = chrono::high_resolution_clock::now();

            // Calculate the elapsed time
            chrono::duration<double> elapsed = end - start;

            // Check if the input is correct
            if (input == "abcdefghijklmnopqrstuvwxyz") {
                cout << "*** You typed the alphabet correctly! ***\n";
                cout << "       Time taken: " << elapsed.count() << " seconds.\n";
                cout << endl;
                cout << "Enter your name: ";
                string name;
                getline(cin, name);
                saveScore(name, elapsed.count());
            } else {
                cout << "???? You did not type the alphabet correctly. ????\n";
                cout << "                   ~Try Again~" << endl;
            }

            // Navigation options
            cout << endl;
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

    void showScores(bool showAll = false) {
        clearScreen();
        vector<ScoreEntry> scores = loadScores();

        if (scores.empty()) {
            cout << "No scores available.\n";
        } else {
            if (!showAll) {
                // Sorting by timeTaken to find top 3 performances
                vector<ScoreEntry> sortedScores = scores;
                sort(sortedScores.begin(), sortedScores.end());

                cout << "    >>~< KeyMaster >~<<";
                cout << endl;
                cout << endl;
                cout << "Top 3 Performances:\n";
                for (size_t i = 0; i < min(sortedScores.size(), static_cast<size_t>(3)); ++i) {
                    const auto& score = sortedScores[i];
                    cout << " *** " << i + 1 << ". " << score.name << " - " << score.timeTaken << " seconds on " << score.dateTime << endl;
                }

                // Sorting by date (newest first) for displaying last 15 scores
                sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
                    return parseDateTime(a.dateTime) > parseDateTime(b.dateTime);
                });

                cout << "\nLast 15 Scores:\n";
                size_t startIdx = scores.size() > 15 ? scores.size() - 15 : 0;
                displayScores(vector<ScoreEntry>(scores.begin() + startIdx, scores.end()));

                cout << "\n # Press >> 'A' >> Enter    -   All Scores " << endl;
                cout << " # Press >> Enter           -   return to the menu..." << endl;
                cout << " >> ";
                char choice;
                cin.ignore(); // Ignore the newline character left by previous input
                choice = cin.get();
                if (choice == 'A' || choice == 'a') {
                    showScores(true);
                    return;
                }
            } else {
                // Sorting by date (newest first) for displaying all scores
                sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
                    return parseDateTime(a.dateTime) > parseDateTime(b.dateTime);
                });

                cout << "\nAll Scores:\n";
                displayScores(scores);

                cout << "Press Enter to return to the menu...";
                cin.ignore(); // Ignore the newline character left by previous input
                cin.get(); // Wait for user to press Enter
            }
        }
    }
};

int main() {
    cout << endl;
    cout << endl;
    cout << "    >>~< KeyMaster >~<<";
    cout << endl;
    cout << endl;
    cout << " >     Press Enter...";
    cin.get();
    KeyMaster test;
    test.displayMenu();
    return 0;
}
