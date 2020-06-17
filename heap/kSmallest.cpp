#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void kSmallest(int input[],int n,int k,int ans[]){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top()>input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }
    for(int i=0;i<k;i++){
        ans[i]=pq.top();
        pq.pop();
    }
}
int main(){
    int input[]={12,7,5,9,4,6};
    int k=3;
    int ans[k];
    kSmallest(input,6,k,ans);
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}