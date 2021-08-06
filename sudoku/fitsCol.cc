#include "sudoku.h"

using namespace std;

bool fitsCol(Grid const &grid, size_t col, size_t num)
{
    for (size_t row = 1; row <= Sudoku::ROWS; ++row)
        if (grid.at(make_pair(row, col)) == num)
            return false;
    return true;
}
