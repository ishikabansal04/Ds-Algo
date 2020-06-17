import java.util.ArrayList;
import java.util.LinkedList;

public class generictree{
    public static void main(String[]args){
        //int arr[]={10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,100,-1,110,-1,-1,120,-1,-1,130,-1,-1};
        // int arr[]={10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,-1,60,80,-1,70,-1,-1,-1,20,40,-1,30,-1,-1,-1};
        int arr[]={10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, -1, -1};
        Node root=construct(arr);
        //display(root);
       /*
        System.out.println( height(root));
        System.out.println(find(root,80));
        System.out.println(maximum(root));
        System.out.println(minimum(root));
        System.out.println(size(root));
        System.out.println(isFoldable(root,root));
       */

       /*
        ArrayList<Node>child=new ArrayList<>();
        flattern(root,child);
        child.remove(0);
        root.childs=child;
        display(root);
        */
        /*
        flattern_01(root);
        display(root);
         */
         /*
         flattern_02(root);
        display(root);
        */
        /*
        int arr1[]={10,30,-1,50,120,-1,40,110,-1,100,-1,-1,60,80,-1,70,-1,-1,-1,20,40,-1,30,-1,-1,-1};
        int arr2[]={10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,40,100,-1,110,-1,-1,120,-1,-1,30,-1,-1};
        Node root1=construct(arr1);
        Node root2=construct(arr2);
        System.out.println(mirrorimage(root1,root2));
        */
        /*
        flattern_01(root);
        removeLeaves(root);
        display(root);
        */
        // Node temp=linearize(root);
        // display(root);
        //linearise_01(root);
        PredSucc(root,30);
        // display(root);
    }

    public static class Node{
        int data=0;
        ArrayList<Node> childs=new ArrayList<>();
        
        Node(int data){
            this.data=data;
        }
    }

       
//construction of a tree============================
    public static Node construct(int[] arr){

        LinkedList<Node> st=new LinkedList<>();

        for(int i=0;i<arr.length-1;i++){
            if(arr[i]!=-1){
                 Node node=new Node(arr[i]);
                 st.addFirst(node);
            }
            else{
                Node rchild=st.removeFirst();
                st.getFirst().childs.add(rchild);
            }
        }

        return st.removeFirst();//at the end root is removed from stack.
}

//display=========================================
     public static void display(Node node){
         StringBuilder sb=new StringBuilder();
         sb.append(node.data+" -> [");
         for(Node child:node.childs){
             sb.append(child.data+" , ");
         }
         sb.append("]");
         System.out.println(sb.toString());

         for(Node child:node.childs){
             display(child);
         }
     }

//height====================================
  
    public static int height(Node node){
    int ht=-1;
    for(Node child:node.childs){
        int rech=height(child);
        ht=Math.max(rech,ht);
    }
    
return ht+1;
}

//find======================================

public static boolean find(Node node,int data){
    if(node.data==data)return true;
    boolean res=false;
    for(Node child:node.childs){
        res=res||find(child,data);
    }
    
return res;
}
//maximum==================================
public static int maximum(Node node){
    int max=node.data;
    for(Node child:node.childs){
        max=Math.max(maximum(child),max);
    }
    return max;
}

//minimum=================================
public static int minimum(Node node){
    int min=node.data;
    for(Node child:node.childs){
        min=Math.min(minimum(child),min);
    }
    return min;
}

//size======================================
public static int size(Node node){
    int size=0;
    for(Node child:node.childs){
        size+=size(child);
    }
    return size+1;
} 


//foldable tree============================

public static boolean isFoldable(Node node1,Node node2){
    if((node1==null && node2!=null)||(node1!=null && node2==null)){
        return false;
    }
    if(node1.childs.size()!=node2.childs.size()) return false;
    if(node1.data!=node2.data) return false;
    for(int i=0,j=node1.childs.size()-1;i<node1.childs.size();i++,j--){//moving in each node's respective child list.
        Node child1=node1.childs.get(i);
        Node child2=node2.childs.get(j);
      
        boolean res=isFoldable(child1,child2);
        if(!res) return false;
    }

    return true;
}

public static void flattern(Node node,ArrayList<Node>child){
    child.add(node);
    for(Node n:node.childs){
        flattern(n,child);
        
    }
    node.childs=new ArrayList<>();
}


public static void flattern_01(Node node){
    ArrayList<Node> ch=new ArrayList<>();
    for(Node n: node.childs){
        flattern_01(n);
        ch.add(n);
        ch.addAll(n.childs);

        n.childs=new ArrayList<>();//to empty this arraylist.
    }
    node.childs=ch;
}


public static void flattern_02(Node node){
    ArrayList<Node> ch=new ArrayList<>();
    for(Node n: node.childs){
        flattern_02(n);
        ch.add(n);
       for(int i=n.childs.size()-1;i>=0;i--){
           ch.add(n.childs.remove(n.childs.size()-1));
       }
    }
    node.childs=ch;
    }

    public static boolean mirrorimage(Node tree1,Node tree2){
        if(tree1.childs.size()!=tree2.childs.size()) return false;
        
        if(tree1.data!=tree2.data) return false;
        
        if((tree1==null && tree2!=null)||(tree1!=null && tree2==null)){
        return false;
    }
    for(int i=0,j=tree1.childs.size()-1;i<tree1.childs.size();i++,j--){
        Node child1=tree1.childs.get(i);
        Node child2=tree2.childs.get(j);
      
        boolean res=mirrorimage(child1,child2);
        if(!res) return false;
    }

    return true;

    }

    //remove leaf node=========================
    //operated in preorder from back!
    public static void removeLeaves(Node node){
        for(int i=node.childs.size()-1;i>=0;i--){
            Node child=node.childs.get(i);
            if(child.childs.size()==0){
                node.childs.remove(i);
                continue;
            }
            removeLeaves(child);
        }
    }

    //convert tree into linklist=============
    public static Node linearize(Node node){
        if(node.childs.size()==0){
            return node;
        }
        Node lastTail=linearize(node.childs.get(node.childs.size()-1));
        for(int i=node.childs.size()-1;i>0;i--){
            Node secondlastTail=linearize(node.childs.get(i-1));
            secondlastTail.childs.add(node.childs.remove(i));
        }
        return lastTail;
    }


//method 2=============(not optimised) complexity is O(n^2)
public static void linearise_01(Node node){
    for(Node child: node.childs){
        linearise_01(child);
    }
    while(node.childs.size()>1){
        Node slast=node.childs.get(node.childs.size()-2);
        Node last=node.childs.remove(node.childs.size()-1);

        Node slast_tail=gettail(slast);
        slast_tail.childs.add(last);
    }
}

public static Node gettail(Node node){
    Node tail=node;
    while(tail.childs.size()==1){
        tail=tail.childs.get(0);
    }
    return tail;
}

//optimised code for O(n)
public static Node linearise_02(Node node){// this function returns tail of a list----

if(node.childs.size()==0) return node; //this base case is req since next line can give exception if no base case
    Node otail=linearise_02(node.childs.get(node.childs.size()-1));   //original tail
    while(node.childs.size()>1){
        Node slast=node.childs.get(node.childs.size()-2);
        Node last=node.childs.get(node.childs.size()-2);

        Node slast_tail=linearise_02(slast);
        node.childs.remove(last);
        slast_tail.childs.add(last);
    }
    return otail;
}

public static class Heapmover{
    Node prev=null;
    Node curr=null;

    Node pred=null;
    Node succ=null;
}
public static void PredSucc(Node root,int data){
    Heapmover move=new Heapmover();
    move=predsucc(root,data);
    System.out.println(move.pred==null?null:move.pred.data);
    System.out.println(move.succ==null?null:move.succ.data);
}
public static Heapmover predsucc(Node node,int data){
   
    Heapmover mover=new Heapmover();
    mover.curr=node;
    if(mover.curr.data==data){
        mover.pred=mover.prev;
    }
    else if(mover.prev!=null && mover.prev.data==data){
        mover.succ=mover.curr;
    }
    mover.prev=mover.curr;
    
for(Node child: node.childs){
    predsucc(child,data);
}
return mover;
}
}