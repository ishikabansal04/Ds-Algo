using namespace std;
#include<iostream>
int printDec(int n,int head){
    if(n==0)return 0;
   
    cout<<head;
     printDec(n-1,n-1);
    return(head+1);
    
}

int main(){
    printDec(5,5);
}