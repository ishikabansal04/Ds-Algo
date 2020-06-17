#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void ksorted(int input[],int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        int temp=pq.top();
        input[j]=temp;
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.size()==0){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
int main(){
    int input[]={12,7,5,9,4};
    int k=3;
    ksorted(input,5,k);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}