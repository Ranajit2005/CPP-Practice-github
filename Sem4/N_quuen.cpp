#include<iostream>
using namespace std;

const int N = 100;
char board[N][N];

void printBoard(char board[N][N],int n){
    static int solution = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    solution++;
    cout<<"Numver of the solution : "<<solution<<endl;
    cout<<endl;
}

void solve(int col,char board[N][N],int n,int uppderDiagonal[],int lowerDiagonal[],int leftRow[]){
    if(col == n){
        printBoard(board,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row] == 0 && uppderDiagonal[(n-1)+(col-row)] == 0 && lowerDiagonal[col+row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            uppderDiagonal[(n-1)+(col-row)] = 1;
            lowerDiagonal[col+row] = 1;
            solve(col+1,board,n,uppderDiagonal,lowerDiagonal,leftRow);

            board[row][col] = '.';
            leftRow[row] = 0;
            uppderDiagonal[(n-1)+(col-row)] = 0;
            lowerDiagonal[col+row] = 0;
        }
    }
}

int main(){
    int n;
    cout<<"Give the number of the queen : ";
    cin>>n;

    int leftrow[n],upperDiagona[2*n-1],lowerDiagonal[2*n-1];
    for(int i=0;i<n;i++){
        leftrow[i]=0;
    }
    for(int i=0;i<2*n-1;i++){
        upperDiagona[i]=0;
        lowerDiagonal[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = '.';
        }
    }

    int sol = 0;
    solve(0,board,n,upperDiagona,lowerDiagonal,leftrow);

    return 0;
}