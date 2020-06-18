import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int N=scn.nextInt();
        int arr[]=new int[N];
        for(int i=0;i<N;i++){
            int val=scn.nextInt();
            arr[i]=val;
        }
        int target=scn.nextInt();
        System.out.println(targetsumcount(arr,0,target,0,""));
        System.out.println(targetarr(arr,target,0));
        targetsum(arr,0,target,0,"");
    }
       
    public static int targetsumcount(int[]arr,int idx,int target,int setsum,String ans){
        if(idx==arr.length){
            if(target==setsum){
           // System.out.println(ans);
                return 1;
        }
            return 0;
        }
        int count=0;
        count+=targetsumcount(arr,idx+1,target,setsum,ans);
        count+=targetsumcount(arr,idx+1,target,setsum+arr[idx],ans+arr[idx]);
       return count;
    }
    
    public static ArrayList<String> targetarr(int[]arr,int target,int idx){
        if(target==0){
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        if(target<0){
            ArrayList<String> base2=new ArrayList<>();
            return base2;
        }
        ArrayList<String> myAns=new ArrayList<>();
        for(int i=idx;i<arr.length;i++){
           
            ArrayList<String>recAns=targetarr(arr,target-arr[i],i);
            for(String s:recAns){
            String myans=s+arr[i];
            myAns.add(myans);
            
            } 
        }
return myAns;
    }
    
    public static void targetsum(int[]arr,int idx,int target,int setsum,String ans){
        if(idx==arr.length){
            if(target==setsum){
            System.out.println(ans);
        }
            return;
        }
     targetsum(arr,idx+1,target,setsum,ans);
        targetsum(arr,idx+1,target,setsum+arr[idx],ans+arr[idx]+" ");
       
    }
    }
