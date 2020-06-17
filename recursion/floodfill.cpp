#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* ques 1. of 4 paths/ways to move

bool isValidLocation(vector<vector<bool>>& isdone, int x, int y){
    if(x<0|| y<0|| x>=isdone.size()|| y>=isdone[0].size()|| isdone[x][y]){
        return false;
    }
    return true;
}

int floodfill(vector<vector<bool>>& isdone, int sr, int sc,int er, int ec, string ans){
    if(sr==er &&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    isdone[sr][sc]=true;;
    if(isValidLocation(isdone,sr+1,sc)){
        count += floodfill(isdone,sr+1,sc,er,ec,ans+"D");
    }

    if(isValidLocation(isdone,sr,sc+1)){
        count += floodfill(isdone,sr,sc+1,er,ec,ans+"R");
    }

    if(isValidLocation(isdone,sr-1,sc)){
        count += floodfill(isdone,sr-1,sc,er,ec,ans+"U");
    }

    if(isValidLocation(isdone,sr,sc-1)){
        count += floodfill(isdone,sr,sc-1,er,ec,ans+"L");
    }    

    isdone[sr][sc]=false;
    return count;
}

void floodfill_QUESTION(){
    vector<vector<bool>> isdone(3,vector<bool>(4,false));
    cout<<floodfill(isdone,0,0,2,3,"")<<endl;
}


int main(){
    floodfill_QUESTION();
    return 0;
}

*/

/* ques 2 of 8 ways to move
bool isValidLocation(vector<vector<bool>>& isdone, int x, int y){
    if(x<0|| y<0|| x>=isdone.size()|| y>=isdone[0].size()|| isdone[x][y]){
        return false;
    }
    return true;
}

int floodfill(vector<vector<bool>>& isdone, int sr, int sc,int er, int ec, string ans){
    if(sr==er &&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    isdone[sr][sc]=true;;
    if(isValidLocation(isdone,sr+1,sc)){
        count += floodfill(isdone,sr+1,sc,er,ec,ans+"D");
    }

    if(isValidLocation(isdone,sr,sc+1)){
        count += floodfill(isdone,sr,sc+1,er,ec,ans+"R");
    }

    if(isValidLocation(isdone,sr-1,sc)){
        count += floodfill(isdone,sr-1,sc,er,ec,ans+"U");
    }

    if(isValidLocation(isdone,sr,sc-1)){
        count += floodfill(isdone,sr,sc-1,er,ec,ans+"L");
    }   
     if(isValidLocation(isdone,sr+1,sc+1)){
        count += floodfill(isdone,sr+1,sc+1,er,ec,ans+"A");
    }

 if(isValidLocation(isdone,sr-1,sc-1)){
        count += floodfill(isdone,sr-1,sc-1,er,ec,ans+"B");
    }

 if(isValidLocation(isdone,sr+1,sc-1)){
        count += floodfill(isdone,sr+1,sc-1,er,ec,ans+"C");
    }

 if(isValidLocation(isdone,sr-1,sc+1)){
        count += floodfill(isdone,sr-1,sc+1,er,ec,ans+"E");
    }


    isdone[sr][sc]=false;
    return count;
}

void floodfill_QUESTION(){
    vector<vector<bool>> isdone(3,vector<bool>(4,false));
    cout<<floodfill(isdone,0,0,2,3,"")<<endl;
}


int main(){
    floodfill_QUESTION();
    return 0;
}

*/


/* ques 1 of 4 ways using 2nd method
bool isValidLocation(vector<vector<bool>>&isdone,int x,int y){
    if(x<0||y<0|| x>=isdone.size()||y>=isdone[0].size()||isdone[x][y]){
        return false;
    }
    return true;
}

int floodfill(vector<vector<bool>>&isdone,int sr,int sc,int er, int ec,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }

    //converting 2d array into 1d array
    //int sr=start/isdone[0].size();
    //int sc=locstart%isdone[0].size();

    int dir[4][2]={ {0,1},
                    {1,0},
                    {0,-1},
                    {-1,0} };
    int count=0;
    isdone[sr][sc]=true;
    string dir_[4]={"D","R","U","L"};
    for(int d=0;d<4;d++){
        int x= sr+ dir[d][0];
        int y= sc+ dir[d][1];
        if(isValidLocation(isdone,x,y)){
            count+=floodfill(isdone,x,y,er,ec,ans+dir_[d]);
        }
    }                
    isdone[sr][sc]=false;
    return count;
}

void floodfillquestions(){
    vector<vector<bool>>arr(3,vector<bool>(4,false));
    cout<<floodfill(arr,0,0,2,3," ");
}

int main(){
    floodfillquestions();
    return 0;
}*/



/* ques of 8 ways using 2nd method and including blocked paths
bool isValidLocation(vector<vector<bool>>&isdone,int x,int y){
    if(x<0||y<0|| x>=isdone.size()||y>=isdone[0].size()||isdone[x][y]){
        return false;
    }
    return true;
}

int floodfill(vector<vector<bool>>&isdone,int sr,int sc,int er, int ec,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }

   
    int dir[8][2]={ {0,1},
                    {1,0},
                    {0,-1},
                    {-1,0},
                    {1,1},
                    {1,-1},
                    {-1,1},
                    {-1,-1} };
    int count=0;
    isdone[sr][sc]=true;
    string dir_[8]={"D","R","U","L","A","B","C","E"};
    for(int d=0;d<8;d++){
        int x= sr+ dir[d][0];
        int y= sc+ dir[d][1];
        if(isValidLocation(isdone,x,y)){
            count+=floodfill(isdone,x,y,er,ec,ans+dir_[d]);
        }
    }                
    isdone[sr][sc]=false;
    return count;
}

void floodfillquestions(){
    vector<vector<bool>>isdone={{0,1,0,0,0},
                             {0,0,1,0,1},
                             {0,0,0,0,0},
                             {0,1,0,0,0}
                             };
    cout<<floodfill(isdone,0,0,3,4," ");
}

int main(){
    floodfillquestions();
    return 0;
}
*/