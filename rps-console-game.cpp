#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

// Will move the generator here as a function later once I start cleaning up the code.
//int choiceGenerator()

int main()
{
    int choice;
    string random_choice, attack;
    do
    {
        // Declares a vector string variable named choices and define its values.
        vector <string> choices = {"rock", "paper", "scissor"};
        // Set up the random number generator
        random_device generator;
        mt19937 engine(generator()); 
        // Declares an object named rangeOfSelection that will produce unbiased, equally likely random integer values within a specific range.
        uniform_int_distribution <size_t> rangeOfSelection(0, choices.size() - 1);
        // Declares a size_t variable named random_index to hold an index value.
        size_t random_index = rangeOfSelection(engine);
        // Use that random_index to pick the actual item from the list.
        random_choice = choices[random_index];
        
        cout << "Choose one (rock, paper, scissor): ";
        cin >> attack;
        cout << "Enemy choice: " << random_choice << endl;
        if (random_choice == "rock" && attack == "paper")
        {
            cout << "You win!" << endl;
        }
        else if (random_choice == "paper" && attack == "scissor")
        {
            cout << "You win!" << endl;
        }
        else if (random_choice == "scissor" && attack == "rock")
        {
            cout << "You win!" << endl;
        }
        else if (random_choice == "paper" && attack == "rock")
        {
            cout << "You lose!" << endl;
        }
        else if (random_choice == "scissor" && attack == "paper")
        {
            cout << "You lose!" << endl;
        }
        else if (random_choice == "rock" && attack == "scissor")
        {
            cout << "You lose!" << endl;
        }
        else
        {
            cout << "Draw!" << endl;
        }
        cout << "\nTry again?(1=yes/2=no): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 1);

    return 0;
}