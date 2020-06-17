//in this we require min no of operations req to make two strings equal=======

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//recursion/bruteforce
int editDistRec(string a,string b){
    if(a.length()==0 || b.length()==0) return 0;
    int count=0;
        if(a[0]==b[0]) return editDistRec(a.substr(1),b.substr(1));
        else{
        int x=editDistRec(a.substr(1),b)+1;//insert
        int y=editDistRec(a,b.substr(1))+1;//delete
        int z=editDistRec(a.substr(1),b.substr(1))+1;
        count+=min(x,min(y,z));
        }
        return count;
}

//memorization
int editDist_mem(string a,string b,vector<vector<int>>& dp){
    if(a.length()==0 || b.length()==0) return 0;
    int count=0;
        if(dp[a.length()][b.length()]!=-1) return dp[a.length()][b.length()];
        if(a[0]==b[0]) return editDist_mem(a.substr(1),b.substr(1),dp);
        else{
        int x=editDist_mem(a.substr(1),b,dp)+1;//insert
        int y=editDist_mem(a,b.substr(1),dp)+1;//delete
        int z=editDist_mem(a.substr(1),b.substr(1),dp)+1;
        count+=min(x,min(y,z));
        }
        dp[a.length()][b.length()]=count;
        return dp[a.length()][b.length()];
}
int editDist_mem(string a,string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,-1));
   
    return editDist_mem(a,b,dp);
}
//tabulation
int editDist_tab(string a,string b,vector<vector<int>>& dp){
    if(a.length()==0 || b.length()==0) return 0;
    
    //fill first row
    for(int i=0;i<=a.length();i++){
        dp[i][0]=i;
    }
    //fill first column
    for(int j=0;j<=b.length();j++){
        dp[0][j]=j;
    }
    //filling other rows and cols
        for(int i=1;i<=a.length();i++){
            for(int j=1;j<=b.length();j++){
                if(a[a.length()-i]==b[b.length()-j]) return dp[i-1][j-1];
                else{
                int x=dp[i-1][j]+1;//insert
                int y=dp[i][j-1]+1;//delete
                int z=dp[i-1][j-1]+1;
                dp[i][j]=min(x,min(y,z));
            }
        }
        }
        return dp[a.length()][b.length()];
}
int editDist_tab(string a,string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,-1));
   
    return editDist_tab(a,b,dp);
}
int main(){
    cout<<editDistRec("abc","xyz")<<endl;
    cout<<editDist_mem("abc","xyz")<<endl;
    cout<<editDist_tab("abc","xyz")<<endl;
    return 0;
}