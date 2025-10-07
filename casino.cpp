#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void showIntro();
void showInstructions();

int main() {
    srand(time(0)); // initialize random seed
    system("cls");
    showIntro();

    string playerName;
    int balance;
    char playAgain;

    cout << "\nEnter your name: ";
    getline(cin, playerName);
    cout << "Enter your total inital amount  ($): ";
    cin >> balance;

    cout << "\nWelcome, " << playerName << "! Let's begin the game.\n";

    do {
        showInstructions();

        int betAmount;
        do {
            cout << "\nEnter your bet amount ($): ";
            cin >> betAmount;
            if (betAmount > balance)
                cout << "Insufficient balance! Try a lower amount.\n";
        } while (betAmount > balance);

        cout << "\nChoose your prediction type:\n";
        cout << "1. Guess the exact number (1 - 10)\n";
        cout << "2. Guess Even number\n";
        cout << "3. Guess Odd number\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        int rolledNumber = rand() % 10 + 1;
        bool isWinner = false;

        switch (choice) {
            case 1: {
                int userGuess;
                cout << "\nEnter your guessed number (1–10): ";
                cin >> userGuess;
                if (userGuess == rolledNumber)
                    isWinner = true;
                break;
            }
            case 2:
                if (rolledNumber % 2 == 0)
                    isWinner = true;
                break;
            case 3:
                if (rolledNumber % 2 != 0)
                    isWinner = true;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                continue;
        }

        cout << "\nThe wheel stopped at number: " << rolledNumber << endl;

        if (isWinner) {
            int winAmount = betAmount * 10;
            cout << " Congratulations! You won $" << winAmount << "!\n";
            balance += winAmount;
        } else {
            cout << " Oops! You lost $" << betAmount << ". Better luck next time.\n";
            balance -= betAmount;
        }

        cout << "\nYour current balance: $" << balance << endl;
        if (balance <= 0) {
            cout << "\nYou don't have enough money to continue.\n";
            break;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThank you for playing, " << playerName << "! Final Balance: $" << balance << endl;
    cout << "\nProject: A.S Casino Game (Mini Project - OOP with C++)\n";
    cout << "Developed by: A. Agnes Swetha & Sowthamini G\n";
    cout << "Duration: March 2023 - April 2023\n";
    cout << "IDE: Code::Blocks\n";
    cout << "-------------------------------------------\n";
    cout << "Goodbye!\n";

    getch();
    return 0;
}

void showIntro() {
    string banner =
        "\n=========================================================\n"
        "        A.S CASINO GAME - Mini Project (OOP in C++)       \n"
        "=========================================================\n";
    for (char c : banner) {
        cout << c;
        Sleep(8);
    }
}

void showInstructions() {
    system("cls");
    cout << "\n=================== GAME INSTRUCTIONS ===================\n";
    cout << "1. Choose any number between 1 - 10.\n";
    cout << "2. If your guess is correct, you win 10x your bet!\n";
    cout << "3. If you lose, the bet amount is deducted from your balance.\n";
    cout << "=========================================================\n";
}
