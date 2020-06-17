#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void hashing(){
    unordered_map<string,int> mymap;
    pair<string,int>p("abc",1);
    //insert element============
   
    mymap.insert(p);
    mymap["def"]=2;

    //search/find element=======

    cout<<mymap["def"]<<endl;
    cout<<mymap.at("def")<<endl;
    
    //cout<<mymap.at("ghi")<<endl; // gives  exceptiom
    cout<<mymap["ghi"]<<endl; //creates default key
    //check if present==========

    if(mymap.count("ghi")>0){
        cout<<mymap.at("ghi")<<endl;
        cout<<mymap["ghi"]<<endl;
    }    
    //size======================

    cout<<mymap.size()<<endl;
    //erase=====================

    mymap.erase("ghi");


}

int main(){
    hashing();
    return 0;
}