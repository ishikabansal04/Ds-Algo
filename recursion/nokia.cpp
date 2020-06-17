#include<iostream>
#include<string>
#include<vector>
using namespace std;

string codes[]={"+","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz","*","#"};
int nokia(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<" ";
        return 1;
    }

    char ch=ques[0];
    string roq=ques.substr(1);
    string code=codes[ch-'0'];
    int count=0;
    for(int i=0;i<code.length();i++){
        count+=nokia(roq,ans+code[i]);

    }
    return count;
}

int main(){
    cout<<nokia("212","");
    return 0;
}