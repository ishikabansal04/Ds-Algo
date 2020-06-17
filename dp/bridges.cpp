#include<iostream>
#include<vector>
#include<list>
#include<queue>   

#define vi vector<int>
#define vvi vector<vi>
using namespace std;

class bridge{
    public:
    int s=0;
    int e=0;
    bridge(){
    }

    bridge(int s,int e){
        this->s=s;
        this->e=e;
    }
    
    bool operator <(const bridge &o)const{
        return this->s > o.s;
    }
};

int lis(priority_queue<bridge> &que){
    vector<bridge> pair(que.size());
    
    for(int i=0;i<que.size();i++){
        bridge pair[i];
        pair[i]=que.top();
        que.pop();
    }

     vi dp(pair.size(),0);
    dp[0]=1;

    for(int i=1;i<4;i++){
        bridge now=pair[i];
        int max_len=1;

        for(int j=0;j<i;j++){
            bridge pre=pair[j];

            if(pre.e < now.e) {
                max_len = max(max_len, dp[j]);
            }
    
        }
        dp[i] = max_len + 1;
    }
     
    return dp[dp.size()- 1]; 
}

int main(){
    priority_queue<bridge> que;
    que.push(bridge(8,1));
    que.push(bridge(1,2));
    que.push(bridge(4,3));
    que.push(bridge(3,4));
    que.push(bridge(5,5));
    que.push(bridge(2,6));
    que.push(bridge(6,7));
    que.push(bridge(7,8));
 
    cout<<lis(que);
    return 0;
}