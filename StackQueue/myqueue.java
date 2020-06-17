public class myqueue{
    private int[] arr;
    
    private int st=0;
    private int end=0;
    private int size=0;

    myqueue(){
        this.arr=new int[10];    
        }

    myqueue(int size){
        this.arr=new int[size];
    }    

    public int size(){
        return this.size;
    }

    public boolean isEmpty(){
        return this.size==0;
    }

    public int front(){
        if(this.size==0){
            System.out.println("QueueIsEmpty");
            return -1;
        }
        return arr[st];
    }

    public void push(int data){
        if(this.size==this.arr.length){
            System.out.println("QueueOverflow");
            return ;
        }

        this.arr[this.end]=data;
        this.end=(this.end+1)%this.arr.length;
        this.size++;
    }

    public int pop(){
        if(this.size==0){
            System.out.println("QueueUnderflow");
            return -1;
        }

        int rv=this.arr[this.st];
        this.arr[this.st]=0;
        this.st=(this.st+1)%this.arr.length;
        this.size--;
        return rv;
    }

    public void print(){
        System.out.print("[");
        // for(int i=this.st;i%arr.length<=this.end;i++){
        //    System.out.print(this.arr[i]+",");
        // }

        for(int i =0; i < this.size; i++){
            System.out.print(this.arr[this.st + i]+",");

        }
         System.out.println("]");
    }
}