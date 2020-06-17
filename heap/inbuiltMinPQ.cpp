
//method one using greater function================
/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
priority_queue<int,vector<int>,greater<int>> pq;

pq.push(16);
pq.push(1);
pq.push(167);
pq.push(7);
pq.push(45);
pq.push(32);

cout<<"Size : "<<pq.size()<<endl;
cout<<"Top : "<<pq.top()<<endl;

while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
}
return 0;
}
*/

//method two using operator overloading and making our own comparator class and an operator function =======
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Comp{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};
int main(){
priority_queue<int,vector<int>,Comp > pq;

pq.push(16);
pq.push(1);
pq.push(167);
pq.push(7);
pq.push(45);
pq.push(32);

cout<<"Size : "<<pq.size()<<endl;
cout<<"Top : "<<pq.top()<<endl;

while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
}
return 0;
}