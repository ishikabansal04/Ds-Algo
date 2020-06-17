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

int knapsack(vi &wt,vi &cost,int maxwt){
    vvi dp(wt.size()+1,vi(maxwt+1,0));
    for(int i=1;i<=wt.size();i++){
        for(int j=1;j<=maxwt;j++){
            int res=j-wt[i];
            if(res>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][res]+cost[i]); //jab vo element aayega humare ans m
            else{
                dp[i][j]=dp[i-1][j]; //jab vo element nhi aayega humare ans m
                }}
    }
return dp[wt.size()][maxwt];
}

//k2. target sum====================================

bool target_sum(vi & arr,int tar){
    vvb dp(arr.size(),vb(tar+1,false));
    dp[0][0]=true;
   //arr.insert(arr.begin(),0);

    for(int i=1;i<arr.size();i++){
        for(int j=0;j<tar+1;j++){
            if(j==0)
             dp[i][j]=true;
           else{
            int idx=j-arr[i];
            if(idx>=0)
             dp[i][j]=dp[i-1][j]||dp[i-1][idx];
             else 
             dp[i][j]=dp[i-1][j];
           }
        }
    }
    return dp[arr.size()-1][tar];
}


int main(){
    // vi wt={1,3,4,5};
    // vi cost={10,40,50,70};
      vi wt={1,2,4,5};
    vi cost={10,40,60,70};
    cout<<knapsack(wt,cost,8);

  /* vi arr={2,3,5,7};
    cout<<boolalpha<<target_sum(arr,6);*/
    return 0;
}