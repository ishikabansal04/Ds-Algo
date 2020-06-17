#include<iostream>
#include<string>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>
using namespace std;

//to find the maximum order square matrix possible in the given matrix where value is 1=======

int max_square(vvi& mat){
    vvi dp(mat.size(),vi(mat[0].size(),0));
    int r=mat.size()-1;
    int c=mat[0].size()-1;
    dp[r][c]==mat[r][c];
    int max_=0;
    
    for(int i=mat.size()-1;i>=0;i--){
        for(int j=mat[0].size()-1;j>=0;j--){
            
            if(i==mat.size()-1 && j==mat[0].size()-1)
            continue;
            
            if(i+1<mat.size()&&j+1<mat[0].size()&&mat[i][j]!=0)
            dp[i][j]=min(min(dp[i][j+1],dp[i+1][j]),dp[i+1][j+1])+1;
            
            else
            dp[i][j]=mat[i][j];
            
            max_=max(max_,dp[i][j]);
        }
    }
    return max_;
}

int main(){
    vvi mat={{0,1,1,1,1},
             {1,1,1,1,1},
             {1,1,1,0,0},
             {1,1,1,1,1},
             {1,1,1,1,0}};

    cout<<max_square(mat);

    return 0;
}