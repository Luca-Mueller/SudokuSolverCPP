#include "sudoku.h"

using namespace std;

std::pair<size_t, size_t> next(std::pair<size_t, size_t> field)
{
    if (field.second == Sudoku::COLS)
        return make_pair(field.first + 1, 1);
    return make_pair(field.first, field.second + 1);
}
