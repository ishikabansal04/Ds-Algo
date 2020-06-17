import java.util.Scanner;
import java.util.ArrayList;

public class fib{
   static int[][] identity={{1,1},{1,0}};

    public static int[][] multiply(int[][] mat1,int[][] mat2){
        int[][] ans=new int[mat1.length][mat2[0].length];
        if(mat1[0].length==mat2.length){
       for(int i=0;i<mat1.length;i++){
           for(int j=0;j<mat2[0].length;j++){
               for(int k=0;k<mat1[0].length;k++){
                   ans[i][j]=mat1[i][k]*mat2[k][j]+ans[i][j];
               }
           }
       } 
        }
       return ans;
    }

    public static int[][] powerbtr(int b){
          if(b==0)
          {   int[][] ans=new int[2][2]; 
              return ans;
              }
         if(b==1) {  
             return identity; 
              }

          
          
        int[][] ans=powerbtr(b/2);
        ans=multiply(ans,ans);
       if(b%2!=0){
        ans= multiply(ans,identity);
       }
       return ans;
    }
  
    public static void main(String[] args){
       int[][] ans=powerbtr(5);
       for(int i=0;i<ans.length;i++){
           for(int j=0;j<ans[0].length;j++){
            System.out.print(ans[i][j]+" ");
           }
       }  
    }
}