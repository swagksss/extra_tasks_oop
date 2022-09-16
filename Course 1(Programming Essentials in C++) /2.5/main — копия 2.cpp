#include <iostream>
#include <algorithm>
using namespace std;
int grid[4][4];
int combinations[24][4];
int iter = 0;
int numbers[] = {1, 2, 3, 4};
int user_numbers[4][3] = {{0,0,1},{1,1,2},{1,3,3},{3,3,4}};

int print(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != 0) cout << "|" << grid[i][j] << "|";
            else cout << "|" << "_" << "|";
        }
        cout << endl;
    }
    cout << "============" << endl;
    return 0;
}
int input(){
    for (int i = 0; i < 4; ++i) {
        int num;
        int row;
        int col;
        cout << "Number:";
        cin >> num;
        cout << "Row:";
        cin >> row;
        cout << "Column:";
        cin >> col;
        cout << "=======" << endl;
        user_numbers[i][0] = row-1;
        user_numbers[i][1] = col-1;
        user_numbers[i][2] = num;
        grid[row-1][col-1] = num;
    }
    return 0;
}
int place_numbers(int r, int c, const int nums[]){
    grid[r][c] = nums[0];
    grid[r][c+1] = nums[1];
    grid[r+1][c] = nums[2];
    grid[r+1][c+1] = nums[3];
    return 0;
}
bool reserved_numbers_check(int row, int col){
    for (int i = 0; i < 4; ++i) {
        if(row == user_numbers[i][0] && col == user_numbers[i][1] && user_numbers[i][2] != grid[row][col]) return false;
        if(row == user_numbers[i][0] && col+1 == user_numbers[i][1] && user_numbers[i][2] != grid[row][col+1]) return false;
        if(row+1 == user_numbers[i][0] && col == user_numbers[i][1] && user_numbers[i][2] != grid[row+1][col]) return false;
        if(row+1 == user_numbers[i][0] && col+1 == user_numbers[i][1] && user_numbers[i][2] != grid[row+1][col+1]) return false;
    }
    return true;
}
bool horizontal_numbers_check(int row){
    if (grid[row][0] == grid[row][2] || grid[row][0] == grid[row][3] || grid[row][1] == grid[row][2] || grid[row][1] == grid[row][3]) return false;
    return true;
}

bool vertical_numbers_check(int column){
    if (grid[0][column] == grid[2][column] || grid[0][column] == grid[3][column] || grid[1][column] == grid[2][column] || grid[1][column] == grid[3][column]) return false;
    return true;
}

int main(){
    input();
    cout << "Pattern: " << endl;
    print();
    cout << "Solutions: " << endl;
    do {
        for (int i = 0; i < 4; ++i) {
            combinations[iter][i] = numbers[i];
        }
        iter++;
    } while ( next_permutation(numbers,numbers+4) );
    for (int i = 0; i < 24; ++i) {
        place_numbers(0,0,combinations[i]);
        if(!reserved_numbers_check(0,0)) continue;
        for (int j = 0; j < 24; ++j) {
            place_numbers(0,2,combinations[j]);
            if(!reserved_numbers_check(0,2) || !horizontal_numbers_check(0) || !horizontal_numbers_check(1)) continue;
            for (int k = 0; k < 24; ++k) {
                place_numbers(2,0,combinations[k]);
                if(!reserved_numbers_check(2,0) || !vertical_numbers_check(0) || !vertical_numbers_check(1)) continue;
                for (int l = 0; l < 24; ++l) {
                    place_numbers(2,2,combinations[l]);
                    if(!reserved_numbers_check(2,2) || !vertical_numbers_check(2) || !vertical_numbers_check(3) || !horizontal_numbers_check(2) || !horizontal_numbers_check(3)) continue;
                    else{
                        print();
                    }
                }
            }
        }
    }
    return 0;
}
