/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#include "Player.h"
#include <iostream>
#include <cstring>

using namespace std;

Player::Player(){
    name = new char[100];
    strcpy(name, "Unnamed");
    this->ship_grid.resize(0,0);
    this->attack_grid.resize(0,0);
}

Player::Player(const char *n, int rows, int cols) 
    : name(new char[strlen(n) + 1]), ship_grid(rows, cols), attack_grid(rows, cols) {
    strcpy(name, n);
    
    for (int i = 0; i < fleet.size(); i++) {
        fleet[i] = nullptr;
    }
}

Player::Player(const Player &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    ship_grid = other.ship_grid;
    attack_grid = other.attack_grid;

    for (int i = 0; i < fleet.size(); i++) {
        if (other.fleet[i] != nullptr) {
            fleet[i] = new Battle_Ship(*other.fleet[i]);
        } else {
            fleet[i] = nullptr;
        }
    }
}

Player& Player::operator=(const Player &other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        ship_grid = other.ship_grid;
        attack_grid = other.attack_grid;

        for (int i = 0; i < fleet.size(); i++) {
            delete fleet[i];
            if (other.fleet[i] != nullptr) {
                fleet[i] = new Battle_Ship(*other.fleet[i]);
            } else {
                fleet[i] = nullptr;
            }
        }
    }
    return *this;
}
Player::~Player() {
    delete[] name;
    for (int i = 0; i < 15; i++) {
        delete fleet[i];
    }
}

int Player::letter_to_number(char letter) {
    return toupper(letter) - 'A';
}


bool Player::parse_coordinate(const char *coord, int& row, int& col) {
    string coordStr(coord);
    if (coordStr.length() < 2) return false;
    
    char letter = coord[0];
    string number = coordStr.substr(1);
    
    if (!isalpha(letter)) return false;
    for (char c : number) {
        if (!isdigit(c)) return false;
    }
    
    row = letter_to_number(letter);
    col = stoi(number) - 1;
    return true;
}



void Player::deploy_fleet()
{

   for(size_t i = 0; i < fleet.size(); i++)
    {
        if(fleet[i] == nullptr) 
        continue;
        
        bool valid_placement = false;
        while(!valid_placement)
        {
            cout << "Placing " << fleet[i]->getName() << " (size: " << fleet[i]->getSize() << ")\n";
            cout << "Enter coordinates (e.g. A1 B1): ";
            string start_pos, end_pos;
            cin >> start_pos >> end_pos;
            
           int start_row, start_col, end_row, end_col;
            if (!parse_coordinate(start_pos.c_str(), start_row, start_col) || 
                !parse_coordinate(end_pos.c_str(), end_row, end_col))
            {
                cout << "Invalid input format! Use letter+number (e.g. a1)\n";
                continue;
            }

            start_row = letter_to_number(start_pos[0]);
            start_col = stoi(start_pos.substr(1)) - 1;
            end_row = letter_to_number(end_pos[0]);
            end_col = stoi(end_pos.substr(1)) - 1;

            
            if(start_row < 0 || start_row >= ship_grid.getRows() ||
               start_col < 0 || start_col >= ship_grid.getCols() ||
               end_row < 0 || end_row >= ship_grid.getRows() ||
               end_col < 0 || end_col >= ship_grid.getCols())
            {
                cout << "Start-row = " << start_row << ", Start-col = " << start_col 
                     << ", End-row = " << end_row << ", End-col = " << end_col << endl;
                cout << "getRows = " << ship_grid.getRows() << ", getCols = " << ship_grid.getCols() << endl;
                cout << "Invalid coordinates! Try again.\n";
                continue;
            }
            
            int row_diff = end_row - start_row;
            int col_diff = end_col - start_col;
            int ship_length = max(abs(row_diff), abs(col_diff)) + 1;
            

            if(ship_length != fleet[i]->getSize())
            {
                cout << "Invalid ship length! Must be " << fleet[i]->getSize() << "\n";
                continue;
            }
            
            bool path_clear = true;
            int row_step = (row_diff == 0) ? 0 : row_diff / abs(row_diff);
            int col_step = (col_diff == 0) ? 0 : col_diff / abs(col_diff);
            
            for(int j = 0; j < ship_length; j++)
            {
                int curr_row = start_row + (j * row_step);
                int curr_col = start_col + (j * col_step);
                if(ship_grid.at(curr_row, curr_col) != '*')
                {
                    path_clear = false;
                    break;
                }
            }
            
            if(!path_clear)
            {
                cout << "Path overlaps with another ship! Try again.\n";
                continue;
            }
            
            // Place ship
            for(int j = 0; j < ship_length; j++)
            {
                int curr_row = start_row + (j * row_step);
                int curr_col = start_col + (j * col_step);
                char symb;
                symb = fleet[i]->getSymbol();
                ship_grid.set(curr_row, curr_col, symb);
                fleet[i]->addCoordinate(curr_row, curr_col);
            }
            
            valid_placement = true;
            cout << "Ship placed successfully!\n";
            cout << "\nYour grid:\n";
            ship_grid.display_grid();
        }
    }
}

int Player::highest_laser_bursts() {
    int max_bursts = 0;
    for (const auto& ship : fleet) {
        if (ship != nullptr && ship->getLaserBursts() > max_bursts) {
            max_bursts = ship->getLaserBursts();
        }
    }
    return max_bursts;
}

void Player::shoot(Player *opponent){

    cout << "Enter attack coordinates (can shoot " << highest_laser_bursts() <<" : " << endl; 
    string coord;
    cin >> coord;
    vector<pair<int, int> > shots;
    bool valid_input = false;
    int num_shots = highest_laser_bursts();
    int count = 0;

    // Validate input

        
        // Read exactly num_shots coordinates
        while(count < num_shots) {
            int row, col;
            if(!parse_coordinate(coord.c_str(), row, col)) {
                cout << "Invalid coordinate format: " << coord << endl;
                shots.clear();
                break;
            }

            row = letter_to_number(coord[0]);
            col = stoi(coord.substr(1)) - 1;
            
            // Validate bounds
            if(row < 0 || row >= attack_grid.getRows() || 
               col < 0 || col >= attack_grid.getCols()) {
                cout << "Coordinate out of bounds: " << coord << endl;
                shots.clear();
                break;
            }
            
            // Check if already shot
            if(attack_grid.at(row, col) != '*') {
                cout << "Already fired at: " << coord << endl;
                shots.clear();
                break;
            }
            
            shots.push_back(std::make_pair(row, col));
            count++;
        }
        
        if(shots.size() == num_shots) {
            valid_input = true;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    // Process all shots
    for(const auto& shot : shots) {
        int row = shot.first;
        int col = shot.second;
        
        if(opponent->ship_grid.at(row, col) != '*') {
            cout << char('A' + row) << (col + 1) << ": HIT!\n";
            attack_grid.set(row, col, opponent->ship_grid.at(row, col));
            opponent->ship_grid.set(row, col,'X');

            for(int i = 0; i < opponent->fleet.size(); i++) {
                if(opponent->fleet[i] != nullptr) {
                    const auto& coords = opponent->fleet[i]->getCoordinates();
                    for(const auto& coord : coords) {
                        if(coord.first == row && coord.second == col) {
                            opponent->fleet[i]->beenHit(row, col);
                            if(opponent->fleet[i]->getIsSunk()) {
                                cout << opponent->fleet[i]->getName() << " has been sunk!\n";
                            }
                            break;
                        }
                    }
                }
            }
            
        } else {
            cout << char('A' + row) << (col + 1) << ": MISS!\n";
            attack_grid.set(row, col, '0');
        }
    }
}


void Player::pop_ship()
{
    for(size_t i = 0; i < fleet.size(); i++)
    {
        if(fleet[i] != nullptr && fleet[i]->getIsSunk())
        {
            delete fleet[i];
            fleet[i] = nullptr;
        }
    }
}

bool Player::all_ships_sunk() {
    for (const auto& ship : fleet) {
        if (ship != nullptr && !ship->getIsSunk()) {
            return false;
        }
    }
    return true;
}

void Player::display_stats()
{
    cout << "Player: " << name << endl;
    cout << "Hits: " << attack_grid.getHits() << endl;
    cout << "Misses: " << attack_grid.getMisses() << endl;
    cout << "Lost: " << attack_grid.getCellsLost() <<" cell(s)" << endl;
    cout << "Lost Star Destroyers (" << no_star_destroyers() <<"): " << ships_lost("Star Destroyer") << endl;
    cout << "Lost Mon Calamari Cruisers (" << no_mon_calamari_cruisers() <<"): " << ships_lost("Mon Calamari Cruiser") << endl;
    cout << "Lost X-Wing Squadrons (" << no_x_wing_squadrons() <<"): " << ships_lost("X-Wing Squadron") << endl;    
    cout << "Lost TIE Fighters (" << no_tie_fighters() <<"): " << ships_lost("TIE Fighter") << endl;
    
}

int Player::no_star_destroyers() {
    int count = 0;
    for (const auto& ship : fleet) {
        if (ship != nullptr && strcmp(ship->getName(), "Star Destroyer") == 0) {
            count++;
        }
    }
    return count;
}
int Player::no_mon_calamari_cruisers() {
    int count = 0;
    for (const auto& ship : fleet) {
        if (ship != nullptr && strcmp(ship->getName(), "Mon Calamari Cruiser") == 0) {
            count++;
        }
    }
    return count;
}

int Player::no_x_wing_squadrons() {
    int count = 0;
    for (const auto& ship : fleet) {
        if (ship != nullptr && strcmp(ship->getName(), "X-Wing Squadron") == 0) {
            count++;
        }
    }
    return count;
}

int Player::no_tie_fighters() {
    int count = 0;
    for (const auto& ship : fleet) {
        if (ship != nullptr && strcmp(ship->getName(), "TIE Fighter") == 0) {
            count++;
        }
    }
    return count;
}

int Player::ships_lost(char* ship_name) {
    int count = 0;
    for (std::vector<Battle_Ship*>::const_iterator it = fleet.begin(); it != fleet.end(); ++it) {
        Battle_Ship* ship = *it;
        if (ship != nullptr && strcmp(ship->getName(), ship_name) == 0 && ship->getIsSunk()) {
            count++;
        }
    }
    return count;
}




const char* Player::get_name() {
    return name;
}



