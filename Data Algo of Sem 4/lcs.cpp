#include<iostream>
// #include<vector>
using namespace std;

void lcs(string s,string t){
    int n = s.size();
    int m = t.size();

    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int dp[n+1][m+1] = {0};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //string are matching
            if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
            //stirng are not matching
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout<<"Maximun matching length is "<<dp[n][m]<<endl;

    // Print the subsequence
    int len = dp[n][m];
    string ans = "";

    for(int i = 0;i<len;i++){
        ans += '$';
    }

    int index = len - 1;    //String are in 0 base indexing 
    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
            ans[index] = s[i-1];
            index--,i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])  i--;
        else j--;
    }

    cout<<"The Longest Common Subsequence is : "<<ans<<endl;

    //Check the DP table
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

int main(){
    // string s1 = "abcde";
    // string s2 = "bdge";
    
    string s1,s2;
    cout<<"Give the 1st string : ";
    cin>>s1;
    cout<<"Give the 2nd string : ";
    cin>>s2;

    lcs(s1,s2);

    return 0;
}