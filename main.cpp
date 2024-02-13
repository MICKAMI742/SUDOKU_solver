#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Coordinates
{
    int x;
    int y;
};

Coordinates returnEmptyLocation(vector<vector<string>> &sudokuPlayground)
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
}

vector<vector<string>> findSolution(vector<vector<string>> &sudokuPlayground)
{

    return sudokuPlayground;
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
    inputSudoku(sudokuPlayground);
    // first sudoku card without filling
    cout << "Before" << endl;
    cout << endl;
    printSudoku(sudokuPlayground);
    cout << "-----------------" << endl;
    findSolution(sudokuPlayground);
    // sudoku card with filling
    cout << "After" << endl;
    cout << endl;
    printSudoku(sudokuPlayground);

    return 0;
}
