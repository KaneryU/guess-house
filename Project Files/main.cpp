#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

double GuessWork(){
int didPlayerWin, chosenNumber;
didPlayerWin = 0;
int number = 1;
int newValid = 0;
int allowedGuesses = 3;
int usedGuesses = 0;
bool outOfGuesses = false;
srand (time(NULL));
chosenNumber = rand() % 10 + 1;
                while (didPlayerWin == 0 && !outOfGuesses){
                    cout << "Choose a number, 1-10" << endl;
                    newValid = 0;
                    cin >> number;
                    if  (number >= 11){
                        while (newValid == 0){
                        cout << "\nBad Number! Choose one under 10.\n" << endl;
                        cout << "\n" << endl;
                        cin >> number;
                        if ( number >= 11){
                            newValid = 0;
                        }else if (number >= 11){
                            newValid = 1;
                            }
                        }


                    }
                    if (chosenNumber == number){
                        didPlayerWin = 1;
                    }else{
                        didPlayerWin = 0;
                        if (usedGuesses == allowedGuesses){
                            outOfGuesses = true;
                            cout << "It was " << chosenNumber << "," << endl;
                        } else{
                         usedGuesses++;
                            cout << "Wrong! You have " <<  allowedGuesses - usedGuesses + 1<< " guesses left\n" << endl;
                        }
                    }

                }

return didPlayerWin;
}





int main()
{
cout << "Welcome to the GUESS HOUSE!" << endl;
cout << "We gave you 500 points!" << endl;
int points = 500;
string currentCommand;
int i = 0;
int newPoints;
int type = 0;
int newValids = 0;
int valid = 0;
cout << "Here are the Commands:\n!play - Play one game, it costs 100 points.\n!bal - Shows your balance.\n!exit - Finish playing, and turn the points you earned into money. Exchange rate is points x 1.5 \n!help - Display this message" << endl;
while (i == 0){
        while (valid == 0){
            cout << "Enter a command: ";
            cin >> currentCommand;
            cout << "\n" << endl;
            if (currentCommand == "!exit"){
                cout << "You earned $" << points*1.5 << " dollars, ("<< points << " points) by the time you finished.\n\n" << endl;
                return 111;

            }else if (currentCommand == "!play"){
                cout << "What kind of bet?\n2 (you can loose 2x your money, and can earn 2x)\n4 (You can loose 4x and gain 4x)\n" << endl;
                cin >> type;
                if (type != 2 && type != 4){
                    while (newValids == 0){
                        cout << "\nBad Number!\n" << endl;
                        cout << "What kind of bet?\n2 (you can loose 2x your money, and can earn 2x)\n4 (You can loose 4x and gain 4x)\n" << endl;
                        cin >> type;
                        if (type != 2 && type != 4){
                            newValids = 0;
                        }else if (type == 2 || type == 4){
                            newValids = 1;
                        }
                    }
                }
                cout << "Playing!\n\n" << endl;
                double won = GuessWork();
                if (won == 1){
                    cout << "You won!\n\n" << endl;
                    points = points + 100 * type;
                }else if (won == 0){
                    cout << "You lost :(\n\n" << endl;
                    points = points - 100 * type;

                }else{
                    cout << "An unknown error occurred.\n\n" << endl;
                    return 112;
                }
                cout << "Your balance is: " << points << "\n\n" << endl;

            }else if (currentCommand == "!bal"){
            newPoints = points * 1.5;
            cout << "You have " << points << " points, which is $" << newPoints << " dollars.\n\n" << endl;
            }else if (currentCommand == "!help"){
                cout << "Here are the Commands:\n!play - Play one game, it costs 100 points.\n!bal - Shows your balance.\n!exit - Finish playing, and turn the points you earned into money.\n!help - Display this message\n\n" << endl;
            }else{
                cout << "Invalid Input! Try again!\n\n" << endl;
                }
        }
    }
}
