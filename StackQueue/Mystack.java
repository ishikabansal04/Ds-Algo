public class Mystack{

    protected int[] st;
    protected int idx=-1;

    Mystack(){
        this.st= new int[10];
    }
    Mystack(int size){
        this.st=new int[size];
    }

    public void print(){
        System.out.print("[");
        for(int i=idx;i>0;i--){
            System.out.print(st[i]+",");
        }
        System.out.println(st[0]+"]");
    }

    public int size(){
        return this.idx+1;
    }

    public boolean isEmpty(){
        return this.idx==-1;
    }

    public int top(){
        if(idx==-1){
            System.err.println("StackUnderflow");
            return -1;
        }
        return st[idx];
    }

    public void push(int data){
        if(idx==st.length){
            System.err.println("StackOverflow");
            return;
        }
        idx++;
        st[idx]=data;
    }
    
    public int pop(){
        if(idx==-1){
            System.err.println("StackUnderflow");
            return -1;
        }
        int rv=st[idx];
        idx--;
        return rv;
    }
}