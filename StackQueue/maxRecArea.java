import java.util.*;
public class maxRecArea{

    public static void main(String []args){
      char arr[][]={{'1','0','1','0','0'},
                    {'1','0','1','1','1'},
                    {'1','0','1','1','1'},
                    {'1','0','0','1','0'}};
      System.out.println(maxAreaMatrix(arr));
    }
     

    public static int maxCArea(int []height){
        int maxArea=0;
        Stack<Integer> st=new Stack<>();
        st.push(-1);                          //left and empty ko handle kerne k liye (width) 
        int i=0;
        while(i<height.length){
            while(st.peek() !=-1 && height[st.peek()]>=height[i]){         //optimization of stack (=)
                int ht=height[st.pop()];
                int area=ht*(i-st.peek()-1);
                maxArea=Math.max(maxArea,area);
            }
            st.push(i);
            i++;
        }
        while(st.peek() !=-1){
                int ht=height[st.pop()];
                int area=ht*(i-st.peek()-1);
                maxArea=Math.max(maxArea,area);
            }
        return maxArea;
    }

    public static int maxAreaMatrix(char[][] arr){
        if(arr.length==0) return 0;
        int []ar=new int[arr[0].length];
        int max_=0;
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                ar[j]=arr[i][j]=='0'? 0:ar[j]+1;
            }
            max_=Math.max(max_,maxCArea(ar));
        }
        return max_;
    }
}