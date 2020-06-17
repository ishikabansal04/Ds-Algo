#include<iostream>
#include<cmath>
using namespace std;

int recursive(int h){
    if(h<=1) return 1;
    int mod=pow(10,9)+7;
    int x=recursive(h-1);
    int y=recursive(h-2);
    int temp1=(int)(long(x)*x)%mod;  //in order to control larger values becoimng negative we take mod by 10^9 +7.
    int temp2=(int)(long(x)*y)%mod;  // this is req to be handled using *long* type buffer as follow.
    int ans=temp1+2*temp2;
    return ans;
}

int balancedBT(int n,int dp[]){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int count=0;
        count+=dp[i-1]*dp[i-1];
        count+=dp[i-2]*dp[i-1];
        count+=dp[i-1]*dp[i-2];
        dp[i]=count;
    }
    return dp[n];
}
int balancedBT(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    return balancedBT(n,dp);
}
int main(){
    cout<<recursive(4)<<endl;
    cout<<balancedBT(4);
    return 0;
}