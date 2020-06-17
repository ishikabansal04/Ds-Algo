import java.util.*;

public class histogram{
    public static void main(String[]args){
        int[] height={6,2,5,4,5,1,6};
        largestArea(height);
         System.out.println(maxCArea(height));
    }
    
    public static void largestArea(int[] height) {
        int maxArea = 0;

        Stack<Integer> st = new Stack<>();

        int i=0;
        for (i = 0; i < height.length; i++) {
            if (st.size() == 0 || height[st.peek()] <= height[i])   //sometimes this gives error bound of exception at index -1 ....so do st.size!=1
                st.push(i);
            else {
                while (st.size() != 0 && height[st.peek()] >= height[i]) {   //sometimes this gives error bound of exception at index -1 ....so do st.size!=1
                    int idx = st.pop();
                    int he = height[idx];
                    int width = i - (st.size() == 0 ? -1 : st.peek()) -1;  // coz we consider one prev index 
                    int currArea = he * width;

                    maxArea = Math.max(maxArea, currArea);
                }
                st.push(i);
            }
        }

        while (st.size() != 0) { //sometimes this gives error bound of exception at index -1 ....so do st.size!=1
            int idx = st.pop();
            int he = height[idx];
            int width = i-(st.size() == 0 ? -1 : st.peek()) -1 ;
            int currArea = he * width;

            maxArea = Math.max(maxArea, currArea);
        }
        System.out.println(maxArea);
    }

  public static int maxCArea(int []height){
        int maxArea=0;
        Stack<Integer> st=new Stack<>();
        st.push(-1);
        int i=0;
        while(i<height.length){
            while(st.peek() !=-1 && height[st.peek()]>=height[i]){
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
    
}