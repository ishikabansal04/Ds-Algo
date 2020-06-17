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

int LCsubseq_mem(string a,string b,vector<vector<int>>&dp){
    int m=a.length();
    int n=b.length();
       if(a.length()==0 || b.length()==0){
        return 0;
    }
    if(dp[m][n]!=0) return dp[m][n];
    int ans;
    if(a[0]==b[0]){
        ans= 1+LCsubseq_mem(a.substr(1),b.substr(1),dp);
    }
    else{
        int x=LCsubseq_mem(a.substr(1),b,dp); //case when only character of a string is included
        int y=LCsubseq_mem(a,b.substr(1),dp);  //case when only first char of b is included
        int z=LCsubseq_mem(a.substr(1),b.substr(1),dp); // case when both are not included //this is redundant call we can avoid this.
        ans= max(x,max(y,z));
    }
    dp[m][n]=ans;
    return dp[m][n];
}

int LCsubseq_tab(string a,string b,vector<vector<int>>&dp){
    int m=a.length();
    int n=b.length();
        if(a.length()==0 || b.length()==0){
            return 0;
    }
    if(dp[m][n]!=0) return dp[m][n];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(a[0]==b[0]){
        dp[i][j]= 1+dp[i+1][j+1];
    }
    else{
        int x=dp[i+1][j]; //case when only character of a string is included
        int y=dp[i][j+1];  //case when only first char of b is included
        int z=dp[i+1][j+1]; // case when both are not included //this is redundant call we can avoid this.
        dp[i][j]= max(x,max(y,z));
        }
     }
    }
    // dp[m][n]=ans;
    return dp[m][n];
}

int main(){
    cout<<LCsubseq("abc","abd")<<endl;
    string a="mnonlmn";
    string b="nlomnm";
    int m=a.length();
    int n=b.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
   
    cout<<LCsubseq_mem(a,b,dp)<<endl;
    cout<<LCsubseq_tab(a,b,dp);
    return 0;
}