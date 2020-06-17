#include<iostream>
#include<string>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int max_cost(vvi& arr){
    vvi dp(arr.size(),vi(arr[0].size(),0));
    int max_=0;
     for(int i=arr[0].size()-1;i>=0;i--){
         for(int j=arr.size()-1;j>=0;j--){
             if(i+1<arr[0].size()&&j-1<arr.size()){
                 dp[j][i]=max(dp[j][i],dp[j-1][i+1]);
             }
             if(i+1<arr[0].size()){
                 dp[j][i]=max(dp[j][i],dp[j][i+1]);
             }
             if(i+1<arr[0].size()&&j+1<arr.size()){
                 dp[j][i]=max(dp[j][i],dp[j+1][i+1]);
             }
             dp[j][i]+=arr[j][i];
         }
     }

     for(int i=0;i<arr.size();i++){
         max_=max(max_,dp[i][0]);
     }
     return max_;
}

int main(){
    vvi arr={{1,3,3},
            {2,1,4},
            {0,6,4}};
    cout<<max_cost(arr);
    return 0;
}