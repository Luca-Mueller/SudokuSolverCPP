#include "sudoku.h"
#include <iostream>

using namespace std;

bool Sudoku::solve(pair<size_t, size_t> field)
{
    if (field.first == 1 and field.second == 1)
        nRecursiveCalls = 1;
    else
        ++nRecursiveCalls;

    // base case: reached end, return true
    if (field.first > Sudoku::ROWS)
        return true;

    // skip field if its filled in
    if (grid[field] != 0)
        return solve(next(field));

    // recursive case: try next possible number and solve next field
    // if no more options for field --> return false
    for (size_t num = 1; num <= Sudoku::MAX; ++num)
    {
        if (    fitsRow(grid, field.first, num) and
                fitsCol(grid, field.second, num) and
                fitsUnit(grid, field.first, field.second, num) )
        {
            grid[field] = num;
            if (solve(next(field)))
                return true;
        }
            
        grid[field] = 0;
    }

    return false;
}
