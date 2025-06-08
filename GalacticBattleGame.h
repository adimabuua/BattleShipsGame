
/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#ifndef GALACTICBATTLEGAME_H
#define GALACTICBATTLEGAME_H
#include "Player.h"

class GalacticBattleGame {
    private:
    Player *player1;
    Player *player2;
    char *game_type;
    bool game_over;
    int round;

    public:
    GalacticBattleGame();
    GalacticBattleGame(Player *, Player *, char *);
    GalacticBattleGame(const GalacticBattleGame &);
    GalacticBattleGame& operator=(const GalacticBattleGame &);
    ~GalacticBattleGame();
    void menu();
    int player_to_start();
    void start_game(Player *, Player *);
    void play_game(Player *, Player *);



};
#endif // GALACTICBATTLEGAME_H