public class client{
    public static void main(String [] args){
        int[] arr={10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
        bttree bt=new bttree(arr);
        //System.out.println(bt.construct(arr).data);
        bt.display();
    }
}