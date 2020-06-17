// in this problem we are given a number n(say 7) we have to reach to 1 through minimum steps....
//operations allowed are:
//1.) decrement by 1....... n-1
//2.) divide by 2 only if n%2==0
//3.) divide by 3 only if n%3==0
//count min no of steps req...
#include<iostream>
using namespace std;
int minsteps(int n,int dp[]){
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2==0 && i%3==0)
        dp[i]+=min(min(dp[i-1],dp[i/2]),dp[i/3])+1;
        else if(i%2==0)
        dp[i]+=min(dp[i-1],dp[i/2])+1;
        else if(i%3==0)
        dp[i]+=min(dp[i-1],dp[i/3])+1;
        else 
        dp[i]+=dp[i-1]+1;
    }
    return dp[n];
}
int minsteps(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    return minsteps(n,dp);
}
int main(){
    cout<<minsteps(7);
    return 0;
}