#include "sudoku.h"

using namespace std;

bool fitsUnit(Grid const &grid, size_t row, size_t col, size_t num)
{
    size_t startRow = row - (row - 1) % (Sudoku::ROWS / 3);
    size_t startCol = col - (col - 1) % (Sudoku::COLS / 3);

    for (size_t row = startRow; row != startRow + 3; ++row)
        for (size_t col = startCol; col != startCol + 3; ++col)
            if (grid.at(make_pair(row, col)) == num)
                return false;
    return true;
}
