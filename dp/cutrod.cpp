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

//this method not clear that much......
int max_=-1e8;
int cutting_rod(vi&price, int len){
    vi dp(len+1,0);
    dp[0]=0;

   for(int i=1;i<=len;i++){
      for(int j=i-1;j>=0;j--){
          max_=max(max_,price[j]+dp[i-j-1]);
          dp[i]=max_;
      }
   }

   return dp[len];
}
//tabulation method=======================
//prefer this method given below...... for understanding refer sheet notes...
int CRpieces(vi price, int len){
    vi dp(len+1,0);
    vs ans(len+1,"");
    dp[0]=0;
    ans[0]="";
    dp[1]=price[1];  //in dp array we r storing max profit tha can be earned...
    ans[1]=to_string(1)+" ";   //in ans array we r basically putting indexes or len of broken subparts...
   for(int i=2;i<=len;i++){  //lump sum i.e when rod is sold intact
      
          dp[i]=price[i];  //putting lump sum i.e. when sold intact initially...
          ans[i]=to_string(i)+" ";  
          int left=1;
          int right=i-1;
          while(left<=right){   //to calculate maximised sum when sold out in pieces...
              if(dp[left]+dp[right]>dp[i]){
                  dp[i]=dp[left]+dp[right];
                  ans[i]=ans[left]+ans[right];
              }
              left++;
              right--;
          }
      }
   
    cout<<ans[len]<<endl;
   return dp[len];
}

//memorization method=====================
int CRpieces_mem(vi price, int len, vi&dp){
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len]; 
    int msp=price[len]; //maximum selling price is atleast =rod length price ....
    int left=1;
    int right=len-1;
    while(left<=right){
        int mspl=CRpieces_mem(price,left,dp);
        int mspr=CRpieces_mem(price,right,dp);
        msp=max(msp,(mspl+mspr));
        left++;
        right--;
    }
    dp[len]=msp;
   return dp[len];
}


int main(){
  
    // vi price={1,5,8,9,10,17,17,20};
    // cout<<cutting_rod(price, 8)<<endl;

    // vi price={0,3,5,6,15,10,25,12,24};
    // cout<<CRpieces(price,8);
 
    vi price={0,3,5,6,15,10,25,12,24};
    vi dp(price.size(),-1);
    cout<<CRpieces_mem(price,8,dp);

    return 0;
}