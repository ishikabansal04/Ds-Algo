import java.util.*;
public class minJump{
    static int []arr={1,3,0,4,0,0,2,1,1,0};
    static int []dp=new int [10];
    public static void main(String []args){
     tab();
     for(int i=0;i<dp.length;i++){
         System.out.print(dp[i]+" ");
     }
    }
    public static void tab(){
    dp[arr.length-1]=0;
    
    for(int i=arr.length-2;i>=0;i--){
        int min=1000000;
        for(int  j=1;j<=arr[i] && j+i<arr.length ;j++){
        min=Math.min(dp[i+j],min);
        }   
            dp[i]=min+1;               
    }
    System.out.println("Ans "+ dp[0]);
    }

}