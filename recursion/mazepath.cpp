#include<iostream>
using namespace std;

/*ques 1 :single moves
*/


int mazepath(int sr,int sc,int er, int ec, string ans){
    if(sr==er &&sc==ec){
        cout<<ans<<endl;
        //return 1;
        return 0;
           }

    //int count=0;
    int leftheight=0;
    int rightheight=0;
    if(sr+1<=er){
        
       //count+=mazepath(sr+1,sc,er,ec,ans+"V");
       //count+=mazepath(sr+1,sc,er,ec,ans+"V")+1; 
        leftheight+=mazepath(sr+1,sc,er,ec,ans+"V")+1;     
    }
    if(sc+1<=ec){
        
        //count+=mazepath(sr,sc+1,er,ec,ans+"H");
       // count+=mazepath(sr,sc+1,er,ec,ans+"H")+1;
         rightheight+=mazepath(sr,sc+1,er,ec,ans+"H")+1;
    }
    /*if(sr+1<=er && sc+1<=ec){
        
        //count+=mazepath(sr+1,sc+1,er,ec,ans+"D");
        count+=mazepath(sr+1,sc+1,er,ec,ans+"D");
    }
    return count;
    */
    return max(leftheight,rightheight);
}

int main(){
   cout<< mazepath(0,0,2,2,"");
   
    return 0;
}

/* ques 2: multiple moves

int mazepath_multiple(int sr,int sc,int er, int ec, string ans){
    if(sr==er &&sc==ec){
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    for(int jump=1;jump+sr<=er;jump++){
        count+=mazepath_multiple(sr+1,sc,er,ec,ans+"V");
    }
    for(int jump=1;jump+sc<=ec;jump++){
        count+=mazepath_multiple(sr,sc+1,er,ec,ans+"H");
    }
    for(int jump=1;jump+sr<=er &&jump+sc<=ec;jump++){
        count+=mazepath_multiple(sr+1,sc+1,er,ec,ans+"D");
    }
    return count;

}

int main(){
   
    cout<<mazepath_multiple(0,0,2,2,"");
    return 0;
}*/
/*ques 3 ludo game when jump can max be equal to 6
int ludo(int sr,int er, string ans){
    if(sr==er){
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    for(int jump=1;jump+sr<=er &&jump<=6;jump++){
        count+=ludo(sr+jump,er,ans+to_string(jump));
    }
    
    return count;

}

int main(){
   
    cout<< ludo(0,10,"");
    return 0;
}


*/