#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* ques 1 combinations of every coin occuring infinite times
int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
     for(int i=idx;i<arr.size();i++){
         if(target-arr[i]>=0){
             count+=coinchange(arr,i,target-arr[i],ans+to_string(arr[i]));
         }
     }
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/*ques 2 of permutations of combinations in ques 1
int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
     for(int i=0;i<arr.size();i++){
         if(target-arr[i]>=0){
             count+=coinchange(arr,i,target-arr[i],ans+to_string(arr[i]));
         }
     }
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* ques 3 of  combinations in ques 1 with every coin occuring only 1 time!

int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
     for(int i=idx;i<arr.size();i++){
         if(target-arr[i]>=0){
             count+=coinchange(arr,i+1,target-arr[i],ans+to_string(arr[i]));
         }
     }
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* ques 4 of making permutations in ques 3 using blockpath method!
int coinchange(vector<int>&arr,vector<bool>&isdone,int target,int ele,string ans){
     if(ele==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
     for(int i=0;i<arr.size();i++){
         if(target-arr[i]>=0&& !isdone[i]){
             isdone[i]=true;
             count+=coinchange(arr,isdone,target-arr[i],ele+1,ans+to_string(arr[i]));
             isdone[i]=false;
         }
     }
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    vector<bool> isdone(4,false);
    cout<<coinchange(arr,isdone,10,0,"");
}

int main(){
    setquestion();
    return 0;
}
*/

/* ques 5 i.e. subsequence method of ques 1!
int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
  
         if(target-arr[idx]>=0){
             count+=coinchange(arr,idx,target-arr[idx],ans+to_string(arr[idx]));
             count+=coinchange(arr,idx+1,target,ans);
         }
     
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/

/* ques 6 i.e. subsequence method of ques 2!
int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
  
         if(target-arr[idx]>=0){
             count+=coinchange(arr,0,target-arr[idx],ans+to_string(arr[idx]));
             count+=coinchange(arr,idx+1,target,ans);
         }
     
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}

*/
/* ques 7 i.e. subsequence method of ques 3!
int coinchange(vector<int>&arr,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
  
         if(target-arr[idx]>=0){
             count+=coinchange(arr,idx+1,target-arr[idx],ans+to_string(arr[idx]));
             count+=coinchange(arr,idx+1,target,ans);
         }
     
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    cout<<coinchange(arr,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/

/* ques 8 i.e. subsequence method of ques 4!
int coinchange(vector<int>&arr,vector<bool>&isdone,int idx,int target,string ans){
     if(idx==arr.size()||target<=0){
         if(target==0){
             cout<<ans<<endl;
             return 1;
         }
         return 0;
     }

     int count=0;
 
         if(target-arr[idx]>=0&& !isdone[idx]){
             isdone[idx]=true;
             count+=coinchange(arr,isdone,0,target-arr[idx],ans+to_string(arr[idx]));
          
             isdone[idx]=false;
         }
        count+=coinchange(arr,isdone,idx+1,target,ans);
     return count;
}

void setquestion(){
    vector<int> arr={2,3,5,7};
    vector<bool> isdone(4,false);
    cout<<coinchange(arr,isdone,0,10,"");
}

int main(){
    setquestion();
    return 0;
}
*/