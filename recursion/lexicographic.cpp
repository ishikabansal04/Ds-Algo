#include <iostream>
#include <string.h>
using namespace std;

int subsequences(string ques,string arr[]){
    if(ques.empty()){
        arr[0]="";
        return 1;
    }

    char ch=ques[0];
        int count=subsequences(ques.substr(1),arr);
    for(int i=0;i<count;i++){
        arr[i+count]=ques[0]+arr[i];
    }
    return 2*count;
}

void lexicographic(string arr[],int n){
    string temp="";
     for (int i = 0; i<n-1 ; ++i){
        for (int j = i + 1; j<n; ++j) {
            if(arr[i]>arr[j]){
                 arr[i].swap(arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    string str="ABC";
    string *arr=new string[1000];
    int count=subsequences(str,arr);
     lexicographic(arr,count);
    //  for(int i=0;i<count;i++){
    //     cout<<arr[i]<<endl;
    // }
    return 0;
}