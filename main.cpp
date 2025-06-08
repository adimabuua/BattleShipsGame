/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/

#include <iostream>
#include "GalacticBattleGame.h"
using namespace std;
int main() {
    cout << "Welcome to the Galactic Battle Game!" << endl;
    cout << "Initializing game..." << endl;

    // Create players
    Player *player1 = new Player("Player 1", 5, 5);
    Player *player2 = new Player("Player 2", 5, 5);

    // Create game instance
    GalacticBattleGame game(player1, player2, "Game 1");

    // Start the game
    game.menu();

    // Clean up
    delete player1;
    delete player2;

    cout << "Thank you for playing!" << endl;
    return 0;
    
}