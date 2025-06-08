
/* 
* Emmanuel Monye - 2406254
* I read and accept the submission rules and the extra rules specified in each question. 
* This is my own work that is done by me only 
*/
#include "Grid.h"
#include <iostream>
#include <vector>

using namespace std;

Grid::Grid(){
    grid_row = 5; // Default number of rows
    grid_column = 5; // Default number of columns
    grid.resize(grid_row, vector<char>(grid_column, '*')); // Initialize grid with '*'
}


Grid::Grid(int rows, int cols)  {
    grid_row = rows;
    grid_column = cols;
    grid.resize(grid_row, vector<char>(grid_column, '*'));
}

void Grid::resize(int rows, int cols) {
    grid_row = rows;
    grid_column = cols;
    grid.resize(grid_row, vector<char>(grid_column, '*'));
}

int Grid::getRows() {
    return grid_row;
}

int Grid::getCols() {
    return grid_column;
}

char& Grid::at(int row, int col) {
    if (row < 0 || row >= grid_row || col < 0 || col >= grid_column) {
        throw out_of_range("Grid index out of range");
    }
    return grid[row][col];
}

void Grid::display_grid()  {
   
    cout << "   "; 
    for(int j = 0; j < grid_column; j++) {
        cout << " " << j + 1 << " ";
    }
    cout << endl;

    
    for(int i = 0; i < grid_row; i++) {
    
        cout << " " << char('A' + i) << " ";
        
        
        for(int j = 0; j < grid_column; j++) {
            cout << " " << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Grid::set(int row, int col, char value) {
    if (row < 0 || row >= grid_row || col < 0 || col >= grid_column) {
        throw out_of_range("Grid index out of range");
    }
    grid[row][col] = value;
}

int Grid::getHits() {
    int hits = 0;
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == 'X') {
                hits++;
            }
        }
    }
    return hits;
}

int Grid::getMisses() {
    int misses = 0;
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == '0') {
                misses++;
            }
        }
    }
    return misses;
}

void Grid::setHits(int hits) {
    for (int i = 0; i < grid_row; i++) {
        for (int j = 0; j < grid_column; j++) {
            if (grid[i][j] == 'X') {
                hits++;
            }
        }
    }
}

void Grid::setMisses(int misses) {
    for (int i = 0; i < grid_row; i++) {
        for (int j = 0; j < grid_column; j++) {
            if (grid[i][j] == '0') {
                misses++;
            }
        }
    }
}   

int Grid::getCellsLost() {
    int lost = 0;
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == 'X' || cell == '0') {
                lost++;
            }
        }
    }
    return lost;
}

