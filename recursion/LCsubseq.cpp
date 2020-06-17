#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LCsubseq(string a,string b){
    if(a.length()==0 || b.length()==0){
        return 0;
    }
    if(a[0]==b[0]){
        return 1+LCsubseq(a.substr(1),b.substr(1));
    }
    else{
        int x=LCsubseq(a.substr(1),b); //case when only character of a string is included
        int y=LCsubseq(a,b.substr(1));  //case when only first char of b is included
        int z=LCsubseq(a.substr(1),b.substr(1)); // case when both are not included //this is redundant call we can avoid this.
        return max(x,max(y,z));
    }
}

int main(){
    cout<<LCsubseq("abcxyzd","cabd");
    return 0;
}