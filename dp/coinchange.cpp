#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vvs vector<vvs>
using namespace std;

//goldmine problem==========================================
int coinchange(vvi &cost){
    vvi dp(cost.size(),(vi (cost.size(),0)));
    for(int i=0;i<cost.size();i++){
        for(int j=0;j<cost[0].size();j++){
            dp[i][j]=max(max(dp[i+1][j+1],dp[i][j+1]),dp[i-1][j+1]);

        }
    }
}


int main(){
    vvi cost={{1,3,3},
                          {2,1,4},
                          {0,6,4}};
    cout<<coinchange(cost);                      
    return 0;
}