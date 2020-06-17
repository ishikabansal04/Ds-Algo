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

int encoding(vi& arr){
    vi dp(arr.size(),0);
    dp[arr.size()-1]=1;
    int two;
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i+1]!=-1)
            two=(10*arr[i])+arr[i+1];
        else two=0;

        if(arr[i]==0) {
            dp[i]=dp[i+1];
            continue;
        }
        else if(two>=10 && two<=26){
            dp[i]=dp[i+1]+dp[i+2];
        }
        else{ 
            dp[i]= dp[i+1];
        }
    }
    return dp[0];
}

int main(){
    vi arr={1,1,0,0,0,4,3,-1};
    cout<<encoding(arr);
    return 0;
}