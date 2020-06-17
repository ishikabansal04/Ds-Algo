#include<iostream>
#include<vector>
using namespace std;
int i;
int j;
void display(vector<vector<int>>&arr){
    for(vector<int>ar:arr){
        for(int ele: ar){
            cout<<ele<<"\t";
        }
        cout<<"\n";
    }
}
void swapfor4(vector<vector<int>>&arr,int i,int j,int k,int l){

int temp=arr[i][j];
arr[i][j]=arr[k][l];
arr[k][l]=temp;

}

void transpose(vector<vector<int>>&arr){
    for(i=0;i<arr.size();i++){
        for(j=i;j<arr[0].size();j++){
            //swapfor(arr,i,j,j,i)
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void colswap(vector<vector<int>>&arr){
    for(i=0;j=arr.size()-1,i<j;i++,j--){
        for(int k=0;k<arr.size();k++){
            //swapfor(arr,i,j,j,i)
            swap(arr[k][i],arr[k][j]);
        }
    }
}

void rowswap(vector<vector<int>>&arr){
    for(i=0;j=arr.size()-1,i<j;i++,j--){
        for(int k=0;k<arr.size();k++){
            swap(arr[i][k],arr[i][j]);
        }
    }
}

void turnby90(vector<vector<int>>&arr,bool mask){
  transpose(arr);
  if(mask==true)
    colswap(arr);
  else
    rowswap(arr);
  display(arr);
}

int main(){
    vector<vector<int>>arr={{1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12},
                             {13,14,15,16}};
 
  
   display(arr);
   cout<<"\n\n\n";
   turnby90(arr,false);

   return 0;                       
}