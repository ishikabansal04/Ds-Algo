import java.util.*;

public class justNext{

    public static void main(String []args){
      int arr[]={1,3,2,4,8,6,5,9,1};
     // nextLG(arr);
     // nextSG(arr);
     // prevLG(arr);
     // prevSG(arr);
    }
 
 //ques1. find just next largest  number for each element of arr!=====
    public static void nextLG(int []arr){
      Stack<Integer> st=new Stack<>();
    
      for(int i=0;i<arr.length;i++){
    
            while(st.size()!=0 && st.peek()<=arr[i]){
                  st.pop();
            }
            if(st.size()==0){
               System.out.println(arr[i]+"->"+-1);
            }
            else {
               System.out.println(arr[i]+"->"+st.peek());
            }
            st.push(arr[i]);
          }
    }

    //ques2. find just next smallest  number for each element of arr!=====
    public static void nextSG(int []arr){
      Stack<Integer> st=new Stack<>();
    
      for(int i=0;i<arr.length;i++){
    
            while(st.size()!=0 && st.peek()>=arr[i]){
                  st.pop();
            }
            if(st.size()==0){
               System.out.println(arr[i]+"->"+-1);
            }
            else {
               System.out.println(arr[i]+"->"+st.peek());
            }
            st.push(arr[i]);
          }
    }
    
    //ques3. find just prev largest  number for each element of arr!=====
    public static void prevLG(int []arr){
      Stack<Integer> st=new Stack<>();
    
      for(int i=arr.length-1;i>=0;i--){
    
            while(st.size()!=0 && st.peek()<=arr[i]){
                  st.pop();
            }
            if(st.size()==0){
               System.out.println(arr[i]+"->"+-1);
            }
            else {
               System.out.println(arr[i]+"->"+st.peek());
            }
            st.push(arr[i]);
          }
    }

    //ques4. find just prev smallest  number for each element of arr!=====
     public static void prevSG(int []arr){
      Stack<Integer> st=new Stack<>();
    
      for(int i=arr.length-1;i>=0;i--){
    
            while(st.size()!=0 && st.peek()>=arr[i]){
                  st.pop();
            }
            if(st.size()==0){
               System.out.println(arr[i]+"->"+-1);
            }
            else {
               System.out.println(arr[i]+"->"+st.peek());
            }
            st.push(arr[i]);
          }
    }
}