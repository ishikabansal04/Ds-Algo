import java.util.*;
public class mincostpath{

    static int[][] costarr={{2,3,0,4},{0,6,5,2},{8,0,3,7},{2,0,4,2}};
    static int[][]dp=new int[4][4];
    public static int costpath(int sr,int sc,int er,int ec){
        if(sr==er && sc==ec) return costarr[er][ec];

        if(dp[sr][sc]!=0) return dp[sr][sc];

         int cost=costarr[sr][sc];
         int dcost=Integer.MAX_VALUE;
         int lcost=Integer.MAX_VALUE;
        if(sr+1<=er){
            dcost=cost+costpath(sr+1,sc,er,ec);
        } 
        if(sc+1<=ec){
            lcost=cost+costpath(sr,sc+1,er,ec);
        }
        dp[sr][sc]=Math.min(dcost,lcost);
        return Math.min(dcost,lcost);
    }


    public static void costpathtabulation(int er,int ec){
     
       int cost=costarr[0][0];
         int dcost=Integer.MAX_VALUE;
         int lcost=Integer.MAX_VALUE;
     
       for(int sr=er;sr>=0;sr--){
           for(int sc=ec;sc>=0;sc--){
            if(sr==er && sc==ec)    
            {
                dp[er][ec]=costarr[er][ec];
                continue;
            }

            if(sr+1<=er){
            dcost=cost+dp[sr+1][sc];
            }

            if(sc+1<=ec){
            lcost=cost+dp[sr][sc+1];
            }

            dp[sr][sc]=Math.min(dcost,lcost);
        }
       }

    }

    public static void main(String[] args){
        System.out.println(costpath(0,0,3,3));
 
        costpathtabulation(3,3); 
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(dp[i][j]+"  ");
            }
            System.out.println();
        }

    }
}