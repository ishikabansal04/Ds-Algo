//import java.util.scanner;
import java.util.ArrayList;

public class ludo{
    public static void main(String [] args){
        System.out.println(ludo(0,10).size());
    }

    public static ArrayList<String> ludo(int si,int ei){
        if(si==ei){
            ArrayList <String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns=new ArrayList<>();
        for(int jump=1;jump+si<=ei && jump<=6;jump++){
             ArrayList<String>recans=ludo(si+jump,ei);

        
        for(String s: recans){
            myAns.add(jump+s);
        }
        }
        return myAns;
    }
}