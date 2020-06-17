#include<vector>
#include<iostream>
using namespace std;

/*void display(vector<int>&arr,int idx){
    if(idx==arr.size())
    return;

    cout<<arr[idx]<<" ";
    display(arr,idx+1);

}

int main(){
    vector<int>arr={10,20,30,40,50,60,70};
    display(arr,0);
    return 0;
}
*/
//int max(int);
int display(vector<int>&arr,int idx,int max){
    
    if(idx==arr.size())
    {return max;}
    if(arr[idx]>max){
        max=arr[idx];
    }
    max= display(arr,idx+1,max);
    return max;

}


int main(){
    vector<int>arr={10,20,30,40,50,60,70};
    int res=display(arr,0,0);
    cout<<res;
    return 0;
}

