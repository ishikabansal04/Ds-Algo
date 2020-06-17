import java.util.Scanner;
import java.util.ArrayList;
public class matrixrec{
    public static void main(String [] args){
        System.out.println(mazepath(0,0,2,2));
        System.out.println(diagonalpath(0,0,2,2));
        
    }

    //using horizontal and vertical moves only
    public static ArrayList<String> mazepath(int si,int ei,int sp,int ep){
    if(ei==ep && si==sp){
        ArrayList<String> base=new ArrayList<>();
        base.add(" ");
        return base;
    }
     ArrayList<String> myAns=new ArrayList<>();
    if(ei+1<=ep){
     ArrayList<String> hrecans=mazepath(si,ei+1,sp,ep);
     for(String s:hrecans){
         myAns.add('H'+s);}
     }

     if(si+1<=ep){
     ArrayList<String> vrecans=mazepath(si+1,ei,sp,ep);
     for(String s:vrecans){
         myAns.add('V'+s);}
     }
     return myAns;

    }


//using horizontal,vertical,diagonal moves

public static ArrayList<String> diagonalpath(int si,int ei,int sp,int ep){
    if(si==sp && ei==ep){
        ArrayList<String> base=new ArrayList<>();
        base.add("");
        return base;
    }

    ArrayList<String> myAns=new ArrayList<>();
    if(ei+1<=ep){
     ArrayList<String> hrecans=diagonalpath(si,ei+1,sp,ep);
     for(String s:hrecans){
         myAns.add('H'+s);}
     }

     if(si+1<=ep){
     ArrayList<String> vrecans=diagonalpath(si+1,ei,sp,ep);
     for(String s:vrecans){
         myAns.add('V'+s);}
     }

     if(si+1<=sp && ei+1<=ep){
     ArrayList<String> drecans=diagonalpath(si+1,ei+1,sp,ep);
     for(String s:drecans){
         myAns.add('D'+s);}
     }  
     return myAns;
         
     }
}

