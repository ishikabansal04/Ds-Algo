#include<iostream>
#include<string>
#include<vector>
#define vi vector<int> 
using namespace std;

string str1="send";
string str2="more";
string str3="money";

int getnumber(string str,vi& noagainstch){
    int ans=0;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        int num=noagainstch[ch-'a'];
        ans=ans*10+num;
    }
    return ans;
}
int cryptoarithmetic_01(string ques,int vidx,vi&noagainstch,int istaken){
    if(vidx==ques.length()){
        int num1=getnumber(str1,noagainstch);
        int num2=getnumber(str2,noagainstch);
        int num3=getnumber(str3,noagainstch);
        if(num1+num2==num3){
            cout<<num1<<"\n"<<num2<<"\n"<<"........."<<num3;
        }
        return 1;
    }
    int count=0;
    for(int i=0;i<10;i++){
        int mask=1<<i;
        if((istaken&mask)==0){
            istaken|=mask;
            noagainstch[ques[vidx]-'a']=i;
            count+=cryptoarithmetic_01(ques,vidx+1,noagainstch,istaken);
             noagainstch[ques[vidx]-'a']=-1;
        }
    }
    return count;
}

vi freqmap(string str){
    vi freq(26,0);
    for(int i=0;i<str.length();i++){
        freq[str[i]-'a']++;
    }
    return freq;
}

void cryptoarithmetic(){
    
    vi freq=freqmap(str1+str2+str3);
    string ques=" ";
    for(int i=0;i<freq.size();i++){
        if(freq[i]>0){
            ques+=(char)(i+'a');
        }
    }
    for(int i=0;i<26;i++){
        cout<<i<<" "<<freq[i]<<" "<<(char)(i+'a')<<endl;
    }
    cout<<ques<<endl;
    cout<<cryptoarithmetic_01(ques,0,noagainstch,0);
}

void setquestion(){
    cryptoarithmetic();

}

int main(){
    setquestion();
    return 0;
}