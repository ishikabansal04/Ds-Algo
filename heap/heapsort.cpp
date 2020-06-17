#include<iostream>
#include<vector>
using namespace std;
void inplaceHeapSort(int pq[],int n){
    //Build the heap====

for(int i=1;i<n;i++){
     int childindex=i; //upheapify(insert) function as it is copy pasted!    

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

//Remove elements but actually not removed=======
int size=n;

while(size>1){
int temp=pq[0];
pq[0]=pq[size-1];
pq[size-1]=temp;

size--;
 
 int parentindex=0;         //downheapify(delete) function as it is copy pasted!
        int childindex1=(2*parentindex+1);
        int childindex2=(2*parentindex+2);

        while(childindex1< size){  //now we have size in place of pq.size() coz of our assumption of reduced size of array.
         int minindex=parentindex;
         if(pq[parentindex]>pq[childindex1]){
             minindex=childindex1;
         }
         if(childindex2<size && pq[childindex2]<pq[minindex]){
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
}

int main(){
 int input[]={5,1,2,0,8};
 inplaceHeapSort(input,5);
 for(int i=0;i<5;i++){
     cout<<input[i]<<" ";
 }
 cout<<endl;
}