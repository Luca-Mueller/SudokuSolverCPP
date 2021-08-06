#ifndef SUDOKU
#define SUDOKU

#include <string>
#include <utility>
#include <map>

using Grid = std::map<std::pair<size_t, size_t>, size_t>;

struct Sudoku
{
    Grid grid;                      // 9 x 9 sudoku grid
    size_t nRecursiveCalls;         // calls to 'solve()'

    enum
    {   DIM = 9,
        ROWS = DIM,
        COLS = ROWS,
        MIN = 1,
        MAX = DIM,
    };
    
    bool read(std::string const &fileName);         // read grid from file
    void print() const;                             // print grid to console
                                                    // solve recursive
    bool solve(std::pair<size_t, size_t> field = std::make_pair(1, 1));
};


// utility functions
bool fitsRow(Grid const &grid, size_t row, size_t num);
bool fitsCol(Grid const &grid, size_t col, size_t num);
bool fitsUnit(Grid const &grid, size_t row, size_t col, size_t num);
std::pair<size_t, size_t> next(std::pair<size_t, size_t> field);

#endif
