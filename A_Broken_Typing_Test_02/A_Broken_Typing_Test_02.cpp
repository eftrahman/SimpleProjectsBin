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

int main() {
    const string correctAlphabet = "abcdefghijklmnopqrstuvwxyz";

    // Display instructions
    cout << "Typing Test: Type the alphabet (a-z) as fast as you can and press Enter.\n";
    cout << "Press Enter to start...\n";
    cin.ignore(); // Wait for user to press Enter

    // Capture the start time
    auto start = chrono::high_resolution_clock::now();

    // Capture the user input
    string input;
    getline(cin, input);

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

    // Load and display previous scores
    vector<double> scores = loadScores();
    cout << "\nPrevious scores:\n";
    sort(scores.begin(), scores.end());
    for (double score : scores) {
        cout << score << " seconds\n";
    }

    return 0;
}

