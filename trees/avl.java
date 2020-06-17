public class avl{
   
    public static void main(String[]args){
        int arr[]={10,20,30,40,50,60,70,80,90,100};
    
        Node root=construct(arr,0,9);
        display(root);
        System.out.println();
        Node temp1=deletenode(root,80);
        display(temp1);

    }

     public static class Node{
        Node left=null;
        Node right=null;
        int data=0;
        int height=-1;
        int balance=0;

    Node(int data){
        this.data=data;
        this.height=0;
    } 

    }

    public static Node construct(int arr[],int si,int ei){
    if(si>ei) return null;
    if(si==ei){
        Node node=new Node(arr[si]);
        return node;
    }

    int mid=(si + ei) >> 1;  //right shift by one divides a no by 2!
    Node node=new Node(arr[mid]);
    node.left=construct(arr,si,mid-1);

    node.right=construct(arr,mid+1,ei);
    node.height=getHeight(node);
    node.balance=getBalance(node);
 
    return node;
}

    //display===================================
  
    public static void display(Node node){
        if(node==null) return;
        StringBuilder sb=new StringBuilder();
        sb.append(node.left!=null?node.left.data:".");
        sb.append("->"+node.data+"<-");
        sb.append(node.right!=null?node.right.data:".");
        System.out.println(sb.toString());
        display(node.left);
        display(node.right);
    }

    //getbalance===============================
    public static int getBalance(Node node){
        if(node==null) return 0;

        int lh=-1;
        int rh=-1;
        if(node.left!=null) lh=node.left.height;
        if(node.right!=null) rh=node.right.height;

        return lh-rh;
    }

    //getHeight================================
    public static int getHeight(Node node){
        if(node==null) return -1;
        
        int lh=-1;
        int rh=-1;
        if(node.left!=null) lh=node.left.height;
        if(node.right!=null) rh=node.right.height;

        return Math.max(lh,rh)+1;
    }

    //updateFactor=============================
    public static void getFactor(Node node){
        node.height=getHeight(node);
        node.balance=getBalance(node);
    }
  //update factors============================
    public static Node updateFactor(Node node){
        if(getBalance(node)>1){    //ll,lr
            if(getBalance(node.left)>0){   //ll
                node=rightRotation(node);
            }
            else{
                node.left=leftRotation(node.left);
                node=rightRotation(node);
            }
        }
        else if(getBalance(node)<-1){
            if(getBalance(node.right)<0){
                node=leftRotation(node);
            }
            else{
                node.right=rightRotation(node.right);
                node=leftRotation(node);
            }
        }
        return node;
    }

    public static Node rightRotation(Node node){
        Node n=node.left;
        Node temp=n.right;
        n.right=node;
        node.left=temp;
        updateFactor(node);
        updateFactor(n);
        return n;
    }
    public static Node leftRotation(Node node){
        Node n=node.right;
        Node temp=n.left;
        n.left=node;
        node.right=temp;
        updateFactor(node);
        updateFactor(n);
        return n; 
    }

    //adding elements===========================
    public static Node addData(Node node,int data){
        if(node==null){
            return new Node(data);
         
        }
        if(node.data<data){
            node.right=addData(node.right,data);
        }
        else{
            node.left=addData(node.left,data);
        }
        getFactor(node);
        node=updateFactor(node);
        return node;
    }

    
 public static Node deletenode(Node node,int val){
     if(node==null){
         return node;
     }
     if(node.data<val){
         node.right=deletenode(node.right,val);
     }
     else if(node.data>val){
         node.left=deletenode(node.left,val);
     }
     else{
      
    if(node.left==null && node.right==null){
        node=null;
        return node;
    }
    else if((node.left==null || node.right==null)){
      Node n=node.left!=null?node.left:node.right;
      return n;
    }

    Node node1=node;
    node1=node.left;

   while(node1.right!=null){
       node1=node1.right;
   }
   node.data=node1.data;
   node.left=deletenode(node.left,node1.data);
    
     }

        getFactor(node);
        node=updateFactor(node);
        return node;
 }
}