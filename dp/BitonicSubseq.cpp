#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int LBS(vector<int>& input){

//LIS subsequences=========================================
    vector<int> lis(input.size(),0);
    vector<string> plis(input.size(),"");
    lis[0]=1;
    plis[0]+=to_string(input[0])+" ";

    for(int i=1;i<input.size();i++){
        for(int j=0;j<=i-1;j++){
            if(input[j]<input[i]){
                if(lis[j]+1>lis[i]){
                lis[i]=lis[j]+1;
                plis[i]=plis[j]+to_string(input[i])+" ";
                }

            }
        }
    }

//LDS subsequence ===============
 vector<int> lds(input.size(),0);
    vector<string> plds(input.size(),"");  //this runs nin reverse order across input array unlike LIS
    lds[input.size()-1]=1;
    plds[input.size()-1]+=to_string(input[input.size()-1])+" ";

    for(int i=input.size()-2;i>=0;i--){
        for(int j=input.size()-1;j>=i+1;j--){
            if(input[j]<input[i]){
                if(lds[j]+1>lds[i]){
                lds[i]=lds[j]+1;
                plds[i]=to_string(input[i])+" "+plds[j];
                }
            }
        }
    }

//LBS ..we dont need to make array again but just iteration over lis and lds would work.........
int omax=0;
string opath="";

    for(int i=0;i<input.size();i++){
        if(lis[i]+lds[i]>omax){
            omax=lis[i]+lds[i]-1;
            opath=plis[i]+" "+plds[i];
        }
    }
   cout<<opath<<endl;
    return omax;
}
int main(){
    vector<int>input={10,22,9,33,21,50,41,60,80,1};
    cout<<LBS(input);
    return 0;
}