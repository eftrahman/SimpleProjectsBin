#include <iostream>
#include <chrono>
#include <string>

using namespace std;

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

    // Check if the input is correct
    if (input == correctAlphabet) {
        cout << "You typed the alphabet correctly!\n";
    } else {
        cout << "You did not type the alphabet correctly.\n";
        cout << "Mistakes: ";
        showMistakes(input, correctAlphabet);
    }

    // Display the elapsed time
    cout << "Time taken: " << elapsed.count() << " seconds.\n";

    return 0;
}
