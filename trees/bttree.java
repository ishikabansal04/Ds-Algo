//import java.util.Scanner;
public class bttree{
    
    public class Node{
        public int data=0;
        private Node left=null;
        private Node right=null;

        Node(int data,Node left,Node right){
            this.data=data;
            this.left=left;
            this.right=right;
        }
    } 
    Node root=null;
    public bttree(int [] arr){
        root=construct(arr);
    }
    static int idx=0;
    public Node construct(int[]arr){
        if(idx>=arr.length||arr[idx]==-1){
            idx++;
            return null;
        }
        Node node=new Node(arr[idx],null,null);
            idx++;
            node.left=construct(arr);
            node.right=construct(arr);
            return node;
    }
    public void display(){
        display_(this.root);
    }
    private void display_(Node node){
        if(node==null) return;
        StringBuilder sb=new StringBuilder();
        sb.append(node.left!=null?node.left.data:".");
        sb.append("->"+node.data+"<-");
        sb.append(node.right!=null?node.right.data:".");
        System.out.println(sb.toString());
        display_(node.left);
        display_(node.right);
    }    
}