import java.util.Scanner;
import java.util.ArrayList;
public class revisioncls{
    public static void main(String [] args){
         printSpace("abc");
    }
public static ArrayList<String> printSpace(String str){
     if(str.length()==0){
          ArrayList<String> base=new ArrayList<>();
          base.add("");
          return base;
}

char ch=str.charAt(0);
    
         String reststr=str.substring(1);
         ArrayList<String> recAns=subsequence(reststr);
        ArrayList<String>myAns=new ArrayList<>();
        for(String s:recAns){
            myAns.add(s);
            myAns.add(ch+s);





















        }   
        return myAns;                                                                                                                         
    
}                                                                                                                                                                                                                                                                                                                  