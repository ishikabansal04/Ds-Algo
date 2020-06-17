import java.util.Scanner;
import java.util.ArrayList;
public class recarray{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String [] args){
        ArrayList <Integer> arr=new ArrayList<>(); 
        input(arr);
        System.out.println(minimum(arr,0));

    }

    public static void input(ArrayList<Integer>arr){
        int n=scn.nextInt();
        for(int i=0;i<n;i++){
            int val=scn.nextInt();
            arr.add(val);
        }
    }
    public static int minimum(ArrayList<Integer>arr,int idx){
        if(arr.size()==idx){
            return Integer.MAX_VALUE;
        }
        int res=minimum(arr,idx+1);
        return Math.min(res,arr.get(idx));
    }
}