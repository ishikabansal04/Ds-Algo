#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> mymap;
    mymap["abc1"]=1;
    mymap["abc2"]=2;
    mymap["abc3"]=3;
    mymap["abc4"]=4;
    mymap["abc5"]=5;
    mymap["abc6"]=6;

    unordered_map<string,int> ::iterator it=mymap.begin();
    while(it!=mymap.end()){             //since unordered map therefore gives value in no particular order===
        cout<<"Key:"<<it->first<<" , Value:"<<it->second<<endl;
        it++;
    }
    
    unordered_map<string,int> ::iterator it1=mymap.find("abc1");
    mymap.erase(it1);
    mymap.erase(it1,it1+4);
    
    vector<int>v;      //this is ordered therefore gives value in particular order
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it2=v.begin();
    while(it2!=v.end()){
        cout<<*it2<<endl;
        it2++;
    }
    return 0;
}