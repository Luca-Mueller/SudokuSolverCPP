#include "sudoku.h"
#include <iostream>

using namespace std;

void Sudoku::print() const
{
    for (size_t row = 1; row <= Sudoku::ROWS; ++row)
    {
        for (size_t col = 1; col <= Sudoku::COLS; ++col)
        {
            size_t num = grid.at(make_pair(row, col));
            num < Sudoku::MIN or num > Sudoku::MAX ? cout << "." : cout << num;

            if (col == (Sudoku::COLS / 3) or col == (Sudoku::COLS / 3) * 2) 
                cout << " | ";
            else
                cout << ' ';
        }
        cout << '\n';

        if (row == (Sudoku::ROWS / 3) or row == (Sudoku::COLS / 3) * 2)
            cout << string((Sudoku::ROWS * 2 + 3), '-') << '\n';
    }
}
