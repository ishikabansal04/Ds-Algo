
//prims algo==============================================
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;


public class algo{

public static Scanner scn=new Scanner(System.in);
public static ArrayList<Edge>[] graph=new ArrayList[7];
public static ArrayList<Edge>[] dgraph=new ArrayList[7];


    public static class Edge{
    
        int v=0;
        int w=0;

        Edge(){

        }
        Edge(int v,int w){
            this.v=v;
            this.w=w;
        }

    }

public static void case1(){
for(int i=0;i<graph.length;i++){
    graph[i]=new ArrayList<Edge>();
    dgraph[i]=new ArrayList<Edge>();
}
        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
}

public static void addEdge(int u,int v,int w){
    if(u<0 || v<0 || u>graph.length || v>graph.length) return ;

   
    graph[u].add(new Edge(v,w));
    graph[v].add(new Edge(u,w)); 
}

public static void addEdge2(int u,int v,int w){
    if(u<0 || v<0 || u>dgraph.length || v>dgraph.length) return ;

  //  kruskal_pq.add(new kpair(u,v,w));
    dgraph[u].add(new Edge(v,w));
    dgraph[v].add(new Edge(u,w)); 
}

public static void display(){
    for(int i=0;i<graph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<graph[i].size();j++){
            System.out.print("("+graph[i].get(j).v+","+graph[i].get(j).w+")");
        }
        System.out.println();
    }
}


public static void display2(){
    for(int i=0;i<dgraph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<dgraph[i].size();j++){
            System.out.print("("+dgraph[i].get(j).v+","+dgraph[i].get(j).w+")");
        }
        System.out.println();
    }
}

public static class primsPair implements Comparable<primsPair>{
     int vtx=0;  //vtx.
    int pvtx=0;  //perentVtx
    int wt=0;
    String psf="";

    primsPair(int vtx,int pvtx,int wt,String psf){
        this.vtx=vtx;
        this.pvtx=pvtx;
        this.wt=wt;
        this.psf=psf;
    }

@Override
public int compareTo(primsPair o){
    return this.wt-o.wt;
}
    
}

public static void Prims(){
    int src=0;
    boolean[] visited=new boolean[graph.length];

    PriorityQueue<primsPair> pq=new PriorityQueue<>();
    pq.add(new primsPair(src,-1,0,""));

    while(!pq.isEmpty()){
        primsPair rpair=pq.remove();
        
        if(visited[rpair.vtx]) continue;

        if(rpair.pvtx!=-1) addEdge2(rpair.vtx,rpair.pvtx,rpair.wt);
        
        visited[rpair.vtx]=true;
        for(Edge e:graph[rpair.vtx]){
            if(!visited[e.v]){
                pq.add(new primsPair(e.v,rpair.vtx,e.w,rpair.psf+" "+e.v));
            }
        }
    } display2();
}


    public static void main(String[]args){
        case1();
        display();
        System.out.println();
        Prims();
    }

}



//kruskal's algo=================================
/*
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;


public class algo{

public static Scanner scn=new Scanner(System.in);
public static ArrayList<Edge>[] graph=new ArrayList[7];
public static ArrayList<Edge>[] dgraph=new ArrayList[7];
public static PriorityQueue<kpair> kruskal_pq=new PriorityQueue<>();

    public static class Edge{
    
        int v=0;
        int w=0;

        Edge(){

        }
        Edge(int v,int w){
            this.v=v;
            this.w=w;
        }

    }

public static void case1(){
for(int i=0;i<graph.length;i++){
    graph[i]=new ArrayList<Edge>();
    dgraph[i]=new ArrayList<Edge>();
}
        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
}

public static void addEdge(int u,int v,int w){
    if(u<0 || v<0 || u>graph.length || v>graph.length) return ;

    kruskal_pq.add(new kpair(u,v,w));
    graph[u].add(new Edge(v,w));
    graph[v].add(new Edge(u,w)); 
}

public static void addEdge2(int u,int v,int w){
    if(u<0 || v<0 || u>dgraph.length || v>dgraph.length) return ;

  //  kruskal_pq.add(new kpair(u,v,w));
    dgraph[u].add(new Edge(v,w));
    dgraph[v].add(new Edge(u,w)); 
}

public static void display(){
    for(int i=0;i<graph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<graph[i].size();j++){
            System.out.print("("+graph[i].get(j).v+","+graph[i].get(j).w+")");
        }
        System.out.println();
    }
}


public static void display2(){
    for(int i=0;i<dgraph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<dgraph[i].size();j++){
            System.out.print("("+dgraph[i].get(j).v+","+dgraph[i].get(j).w+")");
        }
        System.out.println();
    }
}

public static int[] par=new int[graph.length];
public static int[] size=new int[graph.length];

public static class kpair implements Comparable<kpair>{
     int u=0;  //vtx.
    int v=0;  //perentVtx
    int w=0;
    //String psf="";

    kpair(int u,int v,int w){
        this.u=u;
        this.v=v;
        this.w=w;
       // this.psf=psf;
    }

@Override
public int compareTo(kpair o){
    return this.w-o.w;
}
    
}

public static int find(int vtx){
    if(par[vtx]!=vtx) {
        par[vtx]=find(par[vtx]);
        }
        return vtx;
}

public static void Union(int pt1,int pt2){
    if(size[pt1]<=size[pt2]){
        par[pt1]=pt2;
        size[pt2]+=size[pt1];
    }
    else{
           par[pt2]=pt1;
        size[pt1]+=size[pt2];
    }
}

public static void kruskals(){
    for(int i=0;i<par.length;i++){
        par[i]=i;
        size[i]=1;
    }

    while(!kruskal_pq.isEmpty()){
        kpair rpair=kruskal_pq.remove();
        int pt1=find(rpair.u);
        int pt2=find(rpair.v);
        if(pt1!=pt2){
            addEdge2(rpair.u,rpair.v,rpair.w);
            Union(pt1,pt2);
        }
    }
    display2();
}
    public static void main(String[]args){
        case1();
        display();
        System.out.println();
        kruskals();
    }

}

*/
//Articulation point====================================
/*
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;


public class algo{

public static Scanner scn=new Scanner(System.in);
public static ArrayList<Edge>[] graph=new ArrayList[7];

    public static class Edge{
    
        int v=0;
        int w=0;

        Edge(){

        }
        Edge(int v,int w){
            this.v=v;
            this.w=w;
        }

    }

public static void case1(){
for(int i=0;i<graph.length;i++){
    graph[i]=new ArrayList<Edge>();
    
}
        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
}

public static void addEdge(int u,int v,int w){
    if(u<0 || v<0 || u>graph.length || v>graph.length) return ;

   
    graph[u].add(new Edge(v,w));
    graph[v].add(new Edge(u,w)); 
}


public static void display(){
    for(int i=0;i<graph.length;i++){
        System.out.print(i+" => ");
        for(int j=0;j<graph[i].size();j++){
            System.out.print("("+graph[i].get(j).v+","+graph[i].get(j).w+")");
        }
        System.out.println();
    }
}


public static int[] par=new int[graph.length]; //parent of each node================
public static int[] low=new int[graph.length]; //lowest time array==================
public static int[] dis=new int[graph.length]; //discovery time array===============
public static boolean[] points=new boolean[graph.length];

public static int time=0;
public static int root=0;
/*
public static void AP(int vtx,int parent){
    dis[vtx]=low[vtx]=time++;

    for(Edge e:graph[vtx]){
        if(dis[e.v]==-1){
            par[e.v]=vtx;

            if(parent ==-1) root++;
            AP(e.v,vtx);
            if(dis[vtx]<=low[e.v]){
                points[vtx]=true;
            }

            low[vtx]=Math.min(low[vtx],low[e.v]);

        }else if(parent!=e.v){
            low[vtx]=Math.min(low[vtx],dis[e.v]);
        }
    }
}
*/
/*
public static void bridgeAP(int vtx,int parent){
    dis[vtx]=low[vtx]=time++;

    for(Edge e:graph[vtx]){
        if(dis[e.v]==-1){
            par[e.v]=vtx;

            if(parent ==-1) root++;
            bridgeAP(e.v,vtx);
            if(dis[vtx]<low[e.v]){
                points[vtx]=true;
            }

            low[vtx]=Math.min(low[vtx],low[e.v]);

        }else if(parent!=e.v){
            low[vtx]=Math.min(low[vtx],dis[e.v]);
        }
    }
}
*/

//   public static void main(String[]args){
//         case1();
//        // display();
//         System.out.println();

//           Arrays.fill(dis,-1);
//         root=0;
//         AP(0,-1);
//         points[0]=root>1?true:false;

//         for(int i=0;i<graph.length;i++){
//             if(points[i])
//             System.out.println(i);
//         }

/*
  bridgeAP(0,-1);
        points[0]=root>1?true:false;

        for(int i=0;i<graph.length;i++){
            if(points[i])
            System.out.println(i);
        }
    }

}*/