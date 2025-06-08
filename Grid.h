/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:
    int grid_row;
    int grid_column;
    std::vector<std::vector<char> > grid;

public:
    // Constructor with default size 5x5
    Grid();
    Grid(int, int);

    // Resize grid
    void resize(int, int);

    // Getter methods
    int getRows();
    int getCols();

    // Access grid elements
    void display_grid();
    
    char& at(int, int); 

    void set(int, int, char );

    int getHits();
    int getMisses();
    void setHits(int);
    void setMisses(int);
    int getCellsLost();


};

#endif

