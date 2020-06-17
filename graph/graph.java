import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;

public class graph{

    public static Scanner scn=new Scanner(System.in);
    static ArrayList<Edge>[] graph=new ArrayList[7];
    //static ArrayList<ArrayList<Edge>>graph = new ArrayList<ArrayList>>();
    
    public static class Edge{
        int v=0;
        int w=0;
        Edge(int v,int w){
            this.v=v;
            this.w=w;
        }
        Edge(){

        }
    }

public static void addEdge(int u,int v,int w){
        if(u<0 || v<0 || u>=graph.length || v>=graph.length)
        return;
        graph[u].add(new Edge(v,w));
        graph[v].add(new Edge(u,w));
    }


    public static void case1(){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<Edge>();
        }
        addEdge(0,1,10);
        addEdge(0,3,10);      
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,12);
        addEdge(4,5,2);
        addEdge(5,6,3);
        addEdge(4,6,8);

    }

   /* public static void case2(){
        for(int i=0;i<7;i++){
            graph.add(new ArrayList<Edge>());
        }
    }
*/
public static void display(){
    for(int i=0;i<graph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<graph[i].size();j++){
       System.out.print("("+ graph[i].get(j).v+ ","+graph[i].get(j).w+")");
        } System.out.println(); 
    }
} 

public static void deleteEdge(int s,int e){
    
    for(int i=0;i<graph.length;i++){
        if(i==s){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i].get(j).v==e)
                graph[i].remove(j);
                
            }
        }
        if(i==e){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i].get(j).v==s)
                graph[i].remove(j);
            }
        }
    }
}


    public static void removeVertex(int u){
  
        for(int i=graph[u].size()-1;i>-1;i--){
            deleteEdge(graph[u].get(i).v,u);
        }
      
    }


//bfs===================================
public static class pair{
    int ve=0;
    String psf=" ";
    int wsf=0;
    pair(){

    }
    pair(int ve,int wsf,String psf){
        this.ve=ve;
        this.psf=psf;
        this.wsf=wsf;
    }
}
public static void  bfs_path(int src,int des){
 LinkedList<pair> que=new LinkedList<>();

 pair root=new pair(src,0,src+"");
 que.addLast(root);

 boolean[] vis=new boolean[graph.length];

  int countercycle=0;
  boolean ispaath=false;

while(!que.isEmpty()){
    pair rem=que.removeFirst();
    if(vis[rem.ve]){
    System.out.println("cycle:"+countercycle+"("+rem.psf+" @ "+rem.wsf+")");
    countercycle++;
    }

    vis[rem.ve]=true;
    if(rem.ve==des&&!ispaath){
        System.out.println(rem.psf);
        ispaath=true;
    }

    for(Edge e:graph[rem.ve]){
        if(!vis[e.v]){
            pair p=new pair(e.v,rem.wsf+e.w,rem.psf+"->"+e.v);
            que.addLast(p);
        }
    }
}

}

//method 1(length of path)=======================

public static void  bfs_path01(int src,int des){
 LinkedList<pair> que=new LinkedList<>();

 pair root=new pair(src,0,src+"");
 que.addLast(root);
 que.addLast(null);

 boolean[] vis=new boolean[graph.length];

  int countercycle=0;
  boolean ispaath=false;
  int level=0;

while(que.size()!=1){
    pair rem=que.removeFirst();
    if(vis[rem.ve]){
    System.out.println("cycle:"+countercycle+"("+rem.psf+" @ "+rem.wsf+")");
    countercycle++;
    }

    vis[rem.ve]=true;
    if(rem.ve==des&&!ispaath){
        System.out.println(rem.psf+" @ "+level);
        ispaath=true;
    }

    for(Edge e:graph[rem.ve]){
        if(!vis[e.v]){
            pair p=new pair(e.v,rem.wsf+e.w,rem.psf+"->"+e.v);
            que.addLast(p);
        }
    }

    if(que.getFirst()==null){
        que.removeFirst();
        que.addLast(null);
        level++;
    }
}

}


//method 2(length of path)------------------------------

public static int bfs_path02(int src,int des,boolean[] vis){
 LinkedList<pair> que=new LinkedList<>();

 pair root=new pair(src,0,src+"");
 que.addLast(root);

 //boolean[] vis=new boolean[graph.length];

  int countercycle=0;
  boolean ispaath=false;
  int level=0;

while(!que.isEmpty()){
 int size=que.size();

 while(size!=0){
    pair rem=que.removeFirst();
    if(vis[rem.ve]){
    System.out.println("cycle:"+countercycle+"("+rem.psf+" @ "+rem.wsf+")");
    countercycle++;
    }
 
    vis[rem.ve]=true;
    if(rem.ve==des&&!ispaath){
        System.out.println(rem.psf+" @ "+level);
        ispaath=true;
    }

    for(Edge e:graph[rem.ve]){
        if(!vis[e.v]){
            pair p=new pair(e.v,rem.wsf+e.w,rem.psf+"->"+e.v);
            que.addLast(p);
        }
    }
    size--;
 }
 level++;
}
return countercycle;
}

//method 1 for no of disconnected components-----------------------

static String ans="";
static int countcycles=0;
static boolean[] visited=new boolean[graph.length];

public static int disconnected(int src){
     for(int i=0;i<graph.length;i++){
         visited[i]=true;
         boolean flag=false;
         ans=ans+i+" -> ";
          for(int j=0;j<graph[i].size();j++){
                if(!visited[graph[i].get(j).v]){
                    //ans = ans+graph[i].get(j).v+" -> ";
                    flag=true;
                }
               
            }
            if(flag==false){
                System.out.println(ans);
                ans="";
                countcycles++;
            }

     }
     return countcycles;
}



public static class colour{
    int vtx=0;
    int col=-1;
    colour(){
    }

    colour(int vtx,int col){
        this.vtx=vtx;
        this.col=col;
    }
} 
public static void isbipartite(int src){
    LinkedList<colour> que=new LinkedList<>();
    int[] arr=new int[graph.length];
    
    for(int i=0;i<graph.length;i++){
        arr[i]=-1;
    }

 colour root=new colour(src,0);
 que.addLast(root);
 arr[0]=0;
 boolean[] vis=new boolean[graph.length];

 int level=0;
boolean ispaath=false;


while(!que.isEmpty()){
 int size=que.size();

   while(size!=0){
    colour rem=que.removeFirst();

    vis[rem.vtx]=true;
   
    for(Edge e:graph[rem.vtx]){
        if(!vis[e.v]){
            if(rem.col==0){
            colour c=new colour(e.v,1);
            if(arr[rem.col]==-1) arr[rem.col]=1;
            else if(arr[rem.col]==0) {System.out.println("Not bipartite"); break;}
            
            que.addLast(c);
            }
            else{
               colour c=new colour(e.v,0);
              if(arr[rem.col]==-1)  arr[rem.col]=0;
                else if(arr[rem.col]==1) {System.out.println("Not bipartite"); break;}
            
            que.addLast(c);
            }
        }
    }
    size--;
 }
 level++;
}

}

//to check whether graph is tree or not.......cycle:0 & gcc:1=========
public static void istree(int src){
    boolean[] vis=new boolean[graph.length];
     int gcc=disconnected(src);
     int cycle=bfs_path02(src,graph.length,vis);
     System.out.println("gcc: "+gcc+" cycle: "+cycle);
    
     if(cycle==0&&gcc==1)
      System.out.println(" IS A TREE AND CONNECTED ..");
    else
      System.out.println(" NOT A TREE ..");
 }



//method 2....................
//(inside main for loop)!


    public static void main(String[] args){
        case1();
       // display();
        /*
        deleteEdge(3,2);
        System.out.println();
        display();
        */
/*
        removeVertex(3);
        System.out.println();
        display();
*/
/*
        bfs_path(0,6);
         System.out.println();
        bfs_path01(0,6);
         System.out.println();
        bfs_path02(0,6);
*/
/* //method 1 for disconnected========
disconnected(0);
System.out.println(countcycles);
*/

  //method 2 for disconnected components------------------
int comp=0;
boolean[] vis=new boolean[graph.length];
      for(int i=0;i<graph.length;i++){
          if(!vis[i]){
              bfs_path02(i,6,vis);
              comp++;
          }
      }
      System.out.println(" No of components "+comp);

// isbipartite(0);   
 
//istree(0);
 }
}
