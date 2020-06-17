/*
tabulation method =====================

#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int LIS(vector<int>& input){
    vector<int> lis(input.size(),0);
    vector<string> plis(input.size(),"");
    lis[0]=1;
    plis[0]+=to_string(input[0])+" ";
    int maxlength=INT_MIN;
    for(int i=1;i<input.size();i++){
        for(int j=0;j<=i-1;j++){
            if(input[j]<input[i]){
                // lis[i]=max(lis[i],lis[j]+1);
                if(lis[j]+1>lis[i]){
                lis[i]=lis[j]+1;
                plis[i]=plis[j]+to_string(input[i])+" ";
                maxlength=max(maxlength,lis[i]);
                }

            }
        }
    }
    for(int i=0;i<input.size();i++){
        if(maxlength==lis[i]){
            cout<<plis[i]<<endl;
        }
    }
    return maxlength;
}
int main(){
    vector<int>input={10,22,9,33,21,50,41,60,80,1};
    cout<<LIS(input);
    return 0;
}
*/

// memorisation and dp=======================

#include<iostream>
#include<string>
#include<vector>

#define vi vector<int>
using namespace std;

// longest increasing sequences================ in O(n^2)

int lis(vi& arr){
    vi dp(arr.size(),0);
    int max_len=1;
    dp[0]=1;

    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                max_len=max(max_len,dp[i]);
            }
        }
    }
    return max_len; 
}

// longest decreasing sequence===================== in O(n^2)

int lds(vi& arr){
    vi dp(arr.size(),0);
    int max_len=1;
    dp[0]=1;

    for(int i=arr.size()-2;i>=0;i--){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                max_len=max(max_len,dp[i]);
            }
        }
    }
    return max_len;
}

// longest increasing sequence=================== in O(nlogn)

int lis_01(vi& arr){
      vector<int> list;  //our final answer list==========
      list.push_back(arr[0]);  //push first element in ans list!
      int len=1;  //...len is nthng else but telling us the no of elements presnet in our current list
                  //...it is incremented only when an element is inserted at last i.i. op 3 and not in any replacement.
      for(int i=1;i<arr.size();i++){   //move across input array and compare.
        
           if(arr[i]>list[len-1]){    
              list.push_back(arr[i]);
              len++;
              
          }
          
          else{   //we are aiming to find element that is to be replaced.
              int left=0;   
              int right=len-1;
              while(left<right){
                  int mid=(left+right)/2;
                  if(list[mid]<arr[i]){
                      left=mid+1;

                  }
                  else{
                      right=mid;
                  }
              }
              list[right]=arr[i];  //we replace whenever we get an element just larger than our value..
                                   //bcoz we need max no of elements with smallest values in our ans subsequence;
          }
        
      }
  return len;
}

int main(){
    vi arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7};
   // cout<<lis(arr);
   // cout<<lds(arr);
   cout<<lis_01(arr);
    return 0;

}