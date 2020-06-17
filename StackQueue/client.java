public class client{
    public static void main(String []args){
       /* Mystack st=new Mystack(11);
        for(int i=0;i<10;i++){
            st.push(i+10);
        }
        st.print();
        //System.out.println(st.size());
        // System.out.println(st.isEmpty());
        // st.push(50);
        // System.out.println(st.top());
        // System.out.println(st.pop());
*/
          DynamicStack st = new DynamicStack(11);
        // MyQueue qu = new MyQueue();
        for (int i = 0; i < 30; i++) {
            st.push(i + 100);
        }

        st.print();
    }
}