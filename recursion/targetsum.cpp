#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* ques 1 to achieve targetsum=60
int targetsum(vector<int>&arr,int vidx, int target, string ans){
    if(vidx==arr.size()||target<0){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    if(target<0){
        return 0;
    }
    return 0;
    }
    int count=0;
    count+=targetsum(arr,vidx+1,target-arr[vidx],ans + to_string(arr[vidx]));
    count+=targetsum(arr,vidx+1,target,ans);
    return count;
}

void setquestion(){
    vector<int>arr={10,20,30,40,50,60,70,80,90,100};
    cout<<targetsum(arr,0,60,"")<<endl;
}

int main(){
    setquestion();
    return 0;
}
*/

/* ques to print to equisets having equal sum but different combination of elements but here duplicacy occurs!
int targetsum(vector<int>&arr,int vidx, int set1, int set2, string ans1, string ans2){
    if(vidx==arr.size()|| (set1!=0 && set1==set2)){
    if(set1==set2){
        cout<<ans1<<"="<<ans2<<endl;
        return 1;
    }
    return 0;
    }
    int count=0;
    count+=targetsum(arr,vidx+1,set1+arr[vidx],set2,ans1 + to_string(arr[vidx]),ans2);
    //count+=targetsum(arr,vidx+1,target,ans);
    
    count+=targetsum(arr,vidx+1,set1,set2+arr[vidx],ans1 ,ans2+ to_string(arr[vidx]));
    return count;
}

void setquestion(){
    vector<int>arr={10,20,30,40,50,60,70};
    cout<<targetsum(arr,0,0,0,"","")<<endl;
}

int main(){
    setquestion();
    return 0;
}
*/


/* here duplicacy is handled in prev ques!

int targetsum(vector<int>&arr,int vidx, int set1, int set2, string ans1, string ans2){
    if(vidx==arr.size()|| (set1!=0 && set1==set2)){
    if(set1==set2){
        cout<<ans1<<"="<<ans2<<endl;
        return 1;
    }
    return 0;
    }
    int count=0;
    count+=targetsum(arr,vidx+1,set1+arr[vidx],set2,ans1 + to_string(arr[vidx]),ans2);
    //count+=targetsum(arr,vidx+1,target,ans);
    
    count+=targetsum(arr,vidx+1,set1,set2+arr[vidx],ans1 ,ans2+ to_string(arr[vidx]));
    return count;
}

void setquestion(){
    vector<int>arr={10,20,30,40,50,60,70};
    cout<<targetsum(arr,1,10,0,"10","")<<endl;
}

int main(){
    setquestion();
    return 0;
}
*/
/*tried hw ques!
int combination(vector<int>&arr,vector<string>& dic,string num,string ans){
    if(num.size()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=1;i<=2&& i<num.size();i++){
    string ch=num.substr(0,i);

    string roq=num.substr(i+1);
    if(stoi(ch)-1<=26){

    count+=combination(arr,dic,roq,ans+ dic[arr[stoi(ch)-1]]);
    }
    }
    return count;
}

void setquestion(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    vector<string> dic={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    cout<<combination(arr,dic,"1144","")<<endl;
}

int main(int args,char **argv){
    setquestion();
    return 0;
}
*/

/*hw ques!*/
int encoding(string ques,string ans){
    if(ques.size()==0){
        cout<<ans<<endl;
        return 1;
    }
    char ch=ques[0];
    int count=0;
    if(ch=='0'){
        count+=encoding(ques.substr(1),ans);
    }
    else{
        count+=encoding(ques.substr(1),ans+ (char)(ch-'1'+'a'));
        if(ques.size()>1){
            char ch1=ques[1];
            int num=(ch-'0')*10 +(ch1-'0');
            if(num<26){
                count+=encoding(ques.substr(2),ans+(char)('a'+num-1));
            }
        }
    }
    return count;
}

int main(){
    cout<<encoding("110028","")<<endl;
    return 0;
}