#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int main() {
    // Step 1: Display instructions
    cout << "Typing Test: Type the alphabet (a-z) as fast as you can and press Enter.\n";
    cout << "Press Enter to start...\n";
    cin.ignore(); // Wait for user to press Enter

    // Step 2: Capture the start time
    auto start = chrono::high_resolution_clock::now();

    // Step 3: Capture the user input
    string input;
    getline(cin, input);

    // Step 4: Capture the end time
    auto end = chrono::high_resolution_clock::now();

    // Step 5: Calculate the elapsed time
    chrono::duration<double> elapsed = end - start;

    // Step 6: Check if the input is correct
    if (input == "abcdefghijklmnopqrstuvwxyz") {
        cout << "You typed the alphabet correctly!\n";
    } else {
        cout << "You did not type the alphabet correctly.\n";
    }

    // Step 7: Display the elapsed time
    cout << "Time taken: " << elapsed.count() << " seconds.\n";

    return 0;
}

