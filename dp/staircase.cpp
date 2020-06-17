// child can run up on a staircase with 1step,2steps,3steps at a time ...tell total no of ways to climb up a staircase of n stairs.
#include<iostream>
using namespace std;
int staircount(int n,int dp[]){
    dp[0]=0;
    dp[1]=1;
    dp[2]=1+dp[1];
    dp[3]=1+dp[2];
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+1;
    }
    return dp[n];
}
int staircount(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    return staircount(n,dp);
}
int main(){
    cout<<staircount(4);
    return 0;
}