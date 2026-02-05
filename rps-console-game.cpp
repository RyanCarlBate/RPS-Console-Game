#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

char choiceGenerator()
{
    char random_choice;
    // Declares a vector string variable named choices and define its values. Vector was used to utilize the .size()
    vector<char> choices = {'R', 'P', 'S'};
    // Set up the random number generator
    random_device generator;     // Seeder
    mt19937 engine(generator()); // Mersenne Twister engine
    // Declares an object named rangeOfSelection that will produce unbiased, equally likely random integer values within a specific range.
    uniform_int_distribution<size_t> rangeOfSelection(0, choices.size() - 1);
    // Declares a size_t variable named random_index to hold an index value.
    size_t random_index = rangeOfSelection(engine);
    // Use that random_index to pick the actual item from the list.
    random_choice = choices[random_index];

    return random_choice;
}

void clearScreen()
{
    cout << "\033[2J\033[H";
}

void mainMenu()
{
    cout << "Welcome to Rock-Paper-Scissor Game\n"
         << "1. Single-Player\n"
         << "2. Multiplayer\n"
         << "3. Exit\n"
         << "Insert your choice using number: ";
}

int menuChoiceCheck()
{
    int screenChoice;
    while (true)
    {
        cin >> screenChoice;
        if (screenChoice == 1 || screenChoice == 2 || screenChoice == 3)
        {
            break;
        }
        else
        {
            cout << "You insert wrong input. Please Try Again\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\033[2J\033[H";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Insert your choice using number: ";
        }
    }

    return screenChoice;
}

char attackInputCheck() 
{
    char attackInput;
    while (true)
    {
        cout << "Choose one letter for your attack (R=rock, P=paper, S=scissor): ";
        cin >> attackInput;
        if (attackInput == 'r' || attackInput == 'R' || attackInput == 'P' || attackInput == 'p' || attackInput == 'S' || attackInput == 's')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return attackInput;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
            cout << "You entered an invalid choice. Please enter again." << endl;
        }
    }
}

void showAttack(char attackInputResult)
{
    if (attackInputResult == 'r' || attackInputResult == 'R')
    {
        cout << "Your choice: Rock\n";
    }
    else if (attackInputResult == 'P' || attackInputResult == 'p')
    {
        cout << "Your choice: Paper\n";
    }
    else if (attackInputResult == 'S' || attackInputResult == 's')
    {
        cout << "Your choice: Scissor\n";
    }
}

void showEnemyAttack(char attackInputResult)
{
    if (attackInputResult == 'r' || attackInputResult == 'R')
    {
        cout << "Enemy choice: Rock\n";
    }
    else if (attackInputResult == 'P' || attackInputResult == 'p')
    {
        cout << "Enemy choice: Paper\n";
    }
    else if (attackInputResult == 'S' || attackInputResult == 's')
    {
        cout << "Enemy choice: Scissor\n";
    }
}

void defaultTimer()
{
    this_thread::sleep_for(chrono::seconds(1));
}

void evaluateWinner(char enemy, char attack)
{
    if ((enemy == 'R' && attack == 'P') || (enemy == 'R' && attack == 'p'))
    {
        cout << "You win!" << endl;
    }
    else if ((enemy == 'P' && attack == 'S') || (enemy == 'P' && attack == 's'))
    {
        cout << "You win!" << endl;
    }
    else if ((enemy == 'S' && attack == 'R') || (enemy == 'S' && attack == 'r'))
    {
        cout << "You win!" << endl;
    }
    else if ((enemy == 'P' && attack == 'R') || (enemy == 'P' && attack == 'r'))
    {
        cout << "You lose!" << endl;
    }
    else if ((enemy == 'S' && attack == 'P') || (enemy == 'S' && attack == 'p'))
    {
        cout << "You lose!" << endl;
    }
    else if ((enemy == 'R' && attack == 'S') || (enemy == 'R' && attack == 's'))
    {
        cout << "You lose!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }
}

void evaluateWinnerMultiplayer(char playerTwo, char playerOne)
{
    if ((playerTwo == 'R' && playerOne == 'P') || (playerTwo == 'r' && playerOne == 'p'))
    {
        cout << "Player 1 won!" << endl;
    }
    else if ((playerTwo == 'P' && playerOne == 'S') || (playerTwo == 'p' && playerOne == 's'))
    {
        cout << "Player 1 won!" << endl;
    }
    else if ((playerTwo == 'S' && playerOne == 'R') || (playerTwo == 's' && playerOne == 'r'))
    {
        cout << "Player 1 won!" << endl;
    }
    else if ((playerTwo == 'P' && playerOne == 'R') || (playerTwo == 'p' && playerOne == 'r'))
    {
        cout << "Player 2 won!" << endl;
    }
    else if ((playerTwo == 'S' && playerOne == 'P') || (playerTwo == 's' && playerOne == 'p'))
    {
        cout << "Player 2 won!" << endl;
    }
    else if ((playerTwo == 'R' && playerOne == 'S') || (playerTwo == 'r' && playerOne == 's'))
    {
        cout << "Player 2 won!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }
}

int main()
{
    int menuInput;
    int choice;
    char attack, playerOne, playerTwo;
    char enemy;
    mainMenu();
    menuInput = menuChoiceCheck();
    if (menuInput == 1)
    {
        clearScreen();
        cout << "You chose Single-Player";
        this_thread::sleep_for(chrono::seconds(1));
        clearScreen();
        do
        {
            enemy = choiceGenerator();
            attack = attackInputCheck();
            showAttack(attack);
            defaultTimer();
            showEnemyAttack(enemy);
            defaultTimer();
            evaluateWinner(enemy, attack);
            cout << "\nTry again?(1=yes/2=no): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
        } while (choice == 1);
    }
    else if (menuInput == 2)
    {
        clearScreen();
        cout << "You chose Multiplayer";
        this_thread::sleep_for(chrono::seconds(1));
        clearScreen();
        // Multiplayer will be added here later
        do
        {
            cout << "Player 1 turn:" << endl;
            playerOne = attackInputCheck();
            clearScreen();
            cout << "Player 2 turn:" << endl;
            playerTwo = attackInputCheck();
            clearScreen();
            evaluateWinnerMultiplayer(playerTwo, playerOne);
            cout << "\nTry again?(1=yes/2=no): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
        } while (choice == 1);
    }

    return 0;
}