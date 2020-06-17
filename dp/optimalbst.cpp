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

//this method will cause dp to be 3d================
int obst(vi &arr,vi& freq,int st,int end,int lvl){

    if(st==end){
        return lvl*freq[st];
    }
    //if(dp[st][end]!=0) return dp[st][end];

    int min_=1e8;
    for(int i=st;i<=end;i++){
        
        int left=obst(arr,freq,st,i-1,lvl+1);
        int right=obst(arr,freq,i+1,end,lvl+1);
        min_=min(left,right);
        min_+=lvl*freq[i];
    }
  //  dp[st][end]=min_;
    return min_;
}

// this is to make dp 2d==================
int OBST(vi &keys, vi &freq)
{
    vvi dp(keys.size(), vi(keys.size(), 0));
    vi sum(keys.size(), 0);
    sum[0] = freq[0];

    for (int i = 1; i < keys.size(); i++)
        sum[i] += sum[i - 1] + freq[i];

    for (int gap = 0; gap < keys.size(); gap++)
    {
        for (int st = 0, end = gap; end < keys.size(); end++, st++)
        {
            if (gap == 0)
            {
                dp[st][end] = freq[st];
                continue;
            }

            int min_ = 1e8;
            for (int cut = st; cut <= end; cut++)
            {
                int left = cut == st ? 0 : dp[st][cut - 1];
                int right = cut == end ? 0 : dp[cut + 1][end];

                int cost = left + sum[end] - ((st - 1) < 0 ? 0 : sum[st - 1]) + right;
                min_ = min(cost, min_);
            }
            dp[st][end] = min_;
        }
    }

    return dp[0][keys.size() - 1];
}


int main(){
    vi arr={10,12};
    vi freq={34,50};
    //vvi dp(arr.size(),vi(arr.size(),0));
   // cout<<obst(arr,freq,0,arr.size()-1,1);
   cout<<OBST(arr,freq);
}