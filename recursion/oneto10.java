import java.util.Scanner;
public class oneto10{

public static void solve(){
    System.out.println(powerbtr(2,9));
}

//ques 1,2,3
/*public static void increasing(int a,int b){
    if(b==a){
        System.out.println(a);
        return;
    }
    if(a%2!=0){  
    System.out.println(a);}
    increasing(a+1,b);
    if(a%2==0){
    System.out.println(a);}
}*/


//ques 5
/*public static int power(int a, int b){
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);
    
}
  */

//ques 6  
  public static int powerbtr(int a, int b) {
      if(b==0){
          return 1;
      }
  int res=powerbtr(a,b/2);
  res*=res;
  if(b%2!=0){
      res*=a;
  }    
  return res;
  } 

  
    public static void main(String[]argv)
         {
            solve();
         }
}    