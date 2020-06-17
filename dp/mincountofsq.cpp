//in this we r given an n and we need to find min count of numbers req whose sum of squares is equal to n;
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int minsquares(int n,int dp[]){
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++){
        dp[i]=i;
        for(int x=1;x<=ceil(sqrt(i));x++){
            int temp=x*x;
            if(temp>i) break;
            else 
            dp[i]=min(dp[i],dp[i-temp]+1);
        }  
    }
    return dp[n];
}
int minsquares(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    return minsquares(n,dp);
}
int main(){
    cout<<minsquares(4);
    return 0;
}