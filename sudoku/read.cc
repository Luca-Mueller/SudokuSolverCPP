#include "sudoku.h"
#include <fstream>
#include <iostream>

using namespace std;

bool Sudoku::read(string const &fileName)
{   
    ifstream fileInput(fileName);       // file to initialize grid
    fileInput >> skipws;
    Grid newGrid;                       // new empty sudoku

    string line;                        // read rows from file
    for (size_t row = 1; row <= Sudoku::ROWS; ++row)
    {
        getline(fileInput, line);

        if (line.size() != Sudoku::ROWS)
            return false;               // input invalid

        for (size_t col = 1; col <= Sudoku::COLS; ++col)
            newGrid[make_pair(row, col)] = (line[col - 1] - '0');
    }

    grid = std::move(newGrid);          // assign new grid to Sudoku
    return true;                        // success
}
