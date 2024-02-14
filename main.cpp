#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Coordinates
{
    int x;
    int y;
};

Coordinates ReturnEmptyLocation(vector<vector<string>> &sudokuPlayground)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudokuPlayground[i][j] == "-")
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool IsMoveValid(vector<vector<string>> &sudokuPlayground, int row, int col, string number)
{
    // check row and column
    for (int i = 0; i < 9; i++)
    {
        if (sudokuPlayground[row][i] == number || sudokuPlayground[i][col] == number)
        {
            return false;
        }
    }
    // check square
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudokuPlayground[startRow + i][startCol + j] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool FindSolution(vector<vector<string>> &sudokuPlayground)
{
    int row = ReturnEmptyLocation(sudokuPlayground).x;
    int col = ReturnEmptyLocation(sudokuPlayground).y;
    if (row == -1)
    {
        return true;
    }
    for (int num = 1; num < 10; num++)
    {
        if (IsMoveValid(sudokuPlayground, row, col, to_string(num)))
        {
            sudokuPlayground[row][col] = to_string(num);
            if (FindSolution(sudokuPlayground))
            {
                return true;
            }
            sudokuPlayground[row][col] = "-";
        }
    }
    return false;
}

void inputSudoku(vector<vector<string>> &sudokuPlayground)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 8);
    int number = 1;
    int x = dis(gen);
    int y = dis(gen);
    for (int i = 0; i < 9; i++)
    {
        x = dis(gen);
        y = dis(gen);
        sudokuPlayground[x][y] = to_string(number);
        number++;
    }
}

void printSudoku(vector<vector<string>> sudokuPlayground)
{
    for (auto x : sudokuPlayground)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<string>> sudokuPlayground(9, vector<string>(9, "-"));
    // vector<Coordinates> emptyLocations;
    inputSudoku(sudokuPlayground);
    // first sudoku card without filling
    cout << "Before" << endl;
    cout << endl;
    printSudoku(sudokuPlayground);
    cout << "-----------------" << endl;
    // sudoku card with filling
    cout << "After" << endl;
    cout << endl;
    if (FindSolution(sudokuPlayground))
    {
        printSudoku(sudokuPlayground);
    }
    else
    {
        cout << "No solution exists" << endl;
    }
    return 0;
}
