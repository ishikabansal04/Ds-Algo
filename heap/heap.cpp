#include<iostream>
#include<vector>
using namespace std;

//minimum priority queue=====================
class PriorityQueue{
    vector<int>pq;
    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getsize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()) return 0;
        return pq[0];
    }
    void insert(int data){
        pq.push_back(data);
        upheapify();
    }

    int removeMin(){
        int ans=pq[0];
        int temp=pq[0];
        pq[0]=pq[pq.size()-1];
        pq[pq.size()-1]=temp;
        pq.pop_back();
        downheapify();
        return ans;
    }
    void upheapify(){
        int childindex=pq.size()-1;    

        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(pq[parentindex]>pq[childindex]){
                int temp=pq[childindex];
                pq[childindex]=pq[parentindex];
                pq[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
           
        }
    }
    void downheapify(){
        int parentindex=0;
        int childindex1=(2*parentindex+1);
        int childindex2=(2*parentindex+2);

        while(childindex1< pq.size()){
         int minindex=parentindex;
         if(pq[parentindex]>pq[childindex1]){
             minindex=childindex1;
         }
         if(childindex2<pq.size() && pq[childindex2]<pq[minindex]){
             minindex=childindex2;
         }
         if(minindex==parentindex){
             break;
         }
        int temp=pq[minindex];
        pq[minindex]=pq[parentindex];
        pq[parentindex]=temp;
        parentindex=minindex;
        childindex1=(2*parentindex+1);
        childindex2=(2*parentindex+2);
        }      
    }
};

int main(){
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    cout<<p.getsize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
    return 0;
}