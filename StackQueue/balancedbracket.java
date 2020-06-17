import java.util.*;
public class balancedbracket{
    public static void main(String[]args){
        String str="[{((a+b))+(c+d)}]";
        System.out.println(justBalanced(str));
    }
    public static boolean justBalanced(String str){
        Stack<Character> stk=new Stack<>();
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(ch=='('||ch=='{'||ch=='['){
                stk.push(ch);
            }
            else if(ch==')'||ch=='}'||ch==']'){
                if(stk.size()==0) return false;
            else if(ch==')' && stk.peek()=='(') stk.pop();   //these conditions are inside elseif....
             else if(ch=='}' && stk.peek()=='{') stk.pop();
              else if(ch==']' && stk.peek()=='[') stk.pop();
              else return false;
            }
           
        }
        return stk.size()==0;
    }
}