#include<iostream>
#include<vector>
//#include"node.cpp"
using namespace std;
#define MAX 10
// to check recursively if array is sorted============
bool sorted(int arr[MAX],int idx){
    if(idx==4){
        return true;
    }
    bool res;
    if(arr[idx]>arr[idx+1]) return false;
    if(arr[idx]<arr[idx+1]){
        res=sorted(arr,idx+1);
    }
    return res;
}

// finding sum of elemnts in an array========
int sum(int arr[MAX],int idx){
    if(idx==0) return arr[0];
    int sumofnos=sum(arr,idx-1);
    return sumofnos+arr[idx];
}

//to search an element=========
bool search(int arr[MAX],int idx,int data){
    if(idx==0){
        if(arr[0]==data) return true;
        else return false;
    }
    if(arr[idx]==data) return true;
    bool res=search(arr,idx-1,data);
    
    return res;
}

//to return first index=======
int index(int arr[MAX],int idx,int data,int size){
    if(idx==size-1) {
        if(arr[idx]==data){
            return idx;
        }
        return -1;
    }
    if(arr[idx]==data){
        return idx;
    }
    int recans=index(arr,idx+1,data,size);
    return recans;
}

//last index======
int last_index(int arr[MAX],int idx,int data,int size){
    if(idx==0) {
        if(arr[idx]==data){
            return idx;
        }
        return -1;
    }
    if(arr[idx]==data){
        return idx;
    }
    int recans=last_index(arr,idx-1,data,size);
    return recans;
}

//all indexes======
int count=0;
vector<int> all_indexes(vector<int>& arr,int idx,int data){
    if(idx==arr.size()) {
        vector<int>basearr;
        return basearr;
    }
    if(arr[idx]==data){
        count++;
    }
    vector<int>recans=all_indexes(arr,idx+1,data);
    if(arr[idx]==data){
        recans.push_back(idx);
    }
    return recans;
}

//to multiply using only add and sub recursively======
int multiply(int a,int b){
    if(b==0) return 0;
    if(b==1) return a;
    int ans=multiply(a,b-1);
    return a+ans;
}

//to check if a string is pallindrome or not using recursion============
bool ispallindrome(string s,int idx,int size){
    if(idx==s.length()-1) return true;
    if(s[idx]!=s[size])return false;
    bool res=ispallindrome(s,idx+1,size-1);
    return res;
}

bool pallindrome(string s,int size){
    if(s.length()==0 || (size-1)==0) return true;
    if(s[0]!=s[size-1])return false;
    bool res=pallindrome(s.substr(1),size-2);
    return res;
}

string replace(string ques,string asf,int idx){
    if(idx==ques.length()) {
        return asf;
    }
    string s="";
    if(ques[idx]=='p' && ques[idx+1]=='i'){
        s=s+"3.14";
    }
    else{
    s=replace(ques,asf+ques[idx],idx+1);
    }
    s=replace(ques,asf,idx+1);
    return s;
}
//to convert a string into a number============== eg 1234 in a string is to result 1234 as an integer using recursion!!
int convert(string ques,int idx){
    if(ques.length()==0) return 0;
    char ch=ques[0];
    string roq=ques.substr(1);
    int id=ch-'0';
    int prev;
    int temp=idx;
    while(temp!=0){
        id=id*10;
        temp--;
    }
    int num=id +convert(roq,idx-1);
    return num;
}

void removeX(string ques){
    if(ques.length()==0) return;
    char ch=ques[0];
    if(ch!='x'){
        string roq=ques.substr(1);
        removeX(roq);
    }
    else if(ch=='x'){
        // int i=1;
        // for(;ques[i]!='\0';i++){
        //     ques[i-1]=ques[1];
        // }
        // ques[i-1]=ques[i];
        string roq=ques.substr(1);
        ques=roq;
        removeX(ques);
    }
}

int main(){
  //  int arr[]={10,8,9,7,6,5,9};
    // cout << search(arr,5,-1);
  //  cout<<last_index(arr,6,9,6);
    /*vector<int> arr={10,8,9,7,6,5,9};
    vector<int> ans=all_indexes(arr,0,9);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }*/
    //cout<<multiply(3,5);
    // cout<<ispallindrome("ninja",0,4);
    // cout<<replace("pipi","",0);
    // cout<<convert("1234",3);
     cout<<pallindrome("ninja",5);
    // string str="abxcdxbgex";
    // cout<<str<<endl;
    // removeX(str);
    // cout<<str;
    return 0;
}