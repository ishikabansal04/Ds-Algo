#include<iostream>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

int permutation(vi& arr,int tar){
    vi dp(tar+1,0);
    dp[0]=1;
    for(int i=0;i<=tar;i++){
        for(int j=0;j<arr.size();j++){
            if(i-arr[j]>=0){
                int prev=i-arr[j];
                dp[i]+=dp[prev];
            }
        }
    }
    return dp[tar];
}

//target sum by combination method===============================
//memorisation method======(this involves recursion)

int coincombi(vector<int>& price,int tar,int idx){
    if(tar==0) return 1;
    if(tar<=0) return 0;
    if(idx==price.size() && tar!=0) return 0;
    int maxcoins=0;
    if(tar-price[idx]>=0){
        maxcoins+= coincombi(price,tar-price[idx],idx);
    }
        maxcoins+= coincombi(price,tar,idx+1);
    
    return maxcoins;
}

//tabulation method=======
int combination(vi& arr,int tar){
    vi dp(tar+1,0);
    dp[0]=1;

    for(int j=0;j<arr.size();j++){
     for(int i=0;i<=tar;i++){
            if(i-arr[j]>=0){
                int prev=i-arr[j];
                dp[i]+=dp[prev];
            }
        }
    }
    return dp[tar];
}

int main(){
   vi arr={2,3,5,7};
   //cout<<permutation(arr,10);

   vector<int> price={2,3,5,7};
   cout<<coincombi(price,10,0)<<endl;
   
   cout<<combination(arr,10)<<endl;

  
  
    return 0;

}