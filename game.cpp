#include <iostream>
#include <random>

using namespace std;

string checkWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if (
        (userChoice == "Rock" && computerChoice == "Scissors") ||
        (userChoice == "Scissors" && computerChoice == "Paper") ||
        (userChoice == "Paper" && computerChoice == "Rock")
    ) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    string choices[] = {"Rock", "Paper", "Scissors"};

    while (true) {
        cout << "\nWelcome to Rock, Paper, Scissors!" << endl;
        cout << "Choose Rock, Paper, or Scissors: ";

        string userChoice;
        cin >> userChoice;

        for (char &c : userChoice) {
            c = toupper(c);
        }

        if (userChoice != "ROCK" && userChoice != "PAPER" && userChoice != "SCISSORS") {
            cout << "Invalid choice. Please choose Rock, Paper, or Scissors." << endl;
            continue;
        }

        uniform_int_distribution<int> distribution(0, 2);
        string computerChoice = choices[distribution(gen)];
        cout << "Computer chose " << computerChoice << endl;
        
        cout << checkWinner(userChoice, computerChoice) << endl;
        
        cout << "Do you want to play again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        for (char &c : playAgain) {
            c = toupper(c);
        }

        if (playAgain != "YES") {
            cout << "The End!" << endl;
            break;
        }
    }

    return 0;
}
