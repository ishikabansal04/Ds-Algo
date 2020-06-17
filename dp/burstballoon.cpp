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

int max_=-1e8;
int burstballoon(vi &arr,int st,int end){
    if(st==end){
        return 1*arr[st]*1;
    }
    
    for(int cut=st;cut<end;cut++){
        int left=burstballoon(arr,st,cut-1);
        int right=burstballoon(arr,cut+1,end);
        int cost=left*right*arr[cut];
        max_=max(cost,max_);
    }
    return max_;
}

int main(){
    vi arr={1,2,4,5,8,9,2,1,6};
    cout<<burstballoon(arr,0,arr.size());
    return 0;
}