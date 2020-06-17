#include<iostream>
using namespace std;

//memorization
int fibonnaci(int n,int dp[]){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    
        int a=fibonnaci(n-1,dp);
        int b=fibonnaci(n-2,dp);
    dp[n]=a+b;
    return dp[n];
}
int fibonnaci(int n){
    int dp[n+1];
    for(int i=1;i<n+1;i++){
        dp[i]=-1;
    }
    return fibonnaci(n,dp);
}
//tabulation
int fib_tab(int n,int dp[]){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fib_tab(int n){
     int dp[n+1];
    for(int i=1;i<n+1;i++){
        dp[i]=-1;
    }
    return fib_tab(n,dp);
}
int main(){
    cout<<fibonnaci(7)<<endl;
    cout<<fib_tab(7)<<endl;
    return 0;
}