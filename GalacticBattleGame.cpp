/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#include "GalacticBattleGame.h"
#include "Star_Destroyer.h"
#include "Mon_Calamari_Cruiser.h"
#include "X_Wing_Squadron.h"
#include "Tie_Fighter.h"
#include <iostream>
#include <cstring>

using namespace std;

GalacticBattleGame::GalacticBattleGame(){
    player1 = nullptr;
    player2 = nullptr;
    game_type = new char[100];
    strcpy(game_type, "Undefined");
    game_over = false;
    round = 0;
}

GalacticBattleGame::GalacticBattleGame(Player *p1, Player *p2, char *game_type) {
    this->player1 = new Player(*p1);
    this->player2 = new Player(*p2);
    this->game_type = new char[strlen(game_type) + 1];
    strcpy(this->game_type, game_type);
    this->game_over = false;
    this->round = 0;
}
GalacticBattleGame::GalacticBattleGame(const GalacticBattleGame &other) {
    this->player1 = new Player(*other.player1);
    this->player2 = new Player(*other.player2);
    this->game_type = new char[strlen(other.game_type) + 1];
    strcpy(this->game_type, other.game_type);
    this->game_over = other.game_over;
    this->round = other.round;
}
GalacticBattleGame& GalacticBattleGame::operator=(const GalacticBattleGame &other) {
    if (this != &other) {
        delete player1;
        delete player2;
        delete[] game_type;

        this->player1 = new Player(*other.player1);
        this->player2 = new Player(*other.player2);
        this->game_type = new char[strlen(other.game_type) + 1];
        strcpy(this->game_type, other.game_type);
        this->game_over = other.game_over;
        this->round = other.round;
    }
    return *this;
}
GalacticBattleGame::~GalacticBattleGame() {
    delete player1;
    delete player2;
    delete[] game_type;
}

int GalacticBattleGame::player_to_start() {
   
    return (rand() % 2) + 1;  
}


void GalacticBattleGame::menu(){
    cout << "Welcome to Galactic NCC Star Wars Battle"<< endl;
    cout << "Select Game Mode:"<< endl;
    cout << "1. The Swiftstrike "<< endl;
    cout << "2. The Starlight Clash "<< endl;
    cout << "3. Wrath of Titans "<< endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    char *temp; 

    switch(choice)
    {
        case 1:
        
        temp = new char[100];
        cout <<"Enter player 1 name: ";
        cin >> temp;
        player1 = new Player(temp, 5,8);

        cout <<"Enter player 2 name: ";
        cin >> temp;
        player2 = new Player(temp, 5,8);
        strcpy(game_type, "The Swiftstrike");
        delete[] temp;
        start_game(player1, player2);
        break;

        case 2:
        temp = new char[100];
        cout <<"Enter player 1 name: ";
        cin >> temp;
        player1 = new Player(temp, 8,10);

        cout <<"Enter player 2 name: ";
        cin >> temp;
        player2 = new Player(temp, 8,10);
        strcpy(game_type, "The Starlight Clash");
        delete[] temp;
        start_game(player1, player2);
        break;

        case 3:
        temp = new char[100];
        cout <<"Enter player 1 name: ";
        cin >> temp;
        player1 = new Player(temp, 10,12);

        cout <<"Enter player 2 name: ";
        cin >> temp;
        player2 = new Player(temp, 10,12);
        strcpy(game_type, "Wrath of Titans");
        delete[] temp;
        start_game(player1, player2);
        break;

        default:
        cout <<"Invalid input. Try again" << endl;
        break;
    }
}

void GalacticBattleGame::start_game(Player *p1, Player *p2){
    if(player_to_start() == 1)
    {
        if(strcmp(game_type, "The Swiftstrike"))
        {
            p1->fleet.push_back(new Star_Destroyer()); 
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());

            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

        }

        else if(strcmp(game_type, "The Starlight Clash"))
        {
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());

            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

        }

        else
        {
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());


            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

        }

        cout << "Player 1: " << p1->get_name() << " deploys fleet now" << endl;
        p1->deploy_fleet();

        cout << "Player 2: " << p2->get_name() << " deploys fleet now" << endl;
        p2->deploy_fleet();

        play_game(p1, p2);

    }

    else
    {
        if(strcmp(game_type,"The Swiftstrike"))
        {
            p2->fleet.push_back(new Star_Destroyer()); 
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());

        }

        else if(strcmp(game_type ,"The Starlight Clash"))
        {
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());

        }

        else
        {
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Star_Destroyer());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new Mon_Calamari_Cruiser());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new X_Wing_Squadron());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());
            p2->fleet.push_back(new Tie_Fighter());

            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Star_Destroyer());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new Mon_Calamari_Cruiser());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new X_Wing_Squadron());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());
            p1->fleet.push_back(new Tie_Fighter());

        }
        
        cout << "Player 2: " << p2->get_name() << " deploys fleet now" << endl;
        p2->deploy_fleet();

        cout << "Player 1: " << p1->get_name() << " deploys fleet now" << endl;
        p1->deploy_fleet();

        play_game(p1, p2);
}
}

void GalacticBattleGame::play_game(Player *p1, Player *p2)
{
    if(player_to_start() == 1)
    {
        while(!game_over)
        {
            cout <<"\nYour ship grid:\n";
            p1->ship_grid.display_grid();

            cout << "\nYour attack grid:\n";
            p1->attack_grid.display_grid();

            cout <<"Player 1: " << p1->get_name() << " shoots now " << endl;
            p1->shoot(p2);
            
            if(p2->all_ships_sunk())
            {
                cout << "Player 1: " << p1->get_name() << " wins!" << endl;
                game_over = true;
                break;
            }
            
            cout <<"\nYour ship grid:\n";
            p2->ship_grid.display_grid();

            cout << "\nYour attack grid:\n";
            p2->attack_grid.display_grid();
            cout <<"Player 2: " << p2->get_name() << " shoots now " << endl;
            p2->shoot(p1);
            
            if(p1->all_ships_sunk())
            {
                cout << "Player 2: " << p2->get_name() << " wins!" << endl;
                game_over = true;
                break;
            }

            round++;
            cout << "Round: " << round << endl;
            p1->display_stats();
            cout <<"\n";
            p2->display_stats();
            
            p1->pop_ship();
            p2->pop_ship();
        }

    }

    else
    {
        while(!game_over)
        {
            cout <<"\nYour ship grid:\n";
            p2->ship_grid.display_grid();
            cout << "\nYour attack grid:\n";
            p2->attack_grid.display_grid();

            cout <<"Player 2: " << p2->get_name() << " shoots now " << endl;
            p2->shoot(p1);
            
            if(p1->all_ships_sunk())
            {
                cout << "Player 2: " << p2->get_name() << " wins!" << endl;
                game_over = true;
                break;
            }

            cout <<"\nYour ship grid:\n";
            p1->ship_grid.display_grid();

            cout << "\nYour attack grid:\n";
            p1->attack_grid.display_grid();
            cout <<"Player 1: " << p1->get_name() << " shoots now " << endl;
            p1->shoot(p2);
            
            if(p2->all_ships_sunk())
            {
                cout << "Player 1: " << p1->get_name() << " wins!" << endl;
                game_over = true;
                break;
            }

            round++;
            cout << "Round: " << round << endl;
            p1->display_stats();
            cout <<"\n";
            p2->display_stats();
            
            p1->pop_ship();
            p2->pop_ship();
        }
    }
}