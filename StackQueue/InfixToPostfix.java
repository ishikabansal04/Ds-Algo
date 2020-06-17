import java.util.*;
import java.util.Stack;

public class InfixToPostfix{

public static boolean isoperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' ||ch=='/' ||ch=='^' ) return true;
     return false;
}    

public static int priority(char op){
   
    if(op=='+' || op=='-') return 0;
    else if(op=='*' || op=='/') return 1;
    else if(op=='^' ) return 2;
    else return -1;
}


public static String infixevaluate(String str){
    Stack<String> numSt=new Stack<>();
    Stack<Character> opSt=new Stack<>();
    String ans="";

    for(int i=0;i<str.length();i++){
      
        char ch=str.charAt(i);
        if(ch>='0' && ch<='9'){
          String a="";
          a=a+ch;
            numSt.push(a);
        }
        else if(ch=='(') opSt.push(ch);
        else if(isoperator(ch)){
            /*if(opSt.size()!=0 && priority(opSt.peek())<priority(ch)){
                opSt.push(ch);
            }
            else if(opSt.size()!=0){*/
                while(opSt.size()!=0 && opSt.peek()!='(' && priority(opSt.peek())>priority(ch)){
                     String val1=numSt.pop();
                     String val2=numSt.pop();
                     char c=opSt.pop();
                      ans=val2+val1+c;
                     numSt.push(ans);
                }
                opSt.push(ch);
            
        }
        else{
            while(opSt.peek()!='('){
                 String val1=numSt.pop();
                     String val2=numSt.pop();
                     char c=opSt.pop();
                     ans=val2+val1+c;
                     numSt.push(ans);
            }
            opSt.pop();
        }
    }
        while(opSt.size()!=0){
                 String val1=numSt.pop();
                     String val2=numSt.pop();
                     char c=opSt.pop();
                      ans=val2+val1+c;
                     numSt.push(ans);
        }
    
        return numSt.pop();

}

    public static void main(String[] args){
        //String str=;
        System.out.println(infixevaluate("8+4*3"));
    }
}