//A very optimized solution to implement queue using 2 stacks (hackerrank problem)
//see explainataion at https://codereview.stackexchange.com/questions/225469/hackerrank-implement-queue-using-two-stacks-solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<int>stk1;
stack<int>stk2;

 //trick lies in this function above link for explaination!
void flip(){
    while(stk1.size()!=0){
        stk2.push(stk1.top());
        stk1.pop();
    }
}
void enqueue(int data){
    stk1.push(data);
}

void dequeue(){
    if(stk2.size()==0){
        flip();
    }
    stk2.pop();
}
int print(){
    if(stk2.size()==0){
        flip();
    }
    return stk2.top();
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--){
        int q;
        cin>>q;
        if(q==1){
            int val;
            cin>>val;
            enqueue(val);
        }
        else if(q==2){
            dequeue();
        }
        else{
            cout<<print()<<endl;
        }
    }
    return 0;
}
