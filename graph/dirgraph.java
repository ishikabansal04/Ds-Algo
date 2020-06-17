import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
 public class dirgraph{
    
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
 
 
    public static void main(String[] args){
        case1();
        display();
    }
 }