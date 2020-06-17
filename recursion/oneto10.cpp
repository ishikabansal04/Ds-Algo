#include<iostream>
using namespace std;

/*int powerbtr(int,int);
int solve(){
    int res=powerbtr(2,9);
    return res;
}

int powerbtr(int a,int b){
    if(b==0){
        return 1;
    }
    int res=powerbtr(a,b/2);
    res*=res;
    if(b%2!=0){
        res*=a;
    }
    return res;
}
*/
int fibonacci(int);
int solve(){
    int res=fibonacci(5);
    cout<<res;
    return res;
}
int fibonacci(int a){
    if(a==0)
    return 0;
    if(a==1)
    return 1;
    
    int res=fibonacci(a-2)+fibonacci(a-1);
    return res;
}
int main(){
    cout<<solve();
    return 0;
}