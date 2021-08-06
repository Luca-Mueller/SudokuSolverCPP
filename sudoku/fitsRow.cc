#include "sudoku.h"

using namespace std;

bool fitsRow(Grid const &grid, size_t row, size_t num)
{
    for (size_t col = 1; col <= Sudoku::COLS; ++col)
        if (grid.at(make_pair(row, col)) == num)
            return false;
    return true;
}
