#include "sudoku/sudoku.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Sudoku sudoku;
    
    string fileName{ "grids/input.txt" };
    
    if (argc == 2)
    {
        fileName = argv[1];
        cout << fileName << '\n';
    }
    else
        cout << "Use default grid\n";

    bool fileSuccess = sudoku.read(fileName);

    if (fileSuccess)
        sudoku.print();
    else
    {
        cout << "Error: file '" << fileName << "' invalid.\n";
        return -1;
    }

    bool solved = sudoku.solve();
    size_t timeOut = 50'000;

    if (solved)
    {
        cout << "\n*** solved ***\n(calls: " << sudoku.nRecursiveCalls << ")\n";
        sudoku.print();
    }
    else if (sudoku.nRecursiveCalls == timeOut)
        cout << "\n*** timed out ***\n";
    else
        cout << "\n*** not solved ***\n";
}
