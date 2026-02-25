#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 
#include<string>

using namespace std;


void playGame() {
    int secretCode = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "\n****************************************" << endl;
    cout << "   NEW GAME STARTED: Guess (1 to 100)    " << endl;
    cout << "*******************************************" << endl;

    while (true) {
        cout << "Enter your guess: ";
        
        
        if (!(cin >> userGuess)) {
            cout << "[!] Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        attempts++;

        if (userGuess > secretCode) {
            cout << ">> Too HIGH! Try a smaller number." << endl;
        } else if (userGuess < secretCode) {
            cout << ">> Too LOW! Try a larger number." << endl;
        } else {
            cout << "\n[SUCCESS] You nailed it! The number was " << secretCode << "." << endl;
            cout << "[STATS] Total attempts: " << attempts << endl;
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    string choice;

    cout << "Welcome to the Number Guessing Game #1" << endl;

    do {
        playGame();
        
        cout << "\nWould you like to play another round? (Yes/No): ";
        cin >> choice;
        
    } while (choice == "Yes" || choice == "No");

    cout << "\nThank you for playing! Task #1 Complete." << endl;
    return 0;
}