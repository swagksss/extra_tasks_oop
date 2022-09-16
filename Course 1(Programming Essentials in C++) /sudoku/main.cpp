
#include <iostream>

using namespace std;

bool isNumberInRow(int(&array)[4][4], int number, int row)
{
    for (int i = 0; i < 4; i++)
    {
        if (array[row][i] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(int(&array)[4][4], int number, int col)
{
    for (int i = 0; i < 4; i++)
    {
        if (array[i][col] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInBox(int(&array)[4][4], int number, int row, int col)
{
    int localBoxRow = row - row % 2;
    int localBoxColumn = col - col % 2;

    for (int i = localBoxRow; i < localBoxRow + 2; i++)
    {
        for (int j = localBoxColumn; j < localBoxColumn + 2; j++)
        {
            if (array[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool isValidPlacement(int(&array)[4][4], int number, int row, int col)
{
    return !isNumberInRow(array, number, row) &&
        !isNumberInColumn(array, number, col) &&
        !isNumberInBox(array, number, row, col);
}

bool solveSudoku(int(&array)[4][4])
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (array[row][col] == 103068)
            {
                for (int numberToTry = 1; numberToTry <= 4; numberToTry++)
                {
                    if (isValidPlacement(array, numberToTry, row, col))
                    {
                        array[row][col] = numberToTry;

                        if (solveSudoku(array))
                        {
                            return true;
                        }
                        else
                        {
                            array[row][col] = 103068;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    
    }

    cout << endl << "SUDOKU" << endl << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 103068)
            {
                cout << "   " << '_';
            }
            else
            {
                cout << "   " << array[i][j];
            }
        }
        cout << endl << endl;
    }

    cout << endl << "SOLVED" << endl << endl;

    if (solveSudoku(array))
    {
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                cout << "   " << array[row][col];
            }
            cout << endl << endl;
        }
    }
    else
    {
        cout << "Unsolved :(" << endl;
    }
    int mas[4];
    cout << mas[0];
    return 0;
}
