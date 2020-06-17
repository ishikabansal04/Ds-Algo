import java.util.Scanner;
import java.util.ArrayList;

public class mazepath{
    static int[][] dp=new int[7][7];
    static int calls=0;
   
   //single move memorization method=========================
    public static int mazepath(int sr,int er,int sc,int ec){

        if(sr==er && sc==ec) return 1;
        int count=0;
        
        if(dp[sr][sc]!=0) return dp[sr][sc];
        if(er==ec && dp[sc][sr]!=0) return dp[sc][sr];

        calls++;
        if(sr+1<=er){
           count+= mazepath(sr+1,er,sc,ec);
        }
        if(sc+1<=ec){
            count+=mazepath(sr,er,sc+1,ec);
        }
        if(sr+1<=er && sc+1<=ec){
            count+=mazepath(sr+1,er,sc+1,ec);
        }
        dp[sr][sc]=count;
        if(er==ec) { 
            dp[sc][sr]=count;
        }
        return count;
    }

//single moves tabulation============================
    public static void mazepathtabulation(int ec,int er){
        dp[er][ec]=1;
        for(int sr=er;sr>=0;sr--){
            for(int sc=ec;sc>=0;sc--){

        if(sr+1<=er)
          dp[sr][sc]+=dp[sr+1][sc];

        if(sr+1<=er&&sc+1<=ec)
          dp[sr][sc]+=dp[sr+1][sc+1];

        if(sc+1<=ec)
          dp[sr][sc]+=dp[sr][sc+1];
            }
        }
    }

// multiple moves memorization=================================
     public static int multimazepath(int sr,int er,int sc,int ec){
     
        if(sr==er && sc==ec) return 1;
        int count=0;
        
       if(dp[sr][sc]!=0) return dp[sr][sc];
        if(er==ec && dp[sc][sr]!=0) return dp[sc][sr];

          calls++;
        for(int jump=1;jump<=er;jump++){
        if(sr+jump<=er){
           count+= multimazepath(sr+jump,er,sc,ec);
        }
        if(sc+jump<=ec){
            count+=multimazepath(sr,er,sc+jump,ec);
        }
        if(sr+jump<=er && sc+jump<=ec){
            count+=multimazepath(sr+jump,er,sc+jump,ec);
        }
        }
       dp[sr][sc]=count;
        if(er==ec) { 
            dp[sc][sr]=count;
        }
        return count;
    }
    

//multiple moves tabulated dp========================= 
    public static void multimazepathtabulation(int ec,int er){
        dp[er][ec]=1;
        for(int sr=er;sr>=0;sr--){
            for(int sc=ec;sc>=0;sc--){

        for(int jump=1;sr+jump<=er;jump++)
          dp[sr][sc]+=dp[sr+jump][sc];

        for(int jump=1;sr+jump<=er&&sc+jump<=ec;jump++)
          dp[sr][sc]+=dp[sr+jump][sc+jump];

        for(int jump=1;sc+jump<=ec;jump++)
          dp[sr][sc]+=dp[sr][sc+jump];
            }
        }
    }

   public static void main(String[] args){
  //  System.out.println(mazepath(0,6,0,6));
   
  //   mazepathtabulation(6,6);  
  
   //  System.out.println(multimazepath(0,4,0,4));
   //   System.out.println(); 
    //   multimazepathtabulation(3,3);
     for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) 
                System.out.print(dp[i][j]+"  ");
            System.out.println();    
        }
   }
}