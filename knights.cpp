#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int SIZE = 5;
array<array<int, SIZE>, SIZE> chess_board; //Use a 2D array to represent the board
const array<int, 8> ROW = {2, 1, -1, -2, -2, -1, 1, 2};
const array<int, 8> COL = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid_move(int row, int col){
    return (row >= 0) && (row < SIZE) && (col >= 0)  && (col < SIZE) && (chess_board[row][col] == 0);
}

bool search(int row, int col, int temp){
    chess_board[row][col] = temp;
    if (temp == SIZE * SIZE){
        return true;
    }

    for (int i = 0; i < 8; i++){
        int new_row = row + ROW[i]; //Create an int to track the new row
        int new_col = col + COL[i]; //Create an int to track the new column
        if (valid_move(new_row, new_col)){ //If the position is a valid position
            if (search(new_row, new_col, temp + 1)){//Recursive call to search the board again
                return true;
            }
        }
    }
    chess_board[row][col] = 0; //Reset
    return false;
}

int main(){
    //The starting position on the chess board is (2,2)
    int row_pos = 2;
    int col_pos = 2;
    bool solution = search(row_pos, col_pos, 1);

    if (solution){  //If the solution was found 
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                cout << setw(2) << chess_board[i][j] << ":"; //Print the new board consisting of the solution
            }
            cout << endl;
        }
    } 
    else{
        cout << "There is no solution." << endl;
    }
    return 0;
}