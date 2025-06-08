/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#include <vector>
#ifndef BATTLE_SHIP_H
#define BATTLE_SHIP_H

class Battle_Ship{
    protected:
    char *name;
    int size;
    int hits_to_destroy;
    int current_hits;
    int laser_bursts;
    bool is_sunk;
    char symbol;
    std::vector<std::pair<int, int> > coordinates;

        

    public:
    Battle_Ship();
    Battle_Ship(const char *, int, int, int, bool, char);
    Battle_Ship(const Battle_Ship &);
    Battle_Ship& operator=(const Battle_Ship &);
    virtual ~Battle_Ship();
    const char *getName();
    int getSize();
    int getHitsToDestroy();
    int getCurrentHits();
    int getLaserBursts();
    bool getIsSunk();
    char getSymbol();
    void addCoordinate(int row, int col);
    const std::vector<std::pair<int, int> >& getCoordinates() const;
    void beenHit(int, int);
    void shoot();
    bool hit();

            
};
#endif // BATTLE_SHIP_H