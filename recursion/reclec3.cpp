import java.util.Scanner;
import java.util.ArrayList;
public class reclec3{
    public static void main(String [] args){
        solve();
    }

    public static void solve(){
        basicQuestion();
    }
    public static void basicQuestion(){
        System.out.println(subsequent("1234"));
            }

    public static ArrayList<String> subsequence(String str){
      if(str.length()==0){
          ArrayList<String> base=new ArrayList<>();
          base.add("");
          return base;
      }
         char ch=str.charAt(0);
    
         String reststr=str.subString(1);
         ArrayList<String> recAns=subsequence(reststr);
        ArrayList<String>myAns=new ArrayList<>();
        for(String S:recAns){
            myAns.add(s);
            myAns.add(ch+s);

        }   
        return myAns;                                                                                                                         
    }
}