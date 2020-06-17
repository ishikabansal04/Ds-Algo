#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsequence(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return ;
    }
 
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string one=str.substr(0,i);
        string two=str.substr(i+1);
        subsequence(one+two,ans+ch);
    }
}


int main(){
    subsequence("abc","");
    return 0;
}
