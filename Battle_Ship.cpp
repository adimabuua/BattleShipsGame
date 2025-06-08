
/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#include "Battle_Ship.h"
#include <iostream>
#include <cstring>

using namespace std;

Battle_Ship::Battle_Ship(){
    this->name = new char[100];
    strcpy(this->name, "Unspecified");
    this->size = 0;
    this->current_hits = 0;
    this->hits_to_destroy = 0;
    this->laser_bursts = 0;
    this->is_sunk = false;
    this->symbol = '.';
}

Battle_Ship::Battle_Ship(const char *name, int size, int hits_to_destroy, int laser_bursts, bool is_sunk, char symbol) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->size = size;
    this->hits_to_destroy = hits_to_destroy;
    this->current_hits = 0;
    this->laser_bursts = laser_bursts;
    this->is_sunk = is_sunk;
    this->symbol = symbol;
}

Battle_Ship::Battle_Ship(const Battle_Ship &other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->size = other.size;
    this->hits_to_destroy = other.hits_to_destroy;
    this->current_hits = other.current_hits;
    this->laser_bursts = other.laser_bursts;
    this->is_sunk = other.is_sunk;
    this->symbol = other.symbol;
}

Battle_Ship& Battle_Ship::operator=(const Battle_Ship &other) {
    if (this != &other) {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->size = other.size;
        this->hits_to_destroy = other.hits_to_destroy;
        this->current_hits = other.current_hits;
        this->laser_bursts = other.laser_bursts;
        this->is_sunk = other.is_sunk;
        this->symbol = other.symbol;
    }
    return *this;
}

Battle_Ship::~Battle_Ship() {
    delete[] this->name;
}

const char* Battle_Ship::getName() {
    return this->name;
}

int Battle_Ship::getSize() {
    return this->size;
}

int Battle_Ship::getHitsToDestroy() {
    return this->hits_to_destroy;
}

int Battle_Ship::getCurrentHits() {
    return this->current_hits;
}

int Battle_Ship::getLaserBursts() {
    return this->laser_bursts;
}

bool Battle_Ship::getIsSunk() {
    return this->is_sunk;
}

char Battle_Ship::getSymbol() {
    return this->symbol;
}

void Battle_Ship::addCoordinate(int row, int col) {
    coordinates.push_back(make_pair(row, col));
}

const std::vector<std::pair<int, int> >& Battle_Ship::getCoordinates() const {
    return coordinates;
}


void Battle_Ship::beenHit(int row, int col) {
    for (auto &coord : coordinates) {
        if (coord.first == row && coord.second == col) {
            current_hits++;
            if (current_hits >= hits_to_destroy) {
                is_sunk = true;
            }
            return;
        }
    }
}



