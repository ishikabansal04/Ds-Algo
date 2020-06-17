#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* nqueen by subsequence method on my own!
int nqueen(vector<int>&arr,vector<int>&queen,int idx1,int idx2,string ans){
    if(idx2==queen.size()&& idx1==arr.size()){
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    if(idx1<=arr.size()){
        count+=nqueen(arr,queen,idx1+1,idx2+1,ans+"q"+to_string(queen[idx2])+"b"+to_string(arr[idx1])+" ");
        count+=nqueen(arr,queen,idx1+1,idx2,ans);
    }
  
    return count;
    
}

void setquestion(){
    vector<int>arr={0,1,2,3,4,5};
    vector<int>queen={1,2,3};
    cout<<nqueen(arr,queen,0,0,"")<<endl;
}
int main(){
    setquestion();
    return 0;
}
*/
/* nqueen combinations using different method!
int queencombi(int boxes,int box,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    for(int i=box;i<=boxes;i++){
        count+=queencombi(boxes,i+1,tnq,q+1,ans+"q"+to_string(q)+"b"+to_string(i));
    }
    return count;
}

void setquestion(){
    //vector<int>boxes={0,1,2,3,4,5};
    cout<<queencombi(5,0,3,1,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* permutations using bitwise operators!
int queenPerm(int boxes,int isSet,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    for(int i=0;i<=boxes;i++){
        int mask=(1<<i);
        if((isSet&mask)==0){
            isSet|=mask;
            count+=queenPerm(boxes,isSet,tnq,q+1,ans+"q"+to_string(q)+"b"+to_string(i));
            isSet&=(~mask);}
    }
    return count;
}

void setquestion(){
    //vector<int>boxes={0,1,2,3,4,5};
    cout<<queenPerm(5,0,3,1,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* nqueen problem in 2d array!
int queencombi(vector<vector<bool>>& boxes,int idx,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int r=i/boxes[0].size();
        int c=i%boxes[0].size();
        if(!boxes[r][c]){
            boxes[r][c]=true;
            count+=queencombi(boxes,i+1,tnq,q+1,ans+"q"+to_string(q)+"r"+to_string(r)+"c"+to_string(c)+" ");
            boxes[r][c]=false;
        }
    }
    return count;
}

void setquestion(){
    vector<vector<bool>>boxes(4,vector<bool>(4,false));
    cout<<queencombi(boxes,0,3,1,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/*
int queencombi(vector<vector<bool>>& boxes,int idx,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    int i;
     int r=i/boxes[0].size();
     int c=i%boxes[0].size();
    for( i=0;i<boxes.size()*boxes[0].size();i++){
            count+=queencombi(boxes,i+1,tnq,q+1,ans+"q"+to_string(q)+"r"+to_string(r)+"c"+to_string(c)+" ");
        }
    
    return count;
}

void setquestion(){
    vector<vector<bool>>boxes(4,vector<bool>(4,false));
    cout<<queencombi(boxes,0,3,1,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/*method 1 for nqueen problem!

bool isValidSpot(vector<vector<bool>>& boxes,int x,int y){
    int i,j;
    int n=boxes.size();
    int m=boxes[0].size();
    for(i=x,j=y;i>=0&&j>=0;i--,j--){
        if(boxes[i][j]==true){
            return false;
        }
    }
    for(i=x,j=y;i>=0&&j<boxes[0].size();i--,j++){
        if(boxes[i][j]==true){
            return false;
        } 
    }
    for(i=x;i>=0;i--){
        if(boxes[i][y]==true){
            return false;
        }
    }

    for(i=y;i>=0;i--){
        if(boxes[x][i]==true){
            return false;
        }
    }
    return true;

}
int queencombi(vector<vector<bool>>& boxes,int idx,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int r=i/boxes[0].size();
        int c=i%boxes[0].size();
        if(isValidSpot(boxes,r,c)){
            boxes[r][c]=true;
            count+=queencombi(boxes,i+1,tnq,q+1,ans+"q"+to_string(q)+"r"+to_string(r)+"c"+to_string(c)+" ");
            boxes[r][c]=false;
        }
    }
    return count;
}

void setquestion(){
    vector<vector<bool>>boxes(4,vector<bool>(4,false));
    cout<<queencombi(boxes,0,3,0,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* using less no of loops in nqueen method!
bool isValidLocation(int r,int c, int n,int m){
    if(r<0|| c<0|| r>=n||c>=m)
    return false;
    else
    return true;
}
bool isValidSpot(vector<vector<bool>>& boxes,int x,int y){
    int i,j;
    int n=boxes.size();
    int m=boxes[0].size();
   int arr[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};
   for(i=0;i<4;i++){
       for(int rad=1;rad<max(n,m);rad++){
           int r= x+ rad* arr[i][0];
           int c= y+ rad* arr[i][1];
          if(isValidLocation(r,c,n,m)&& boxes[r][c] ){return false;}
       }
   }
    return true;

}
int queencombi(vector<vector<bool>>& boxes,int idx,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int r=i/boxes[0].size();
        int c=i%boxes[0].size();
        if(isValidSpot(boxes,r,c)){
            boxes[r][c]=true;
            count+=queencombi(boxes,i+1,tnq,q+1,ans+"q"+to_string(q)+"r"+to_string(r)+"c"+to_string(c)+" ");
            boxes[r][c]=false;
        }
    }
    return count;
}

void setquestion(){
    vector<vector<bool>>boxes(4,vector<bool>(4,false));
    cout<<queencombi(boxes,0,3,0,"");
}

int main(){
    setquestion();
    return 0;
}
*/
/* nqueen problem using subsequence methid!
bool isValidLocation(int r,int c, int n,int m){
    if(r<0|| c<0|| r>=n||c>=m)
    return false;
    
    return true;
}
bool isValidSpot(vector<vector<bool>>& boxes,int x,int y){
    int i,j;
    int n=boxes.size();
    int m=boxes[0].size();
   int arr[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};
   for(i=0;i<4;i++){
       for(int rad=1;rad<max(n,m);rad++){
           int r= x+ rad* arr[i][0];
           int c= y+ rad* arr[i][1];
          if(isValidLocation(r,c,n,m)&& boxes[r][c] ){return false;}
       }
   }
    return true;

}
int queencombi(vector<vector<bool>>& boxes,int idx,int tnq, int q, string ans){
    if(q==tnq+1){
        cout<<ans<<endl;
        return 1;
    }
    //there is a case where idx reaches out of bound and we need to handle that!
if(idx==boxes.size()*boxes[0].size()){
    return 0;
}
    int count =0;
    int n=boxes.size();
    int m=boxes[0].size();
   
        int r=idx/m;
        int c=idx%m;
        if(isValidSpot(boxes,r,c)){
            boxes[r][c]=true;
            count+=queencombi(boxes,idx+1,tnq,q+1,ans+"q"+to_string(q)+"r"+to_string(r)+"c"+to_string(c)+" ");
      
            boxes[r][c]=false;
          
        }
    count+=queencombi(boxes,idx+1,tnq,q,ans);
       
   
    return count;
}

void setquestion(){
    vector<vector<bool>>boxes(4,vector<bool>(4,false));
    cout<<queencombi(boxes,0,4,1,"");
}

int main(){
    setquestion();
    return 0;
}
*/