import java.util.*;

public class targetsum{
    public static void main(String[] args){
        int price[]={2,3,5,6};
         System.out.println(CCpermutation(price,10,new ArrayList[11])); //this is arraylist of array as our arraylist contains string type arrays
         System.out.println(CCcombination(price,10,0,new ArrayList[11][price.length]));  
    }

    public static ArrayList<String> CCcombination(int price[],int tar,int lpi,ArrayList[][]dp){   //lpi= last paid installment
        if(tar==0) {
            ArrayList<String> base=new ArrayList<String>();
            base.add("");
            return base;
        }
        if(tar<0) {
            ArrayList<String> base2=new ArrayList<String>();
            return base2;
        }
        if(dp[tar][lpi]!=null) return dp[tar][lpi];
        ArrayList<String> mresult=new ArrayList<>();
        for(int i=lpi;i<price.length;i++){
            ArrayList<String> recans=CCcombination(price,tar-price[i],i,dp);
            for(String s:recans){
                String mstring=s+price[i];
                mresult.add(mstring);
            }
        }
        dp[tar][lpi]=mresult;
        return mresult;
    }

    public static ArrayList<String> CCpermutation(int price[],int tar,ArrayList[]dp){
        if(tar==0) {
            ArrayList<String> base=new ArrayList<String>();
            base.add("");
            return base;
        }
        if(tar<0) {
            ArrayList<String> base2=new ArrayList<String>();
            return base2;
        }
        if(dp[tar]!=null) return dp[tar];
        ArrayList<String> mresult=new ArrayList<>();
        for(int i=0;i<price.length;i++){
            ArrayList<String> recans=CCpermutation(price,tar-price[i],dp);
            for(String s:recans){
                String mstring=s+price[i];
                mresult.add(mstring);
            }
        }
        dp[tar]=mresult;
        return mresult;
    } 
}