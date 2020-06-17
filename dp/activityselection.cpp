#include<iostream>
#include<queue>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>
using namespace std;

class activity{
       public:
        int s=0;
        int e=0;

  activity(){

  }
  activity(int s,int e){
      this->s=s;
      this->e=e;
  }

  bool operator <(const activity &o)const{
       // return this->s < o.s; //weak->strong->weak. max heap.
        return this->s > o.s; //strong->weak->strong. min heap
    }
};

// longest increasing sequences====================

int lis(priority_queue<activity>& act){
     vector<activity> pair(act.size());
     for(int i=0;i<pair.size();i++){
        pair[i]=act.top();
        act.pop();
        }

    vi dp(pair.size(),0);
    dp[0]=1;

    for(int i=1;i<pair.size();i++){
        activity now=pair[i];
        int max_len=1;

        for(int j=0;j<i;j++){
            activity pre=pair[j];

            if(pre.e < now.s) {
                max_len = max(max_len, dp[j]);
            }
            
        }
        dp[i] = max_len + 1;
    }

    return dp[dp.size()- 1]; 
}

int main(){
    vi start={1,3,5,6};
    vi endact={2,4,7,8};
     priority_queue<activity> act;
     for(int i=0;i<start.size();i++){
         int st=start[i];
         int en=endact[i];
        act.push(activity(st,en));  
     }   
     cout<<lis(act);


    return 0;

}