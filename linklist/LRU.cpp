#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRU{
    list<int> ll;
    unordered_map<int, int> map;
    int defaultsize=4;

    void set(int key, char val){
        if(defaultsize==0){
           int pkey=list.removeLast();
        
        }
    }
    void get(int key){

    }
}