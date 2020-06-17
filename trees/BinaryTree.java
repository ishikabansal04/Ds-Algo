import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
public class BinaryTree{
    
    public static void main(String []args){
        int arr[]={10,20,40,80,- 1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
       // int arr[]={10,30,10,-1,20,-1,-1,40,-1,-1,80,50,60,-1,-1,-1,90};
        BinaryTree ob=new BinaryTree();
        Node idx=new Node(0,null,null);
        Node root=ob.construct(arr,idx);
/*
        int[] pre={10,20,40,50,60,30,70,90,80};
        int[] post={40,60,50,20,90,70,80,30,10};
        int[] in={40,20,60,50,10,70,90,30,80};
       
*/
        int[] pre={10,20,40,50,30,70,80};
        int[] post={40,50,20,70,80,30,10};
       // int[] in={40,20,60,50,10,70,90,30,80};
        //verified

        //display(root);
     
       // System.out.println(size(root));
       // System.out.println(height(root));

        //preOder(root);
       // System.out.println();
        
        //inOder(root);
        //System.out.println();

       // postOder(root);
        //System.out.println();

       //System.out.println(max(root));
       //System.out.println(min(root));  
       //System.out.println(find(root,50));


        ArrayList<Node> ans=new ArrayList<>();
       //System.out.println(rootToNodePath_01(root,110,ans));
       //for(Node node:ans){
       //    System.out.println(node.data+" ");

       //ans=rootToNodePath(root,100);
       //Collections.reverse(ans); //inbuilt function in Collection and binary search is also present
       //if(ans!=null){
       //for(Node node:ans){
      
       //System.err.println(node.data+ " ");}}
       //else
       //System.out.println("Empty Arraylist");

       //leafNodes(root);
       
        //levelOder_01(root);
        //levelOder_02(root);
        //levelOder_03(root);
       //levelOder_04(root);

       //System.out.println(LCA_01(root,40,50));
      // if(LCA_02(root,100,80)){
     // System.out.println(LCA.data);
    //}
    //else 
      //System.out.println(" not found");

    
     //System.out.println(Bst(root).countBst);
     //System.out.println(isBst_01(root));
     System.out.println(Diameter_01(root));
     //System.out.println(Diameter_02(root).d);

     //display(root);
     //System.out.println();
     //deleteLeaf(root,20);
     //display(root);

    //display(root);
    //System.out.println();
    //deleteLeaf_01(root,20);
    //display(root);

    //display(root);
    //System.out.println();
    //addLeaf_01(root,40,99,false);
    //display(root);
/*
    Node root=preIn(pre,in,0,8,0,8);
    display(root);
*/
/*
    Node root=postIn(post,in,0,8,0,8);
    display(root);
*/
/*
//for prepost only complete trees work .....therefore all single childs of previous ques is deleted from above array and new array is:
    Node root=prepost(post,pre,0,6,0,6);
    display(root);

*/

/*
    //traversing doubly link list in forward direction!..........
    DLL(root);
    Node itr=head;
    while(itr!=null){
        System.out.print(itr.data+" ");
        itr=itr.right;
    }
   System.out.println("\n");
   */
     //traversing doubly link list in forward direction!..........
    DLL(root);
    Node itr=prev1;
    while(itr!=null){
        System.out.print(itr.data+" ");
        itr=itr.left;
    }
    }


    public static class Node{
        public int data=0;
        private Node left=null;     
        private Node right=null;    
        
        public Node (int data,Node left,Node right){          
             this.data=data;        
             this.left=left;         
             this.right=right;       
        }
    }

    //display of a tree======================
        private static void display(Node node){
            if(node==null) return;

            StringBuilder sb=new StringBuilder();
            sb.append(node.left!=null?node.left.data:".");
            sb.append("->"+node.data+"<-");
            sb.append(node.right!=null?node.right.data:".");

            System.out.println(sb.toString());
            display(node.left);
            display(node.right);
        }
    
//construction of a tree============================
    public Node construct(int[] arr,Node idx){
        if(idx.data>=arr.length||arr[idx.data]==-1){
            idx.data++;
            return null;
        }
    Node node =new Node(arr[idx.data],null,null);
    idx.data++;
    node.left=construct(arr,idx);
    node.right=construct(arr,idx);
    return node;

}


//util................................
public static int size(Node node){
    if(node==null) return 0;
    return size(node.left)+size(node.right)+1;
}

//height of tree======================
public static int height(Node node){
 if(node==null) return 0;
return Math.max(height(node.left),height(node.right))+1;
}



//traversals.================================
public static void preOder(Node node){
 if(node==null) return ;
System.out.println(node.data+" ");
preOder(node.left);
preOder(node.right);
}

public static void postOder(Node node){
 if(node==null) return ;
 postOder(node.left);
 postOder(node.right);
 System.out.println(node.data+" ");
}

public static void inOder(Node node){
 if(node==null) return ;
 inOder(node.left);
 System.out.println(node.data+" ");
 inOder(node.right);

 
}

//max value==============================================
public static int max(Node node){
    if(node==null)
    return Integer.MIN_VALUE;
    return Math.max(max(node.left),Math.max(node.data,max(node.right)));

}

//min value=============================================
public static int min(Node node){
    if(node==null)
    return Integer.MAX_VALUE;
    return Math.min(min(node.left),Math.min(node.data,min(node.right)));
}

public static boolean find(Node node,int x){
    
    if(node==null) return false;
    if(node.data==x) return true;

    return find(node.left,x)||find(node.right,x);

}

//min path===================================

public static boolean rootToNodePath_01(Node root,int data,ArrayList<Node> path){
 if(root==null) return false;
 if(root.data==data) 
 {
 path.add(root);
 return true;}

 if(rootToNodePath_01(root.left,data,path)){
     path.add(root);
     return true;
 }
 if(rootToNodePath_01(root.right,data,path)){
     path.add(root);
     return true;
 }
 return false;
}

public static  ArrayList<Node> rootToNodePath(Node node,int data){
    if(node==null) return null;

    if(node.data==data){
        ArrayList<Node> base=new ArrayList<>();
        base.add(node);
        return base;
    }

    ArrayList<Node> leftans=rootToNodePath(node.left,data);
    if(leftans!=null){
        leftans.add(node);
        return leftans;
    }

    ArrayList<Node> rightans=rootToNodePath(node.right,data);
    if(rightans!=null){
        rightans.add(node);
        return rightans;
    }
      return null;//null returned coz leftans and rightans are already returned respectively in their blocks.,....if none of left or right then null returhned;

}

//print leafnodes===================================!
public static void leafNodes(Node node){
    if(node==null) return;
    if((node.left==null)&&(node.right==null)) 
    {
        System.out.println(node.data+" ");
        return;
    }
    leafNodes(node.left);
    leafNodes(node.right);
    

}


//level order traversal================================================
public static void levelOder_01(Node root){
LinkedList<Node> que=new LinkedList<>();
 que.addLast(root);
 while(!que.isEmpty()){
     Node node=que.removeFirst();
     System.out.print(node.data+" ");
     if(node.left!=null){
         que.addLast(node.left);
     }
     if(node.right!=null){
         que.addLast(node.right);
     }
 }
}



public static void levelOder_02(Node root){
LinkedList<Node> que=new LinkedList<>();
que.addLast(root);

while(!que.isEmpty()){
    int size=que.size();

    while(size-->0){
    Node node=que.removeFirst();
     System.out.print(node.data+" ");

    if(node.left!=null){
         que.addLast(node.left);
     }
     if(node.right!=null){
         que.addLast(node.right);}

    }
    System.out.println();
}
}


public static void levelOder_03(Node root){

  LinkedList<Node> que1=new LinkedList<>();  
  LinkedList<Node> que2=new LinkedList<>();
   
   que1.addLast(root);
   while(!que1.isEmpty()){
       Node node=que1.removeFirst();
       System.out.print(node.data+" ");
       
        if(node.left!=null){
         que2.addLast(node.left);
        }

        if(node.right!=null){
         que2.addLast(node.right);}

        if(que1.size()==0){
        System.out.println();
        LinkedList<Node>temp=new LinkedList<>();
        temp=que1;
        que1=que2;
        que2=temp;}


   }
}
//LCA=================================================
public static int LCA_01 (Node root,int data1,int data2){
    ArrayList<Node> path1=rootToNodePath(root,data1);
    ArrayList<Node> path2=rootToNodePath(root,data2);
    if(path1==null||path2==null){
        return 0;
    }
    Node ans=null;
    int i=path1.size()-1;
    int j=path2.size()-1;
    while(i>=0 && j>=0){
       if(path1.get(i).data==path2.get(j).data){
           ans=path1.get(i);
       }
       else {
           break;  //loop is breaked when we no more get coomon ancestor while moving from root to to node.
       }
       i--;
       j--; 
    }
    return ans.data;
}

static Node LCA=null;
public static boolean LCA_02(Node node,int data1,int data2){
    if(node==null) return false;

    boolean selfDone = node.data==data1 || node.data==data2;

    boolean left=LCA_02(node.left,data1,data2);
    if(LCA!=null) return true;

    boolean right=LCA_02(node.right,data1,data2);

    if((left && right)||(left && selfDone)||(right && selfDone))
    LCA=node;

    return left||right||selfDone;
}

//check if a tree is binary search tree========================!

 public static class pair {
     int max=Integer.MIN_VALUE;
     int min=Integer.MAX_VALUE;
     boolean isBst=true;
     int countBst=0;
 }
    
 
public static  pair Bst(Node node){
    if(node==null) return new pair();
    pair left=Bst(node.left);
    pair right=Bst(node.right);
    pair mypair=new pair();
    mypair.isBst=false;

    if(left.isBst && right.isBst && left.max<=node.data && right.min>=node.data){
        mypair.isBst=true;
       // mypair.countBst=left.countBst+right.countBst+1;
        mypair.countBst=1;
    }
     mypair.min=Math.min(node.data,Math.min(left.min,right.min));
     mypair.max=Math.max(node.data,Math.max(left.max,right.max));
     mypair.countBst+=left.countBst+right.countBst;
     return mypair;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
}

//BinarySearch sorted=====================================

static int prev=Integer.MIN_VALUE;
public static boolean isBst_01(Node curr){
    if(curr==null) return true;

    boolean left=isBst_01(curr.left);
    if(!left) return false;

    if(prev<curr.data) prev=curr.data;
    else return false;
    boolean right=isBst_01(curr.right);
    if(!right) return false;

    return true;
}

//Diameter========================================
public static int Diameter_01(Node node){
    if(node==null) return 0;      //n^2 complexity

    int lh=height(node.left);
    int rh=height(node.right);

    int ld=Diameter_01(node.left);
    int rd=Diameter_01(node.right);

    return Math.max(Math.max(ld,rd),lh+rh+1); //lh+rh+1 is the case when diameter is max considering both left and right subtrees
}

public static class pair_01{
    int h=0;
    int d=0;
}

public static pair_01 Diameter_02(Node node){
    if(node==null) return new pair_01();    //complexity o(n)

    pair_01 left=Diameter_02(node.left);
    pair_01 right=Diameter_02(node.right);

    pair_01 mypair=new pair_01();
    mypair.h=Math.max(left.h,right.h)+1;
    mypair.d=Math.max(Math.max(left.d,right.d),left.h+right.h+1);

    return mypair;
}

//deleting leaf node of a tree=====================================!
public static void deleteLeaf(Node node,int leaf){
    if(node==null) return ;

    if(node.left!=null && node.left.data==leaf) node.left=null;
    if(node.right!=null && node.right.data==leaf) node.right=null;

    deleteLeaf(node.left,leaf);
    deleteLeaf(node.right,leaf);

}

public static Node deleteLeaf_01(Node node,int leaf){
    if(node==null) return null;

    if(node.left==null && node.right==null && node.data==leaf) return null;

    node.left=deleteLeaf_01(node.left,leaf);
    node.right=deleteLeaf_01(node.right,leaf);

    return node;
}
/*
     //singlechild delete......................
     public static void singlechild(Node node,int val){
         if(node==null) return ;
         if(node.data==val){
         if(node.left==null && node.right!=null ){
                node.data=node.right.data;
                deleteleaf_01(node,node.data);
         }
         if(node.right==null && node.left!=null){
              node.data=node.left.data;
                deleteleaf_01(node,node.data);
         }
         }
         */


//adding a leaf node==============================
public static void addLeaf_01(Node node,int par,int leaf,boolean isLeft){
    if(node==null) return;

    if(node.data==par){
        if(isLeft) node.left=new Node(leaf,null,null);
        else node.right=new Node(leaf,null,null);
    }
    addLeaf_01(node.left,par,leaf,isLeft);
    addLeaf_01(node.right,par,leaf,isLeft);
}

//construct tree using inoder and preoder========================================
public static Node preIn(int[] pre,int[] in,int ps,int pe,int is,int ie)
{
    if(ps>pe || is>ie) return null;
    Node node=new Node(pre[ps],null,null);
    int idx=is;
    while(idx<=ie){
        if(in[idx]==pre[ps]) break;
        idx++;
    }
    /*
    //this foll loop can also be used in place of while loop.
    int idx=-1;
    for(idx=is;idx<=ie;idx++){
        if(pre[ps]==in[idx]){
            break;
        }
    }
    */
    int tne=idx-is;//to count total no of elements on left subtree in inorder array.

    node.left=preIn(pre,in,ps+1,ps+tne,is,idx-1);
    node.right=preIn(pre,in,ps+tne+1,pe,idx+1,ie);

    return node;
}

//to construct a tree using the given inorder and postorder traversals!...........................
public static Node postIn(int[] post,int[] in,int ps,int pe,int is,int ie){
     if(ps>pe || is>ie) return null;
    Node node=new Node(post[pe],null,null);
    int idx=is;
    while(idx<=ie){
        if(in[idx]==post[pe]) break;
        idx++;
    }
    int tne=idx-is;

    node.left=postIn(post,in,ps,ps+tne-1,is,idx-1);
    node.right=postIn(post,in,ps+tne,pe-1,idx+1,ie);

    return node;
}



//to construct a tree using the given preorder and postorder traversals!...........................

public static Node prepost(int[] post,int[] pre,int posts,int poste,int pres,int pree){
     if(posts==poste || pres==pree) return new Node(pre[pres],null,null);
     if(posts>poste || pres>pree){
         return null;
     }
    // System.out.println(posts+" "+poste+" "+pres+" "+pree);
    Node node=new Node(pre[pres],null,null);
    int idx=posts;
    while(idx<=poste){
        if(post[idx]==pre[pres+1]) break;
        idx++;
    }
    int tne=idx-posts;

    node.left=prepost(post,pre,posts,posts+tne,pres+1,pres+tne+1);
    node.right=prepost(post,pre,posts+tne+1,poste-1,pree-tne,pree);

    return node;
}

//how to convert a given tree into a doubly link list in inorder traversal!
static Node head=null;
static Node prev1=null;
public static void DLL(Node curr){
    if(curr==null) return;
    DLL(curr.left);
    if(head==null){
        head=curr;
    }
    else{
        curr.left=prev1;
        prev1.right=curr;
    }
    prev1=curr;
    DLL(curr.right);
}
}

