#include<iostream>
#include<vector>
#include<string>
#define vi vector<int>
#define vii vector<vi>
using namespace std;
/*method 1 for sudoku problem!

void display(vii&boxes){
    for(vi ar:boxes){
        for(int i : ar){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isvalidlocation(vii &boxes,int x,int y,int val){
    int i;
    for(i=0;i<9;i++){
        if(boxes[i][y]==val)
        return false;

    }
    for(i=0;i<boxes[0].size();i++){
        if(boxes[x][i]==val)
        return false;
        
    }
    int nr=(x/3)*3;
    int nc=(y/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(boxes[nr+i][nc+j]==val)
            return false;
         
        }
    }
 return true;
}

int sudoko_01(vii&boxes,int idx){
    if(idx==81){
        display(boxes);
        return 1;
    }
    int count=0;
    int r=idx/9;
    int c=idx%9;
    if(boxes[r][c]==0){
        for(int val=1;val<=9;val++){
            if(isvalidlocation(boxes,r,c,val)){
                boxes[r][c]=val;
                count+=sudoko_01(boxes,idx+1);
                boxes[r][c]=0;
            }
        }
    }
            else
            count+=sudoko_01(boxes,idx+1);
        
        return count;
    
}
void sudoko(){
    vector<vector<int>>boxes ={{3,0,6,5,0,8,4,0,0},
                               {5,2,0,0,0,0,0,0,0},
                               {0,8,7,0,0,0,0,3,1},
                               {0,0,3,0,1,0,0,8,0},
                               {9,0,0,8,6,3,0,0,5},
                               {0,5,0,0,9,0,6,0,0},
                               {1,3,0,0,0,0,2,5,0},
                               {0,0,0,0,0,0,0,7,4},
                               {0,0,5,2,0,6,3,0,0}
    };

    cout<<sudoko_01(boxes,0);

}

int main(){
    sudoko();
    return 0;
}

*/
/*bitwise method!
void display(vii&boxes){
    for(vi ar:boxes){
        for(int i : ar){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isvalidlocation(vii &boxes,int x,int y,int val){
    int i;
    for(i=0;i<9;i++){
        if(boxes[i][y]==val)
        return false;

    }
    for(i=0;i<boxes[0].size();i++){
        if(boxes[x][i]==val)
        return false;
        
    }
    int nr=(x/3)*3;
    int nc=(y/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(boxes[nr+i][nc+j]==val)
            return false;
         
        }
    }
 return true;
}

int sudoko_01(vii&boxes,int idx,vi& row, vi& col,vii& mat){
    if(idx==81){
        display(boxes);
        return 1;
    }
    int count=0;
    int r=idx/9;
    int c=idx%9;
    if(boxes[r][c]==0){
        for(int val=1;val<=9;val++){
             int mask=1<<val;
            if(((row[r]& mask)==0)&&((col[c]& mask)==0)&&((mat[r/3][c/3]& mask)==0)){
                boxes[r][c]=val;
               
                row[r]|=mask;
                col[c]|=mask;
                mat[r/3][c/3]|=mask;
                count+=sudoko_01(boxes,idx+1,row,col,mat);
                boxes[r][c]=0;
                row[r]^=mask;
                col[c]^=mask;
                mat[r/3][c/3]^=mask;
                }
            }
        }
    
            else
            count+=sudoko_01(boxes,idx+1,row,col,mat);
        
        return count;
    
}

void sudokupopulate(vii& boxes,vi& row, vi& col,vii& mat) {
    for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               if(boxes[i][j]==0)
               continue;
               int mask=(1<<boxes[i][j]);
               row[i]|=mask;
               col[j]|=mask;
               mat[i/3][j/3]|=mask;
           }
    }}
void sudoko(){
    vector<vector<int>>boxes ={{3,0,6,5,0,8,4,0,0},
                               {5,2,0,0,0,0,0,0,0},
                               {0,8,7,0,0,0,0,3,1},
                               {0,0,3,0,1,0,0,8,0},
                               {9,0,0,8,6,3,0,0,5},
                               {0,5,0,0,9,0,6,0,0},
                               {1,3,0,0,0,0,2,5,0},
                               {0,0,0,0,0,0,0,7,4},
                               {0,0,5,2,0,6,3,0,0}
    };
    vi row(9,0);
    vi col(9,0);
    vii mat(3,vi(3,0));
    sudokupopulate(boxes,row,col,mat);
    cout<<sudoko_01(boxes,0,row,col,mat);

}

int main(){
    sudoko();
    return 0;
}
*/