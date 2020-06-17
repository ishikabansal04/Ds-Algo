import java.util.LinkedList;
import java.util.Stack;

public class infix{

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

public static int operation(int num1,int num2, char op){ //pop1-num1 && pop2==num2.
    if(op=='+') return num2+num1;
    else if(op=='-') return num2-num1;
    else if(op=='*') return num2*num1;
    else if(op=='/') return num2/num1;
    else if(op=='%') return num2%num1;
    else return (int)Math.pow(num2,num1);
}

public static int infixevaluate(String str){
    Stack<Integer> numSt=new Stack<>();
    Stack<Character> opSt=new Stack<>();
    for(int i=0;i<str.length();i++){
        char ch=str.charAt(i);
        if(ch>='0' && ch<='9'){
            numSt.push(ch-'0');
        }
        else if(ch=='(') opSt.push(ch);
        else if(isoperator(ch)){
            /*if(opSt.size()!=0 && priority(opSt.peek())<priority(ch)){
                opSt.push(ch);
            }
            else if(opSt.size()!=0){*/
                while(opSt.size()!=0 && opSt.peek()!='(' && priority(opSt.peek())>priority(ch)){
                     int val1=numSt.pop();
                     int val2=numSt.pop();
                     char c=opSt.pop();

                     int ans=operation(val1,val2,c);
                     numSt.push(ans);
                }
                opSt.push(ch);
            }
        else{
            while(opSt.peek()!='('){
                 int val1=numSt.pop();
                     int val2=numSt.pop();
                     char c=opSt.pop();

                     int ans=operation(val1,val2,c);
                     numSt.push(ans);
            }
            opSt.pop();
        }
    }
        while(opSt.size()!=0){
              int val1=numSt.pop();
                     int val2=numSt.pop();
                     char c=opSt.pop();

                     int ans=operation(val1,val2,c);
                     numSt.push(ans);
        }

        return numSt.pop();

}

    public static void main(String[] args){
        //String str=;
        System.out.println(infixevaluate("8+4*3-9/3^(2-1)"));
    }
}