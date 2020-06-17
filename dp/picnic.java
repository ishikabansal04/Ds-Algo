import java.util.*;
public class picnic{
    static int []dp=new int [6];
    public static void main(String []args){
      // System.out.println(nchild(5));
      tab(5);
      for(int i=0;i<dp.length;i++){
        System.out.print(dp[i]+" ");
      }
    }
    public static int nchild(int n){
        if(n==1 ||n==2) {
            dp[n]=n;
            return n;}
        if(dp[n]!=0) return dp[n];
        int ways;
        ways=nchild(n-1)+(n-1)*nchild(n-2);
        dp[n]=ways;
        return ways;
    }
    public static void tab(int n){
        dp[2]=2;
        dp[1]=1;

        for(int i=3;i<=n;i++){
            int ways=nchild(i-1)+(i-1)*nchild(i-2);
            dp[i]=ways;
        }
        System.out.println("ans "+dp[n]);
        
    }
}