/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Battle_Ship.h"
#include "Grid.h"
#include <vector>

using namespace std;

class Player{
    public:
    char *name;
    vector<Battle_Ship*> fleet;
    Grid ship_grid;
    Grid attack_grid;


    public:
    Player();
    Player(const char *, int, int);
    Player(const Player &);
    Player& operator=(const Player &);
    ~Player();
    void deploy_fleet();
    void shoot(Player *);
    void set_name(char *);
    const char* get_name();
    int letter_to_number(char);
    bool parse_coordinate(const char *, int &, int &);
    int highest_laser_bursts();
    void display_stats();
    void pop_ship();
    bool all_ships_sunk();
    int no_star_destroyers();
    int no_mon_calamari_cruisers();
    int no_x_wing_squadrons();
    int no_tie_fighters();
    int ships_lost(char *);

    


   
    


};
#endif // PLAYER_H