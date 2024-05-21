#include<iostream>
#include<vector>
using namespace std;

void solve(int col,vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &upperDiagonal, vector<int> &lowerDiagonal,int n){

    //Base case
    if(col == n){
        ans.push_back(board);
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
            solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            
            //now we check for other ans
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[(n-1)+(col-row)] = 0;
        } 
    }
}

int main(){

    int n;
    cout<<"Give the queen number : ";
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }

    vector<int>leftRow(n,0), upperDiagonal(2*n - 1,0),lowerDiagonal(2*n - 1,0);

    solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}