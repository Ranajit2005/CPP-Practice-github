#include <iostream>
using namespace std;
const int N = 100;
char board[N][N];

void printBoard(char board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int col,char board[N][N], int n,int leftRow[],int upperDiagonal[],int lowerDiagonal[]){

    //Base case
    if(col == n) {
        // Print the solution
        printBoard(board, n);
        return;
    }

    //Checking Condition
    for(int row=0;row<n;row++){

        //Cheak the queen is placed or not
        if(leftRow[row] == 0 && upperDiagonal[(n-1) + (col-row)] == 0 && lowerDiagonal[row + col] == 0){

            //if all those condition sitisfy then placed the queen and marked tha placed as 1
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[(n-1)+(col-row)] = 1;
            lowerDiagonal[row+col] = 1;

            //till now we check the queen is placed 1st col, now we check for other col
            solve(col+1,board,n,leftRow,upperDiagonal,lowerDiagonal);

            //now we check for other ans
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[(n-1)+(col-row)] = 0;
        } 
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Allocate memory for the chessboard
    // char **board = new char *[n];
    for (int i = 0; i < n; i++) {
        // board[i] = new char[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    int leftRow[n], upperDiagonal[2*n - 1],lowerDiagonal[2*n - 1];
    for(int i=0;i<n;i++){
        leftRow[i] = 0;
    }
    for(int i=0;i<2*n-1;i++){
        upperDiagonal[i] = 0;
        lowerDiagonal[i] = 0;
    }

    solve(0,board,n,leftRow,upperDiagonal,lowerDiagonal);

    return 0;
}