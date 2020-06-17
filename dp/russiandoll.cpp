#include<iostream>
#include<vector>
#include<list>
#include<queue>   


#define vi vector<int>
#define vvi vector<vi>
using namespace std;

class envelope{
       public:
        int w=0;
        int l=0;

  envelope(){

  }
  envelope(int w,int l){
      this->w=w;
      this->l=l;
  }

  bool operator <(const envelope &o)const{
       // return this->w < o.w; //weak->strong->weak. max heap.
        return this->w > o.w; //strong->weak->strong. min heap
    }
};

// longest increasing sequences====================

int lis(priority_queue<envelope>& env){
     vector<envelope> pair(env.size());
     //cout<<env.size()<<" ";
     for(int i=0;i<4;i++){
        envelope pair[i];
        pair[i]=env.top();
        env.pop();
      //  cout<<pair[i].l<<" ";
      }

    vi dp(pair.size(),0);
    dp[0]=1;

    for(int i=1;i<4;i++){
        envelope now=pair[i];
        int max_len=1;

        for(int j=0;j<i;j++){
            envelope pre=pair[j];

            if(pre.l <= pair[i].l) {
                max_len = max(max_len, dp[j]);
            }
            
        }
        dp[i] = max_len + 1;
    }

    return dp[dp.size()- 1]; 
}
//6, 8, 10, 12

int main(){
     priority_queue<envelope> env;
     env.push(envelope(4,12));
     env.push(envelope(3,10));
     env.push(envelope(2,8));
     env.push(envelope(1,6));

     
     cout<<lis(env);


    return 0;

}