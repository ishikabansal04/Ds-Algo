import java.util.Scanner;
import java.util.ArrayList;
//import java.util.ArrayList; 
public class shoeprob{
    public static void main(String [] args){
        int a[]={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};
        
        ArrayList<Integer>arr=new ArrayList<>();
        for(int i=0;i<17;i++){
            arr.add(a[i]);
        }
        solve(arr);
    }

    public static void solve(ArrayList<Integer>arr){
        int beg=0;
        int end=arr.size();
        int mid=(beg+end)/2 ;
        while(beg<end){
        if(arr.get(mid-1)!=arr.get(mid)){
            end=mid-1;   
        }
        else{
            beg=mid+1;
        }
        }
        System.out.print(arr.get(mid));
    }
    }