#include<iostream>
#include<vector>
using namespace std;

//approach to save some space in dp======based on sliding window technique
int fibs(int n){
    vector<int>slider(2,0);
    slider[0]=0; //i.e slider  0 contains fib(0) initially
    slider[1]=1; //i.e slider  1 contains fib(1) initially
    int nf;
    
    for(int i=1;i<=n;i++){
        nf=slider[0]+slider[1];
        slider[0]=slider[1];
        slider[1]=nf;
    }
    return slider[0];
}
//board path slider
int nbps(int tar){
    vector<int>slider(6,0);
    slider[0]=1; //i.e slider  0 contains ways of path from target to target initially
 
    for(int i=1;i<=tar;i++){
        int nf=slider[0]+slider[1]+slider[2]+slider[3]+slider[4]+slider[5];
        for(int i=5;i>0;i--){
            slider[i]=slider[i-1];
        }
        slider[0]=nf;
    }
    return slider[0];
}

//mazepath slider
int bps(int er,int ec){
    vector<int> slider(ec+1,1);
    for(int i=1;i<=er;i++){
        for(int j=ec-1;j>=0;j--){
            slider[j]=slider[j]+slider[j+1];
        }
    }
    return slider[0];
}
int main(){
    // cout<<fibs(5);
    // cout<<nbps(10);
    cout<<bps(3,3);
    return 0;
}