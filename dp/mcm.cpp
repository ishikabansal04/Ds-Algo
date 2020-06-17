#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vvs vector<vs>
using namespace std;


int mcm_01(int st,int end,vi& row,vi& col,vvi& dp){
    if(st==end) return 0;
    if(dp[st][end]!=0) return dp[st][end];
    int min_=1e8;
    for(int cut=st;cut<end;cut++){
        int left=mcm_01(st,cut,row,col,dp);
        int right=mcm_01(cut+1,end,row,col,dp);
        int cost=left+right+row[st]*col[end]*col[cut];
        min_=min(cost,min_);
    }

    dp[st][end]=min_;
    return min_;
}

int mcm_02(vi& row,vi& col,vvi& dp){
   for(int gap=0;gap<col.size();gap++){
       for(int st=0,end=gap;end<col.size();st++,end++){
        if(gap==0) continue;
        else{
           int min_=1e8;
        for(int cut=st;cut<end;cut++){
        int left=dp[st][cut];
        int right=dp[cut+1][end];
        int cost=left+right+row[st]*col[end]*col[cut];
        min_=min(cost,min_);
        }   
     dp[st][end]=min_;
    }
       }  
   }

   return dp[0][col.size()-1];
}

string mcm_03(vi& row,vi& col,vvi& dp){
   vvs ans(row.size(),vs(col.size(),""));

   for(int gap=0;gap<row.size();gap++){
       for(int st=0,end=gap;end<col.size();st++,end++){
        if(gap==0) {
            ans[st][end]=string(1,(char)('A'+st));
            continue;
        }
        else{
        int min_=1e8;
        for(int cut=st;cut<end;cut++){
        int left=dp[st][cut];
        int right=dp[cut+1][end];
        int cost=left+right+row[st]*col[end]*col[cut];
      //  min_=min(cost,min_);
        if(cost<min_){
            min_=cost;
            ans[st][end]="("+ans[st][cut]+ans[cut+1][end]+")";
        }
        }   
     dp[st][end]=min_;
   
    }
       }
   }
   
   return (ans[0][col.size()-1]+" -> "+ to_string(dp[0][col.size()-1]));
}



int main(){
    vi row={40,20,30,10};
    vi col={20,30,10,30};
    vvi dp(row.size(),vi(col.size(),0));

 //   cout<<mcm_01(0,row.size()-1,row,col,dp);
 //   cout<<mcm_02(row,col,dp);
  cout<<mcm_03(row,col,dp);
}