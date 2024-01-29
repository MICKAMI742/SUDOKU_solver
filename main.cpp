#include <iostream>
#include <vector>
#include <random>
using namespace std;

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

void printSolution(int x, int y, int number, vector<vector<string>> sudokuPlayground)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudokuPlayground[i][j] == to_string(number))
            {
                x = j;
                y = i;
            }
        }
    }
    cout << "x: " << x << " y: " << y << " number: " << number << endl;
}

int main()
{
    vector<vector<string>> sudokuPlayground(9, vector<string>(9, "-"));
    inputSudoku(sudokuPlayground);
    printSudoku(sudokuPlayground);
    printSolution(1, 2, 3, sudokuPlayground);

    return 0;
}
