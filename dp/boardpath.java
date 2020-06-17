import java.util.Scanner;
import java.util.ArrayList;

public class boardpath{
    static int[] dp=new int[11];
    
    public static int boardpath(int tar){
        if(tar==0) return 1;
        int count=0;
        
        if(dp[tar]!=0) return dp[tar];
        for(int i=1;i<=6;i++){
            if(tar-i>=0){
                count+=boardpath(tar-i);
            }
        }
        
        dp[tar]=count;
        return count;
    }

    public static void boardpathtabulation(int tar){
        dp[tar]=1;
        for(int i=tar;i>=0;i--){
            for(int dice=1;dice<=6 && (dice+i)<=tar;dice++){
                dp[i]+=dp[i+dice];
            }
        }
    }

    public static void main(String[] args){
      /*  System.out.println(boardpath(10));
        for(int i=0;i<11;i++){
            System.out.print(dp[i]+"  ");
        }
      */
        boardpathtabulation(10);
          for(int i=0;i<11;i++){
            System.out.print(dp[i]+"  ");
        }
    }
}