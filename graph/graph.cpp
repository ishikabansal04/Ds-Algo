#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;    

//class......

 class Edge{
     public:
        int v=0;
        int w=0;
        Edge(int v,int w){
            this->v=v;
            this->w=w;
        }
        Edge(){
        }
    };


//to store edges of each vertex...........

//vector<vector<Edge*>>graph(7,vector<Edge*>());
vector<vector<Edge *>>graph;


//adding edges.............
void addEdge(int u,int v,int w){
        if(u<0 || v<0 || u>=graph.size() || v>=graph.size())
        return;
        graph[u].push_back(new Edge(v,w));
        graph[v].push_back(new Edge(u,w)); //to make edges bidirectional edge is added to vector list of both u and v.
    }


//display graph.............
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" => ";
        for(int j=0;j<graph[i].size();j++){
       cout<<"("<< graph[i][j]->v<< ","<<graph[i][j]->w<<")";
        } 
        cout<<endl; 
    }
} 
    

//remove edge..................
    void removeEdge(int u,int v){
        int i=-1;
        int j=-1;
        for(int k=0;k<graph[u].size();k++){
            if(graph[u][k]->v==v){
                i=k;
                break;
            }
        }
         for(int k=0;k<graph[v].size();k++){
            if(graph[v][k]->v==u){
                j=k;
                break;
            }
        }

        graph[u].erase(graph[u].begin()+i);
        graph[v].erase(graph[v].begin()+j);
    }


//remove vertex................
    void removeVertex(int u){
        for(int i=graph[u].size()-1;i>=0;i--){
            removeEdge(graph[u][i]->v,u);
        }
    }

//DFS print......................    
void DFS(int sv,vector<bool>& visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(Edge *e:graph[sv]){
        int v=e->v;
        if(v==sv) continue;
        if(!visited[v])
        DFS(v,visited);
    }
}

void BFS(int src,vector<bool>&visited){
    list<int>que;
    que.push_back(src);
    visited[src]=true;
    while(que.size()!=0){
        int rv=que.front();
        que.pop_front();
        cout<<rv<<endl;
       
        for(Edge*e:graph[rv]){
            int v=e->v;
            if(!visited[v]){
                que.push_back(v);
                 visited[v]=true;
            }
        }
    }
}

int ConnectedComponents(){
    int count=0;
    vector<bool>visited(graph.size()-1,false);
  
    for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            DFS(i,visited);
            count+=1;
            cout<<endl;
        }
    }
    return count;
}


int BFScyclecounter(int src,vector<bool>&visited){
    list<int>que;
    int cycles=0;
    que.push_back(src);
    // visited[src]=true;
    while(que.size()!=0){
        int rv=que.front();
        que.pop_front();
        // cout<<rv<<endl;
        if(visited[rv]){
            cycles++;
        }
           visited[rv]=true;
        for(Edge*e:graph[rv]){
            int v=e->v;
            if(!visited[v]){
                que.push_back(v);
              
            }
        }
    }
    return cycles;
}

bool isTree(int src){
    vector<bool>visited(graph.size(),false);
    int gcc=ConnectedComponents();
    int cycles=BFScyclecounter(src,visited);
    if(cycles==0 && gcc==1){
        return true;
    }
    return false;
}

bool isForest(int src){
    vector<bool>visited(graph.size(),false);
    int gcc=ConnectedComponents();
    int cycles=BFScyclecounter(src,visited);
    if(cycles==0 && gcc>1){
        return true;
    }
    return false;
}

//haspath(1 random path)................
    bool hasPath(int src,int des,vector<bool>& visited,string ans){
        if(src==des){
            cout<<ans<<endl;
            return true;
        }
        visited[src]=true;
        bool res=false;
        for(Edge *e:graph[src]){
            int v=e->v;
            if(!visited[v]){

                res=res||hasPath(v,des,visited,ans+to_string(v)+"->");
            }
        }
        return res;
    }


//all possible paths......................
     void allPath(int src,int des,vector<bool>& visited,string ans){
        if(visited[src]) return;
        if(src==des){
            cout<<ans<<endl;
            return;
        }
        visited[src]=true;
        for(Edge *e:graph[src]){
            int v=e->v;
            allPath(v,des,visited,ans+to_string(v)+"->");

        }
        visited[src]=false;
    }
    
    
//preorder traversal of graph...........    
    void preOrderPath(int src,vector<bool>& visited,string ans){        
        
        visited[src]=true;

        cout<<to_string(src)+ " -> "+ans +to_string(src)<<endl; //this would just print like src -> src and would not add src to our ans!
        for(Edge *e:graph[src]){
            int v=e->v;
            if(!visited[v])
            preOrderPath(v,visited,ans+to_string(src));  //this is req to add src to our previous ans......

        }
        visited[src]=false;
    }

 //postorder traversal...............
    void postOrderPath(int src,vector<bool>& visited,string ans){
        
        visited[src]=true;
        for(Edge *e:graph[src]){
            int v=e->v;
            if(!visited[v])
            postOrderPath(v,visited,ans+to_string(src));

        }
          cout<<to_string(src)+ " -> "+ans +to_string(src)<<endl;
        visited[src]=false;
    }


//to print weights of all paths..................
  void Pathnweight(int src,int w,vector<bool>& visited,string ans){
        
        visited[src]=true;

        cout<<to_string(src)+ " -> "+ans +to_string(src)+" @ "+ to_string(w)<<endl;
        for(Edge *e:graph[src]){
            int v=e->v;
            int wt=e->w;
            if(!visited[v])
            Pathnweight(v,w+wt,visited,ans+to_string(src));

        }
        visited[src]=false;
    }

// to get lightest weight method 1(in source to dest)..............  
class Pair_path{
    public:
    int wt=100000;
    string s=" ";
    Pair_path(int wt,string s){
        this->wt=wt;
        this->s=s;

    }
    Pair_path(){

    }
};
Pair_path * lightestweight(int src,int des,vector<bool>&visited){
    if(src==des){
        Pair_path* obj=new Pair_path(0,to_string(src)+" ");
        return obj;
    }
    visited[src]=true;
    Pair_path* myans=new Pair_path();
    for(Edge *e:graph[src]){
        int nbr=e->v;
        int w=e->w;
        if(!visited[nbr]){
            Pair_path *recans=lightestweight(nbr,des,visited);
            if(recans->wt+w< myans->wt){
                myans->wt=recans->wt+w;
                myans->s=to_string(src)+" "+recans->s;
            }
            }
    }
    visited[src]=false;
    return myans;

}


//to get lightest weight method 2 in source to destination....................
    int fwt=100000;
    string fans="";
    void lightestweight_01(int src,int des,vector<bool>& visited,int wt,string ans){
        if(src==des){
            if(wt<fwt){
                fwt=wt;
                fans=to_string(src)+ans;
            }
            return;
        }

        visited[src]=true;
        for(Edge *e:graph[src]){
            int nbr=e->v;
            int w=e->w;
            if(!visited[nbr]){
                lightestweight_01(nbr,des,visited,w+wt,ans+to_string(nbr));
            }
        }
        visited[src]=false;
    }


//to get heaviest weight method1 from source to dest.............................
    class Pair_path2{
    public:
    int wt=0;
    string s=" ";
    Pair_path2(int wt,string s){
        this->wt=wt;
        this->s=s;

    }
    Pair_path2(){

    }
};
Pair_path2 * heaviestweight(int src,int des,vector<bool>&visited){
    if(src==des){
        Pair_path2* obj=new Pair_path2(0,to_string(src)+" ");
        return obj;
    }
    visited[src]=true;
    Pair_path2* myans=new Pair_path2();
    for(Edge *e:graph[src]){
        int nbr=e->v;
        int w=e->w;
        if(!visited[nbr]){
            Pair_path2 *recans=heaviestweight(nbr,des,visited);
            if(recans->wt+w> myans->wt){
                myans->wt=recans->wt+w;
                myans->s=to_string(src)+" "+recans->s;
            }
            }
    }
    visited[src]=false;
    return myans;

}

//to get heaviest weight method 2 from source to dest.........................
  int fwt2=0;
    string fans2="";
    void heaviestweight_01(int src,int des,vector<bool>& visited,int wt,string ans){
        if(src==des){
            if(wt>fwt2){
                fwt2=wt;
                fans2=to_string(src)+ans;
            }
            return;
        }

        visited[src]=true;
        for(Edge *e:graph[src]){
            int nbr=e->v;
            int w=e->w;
            if(!visited[nbr]){
                heaviestweight_01(nbr,des,visited,w+wt,ans+to_string(nbr));
            }
        }
        visited[src]=false;
    }



//hamiltonian path/cycle..........................
  void hamiltonian(int src,int osrc,int cnt,int wt,vector<bool>&visited,string ans){
      if(cnt=graph.size()-1){
          cout<<ans+to_string(src);
          for(Edge *e:graph[src]){
              if(e->v==osrc){
                  cout<<" -> Cycle "<<endl;
              }
          }
          cout<<endl;
      }

      visited[src]=true;
      for(Edge *e:graph[src]){
          int nbr=e->v;
          int w=e->w;
          if(!visited[nbr]){
              hamiltonian(nbr,osrc,cnt+1,wt+w,visited,ans+to_string(src));
          }
      }
      visited[src]=false;
  }

class color{
    public:
    int vtx=0;
    int col=0;
    color(){};
    color(int vtx,int col){
        this->vtx=vtx;
        this->col=col;
    }
};

bool bipartite(int src,vector<int>& vis){
     list<color> que;

     que.push_back(color(src,0));
     bool res=true;

     while(que.size()>0){
       color rem=que.front();
       que.pop_front();

       if(vis[rem.vtx]!=-1){
           if(vis[rem.vtx]!=rem.col){
               cout<<rem.vtx<<"->"<<"Not bipartite"<<endl;
               res=false;
           }
          
       }

       vis[rem.vtx]=rem.col;
       for(Edge* e:graph[rem.vtx]){
           if(vis[e->v]==-1){
               color npair(e->v,(rem.col+1)%2);
               que.push_back(npair);
           }
       }
     }
    return res;
 }

//to check whether graph is tree or not.......cycle:0 & gcc:1=========
 
 

//solve......................
void solve(){
    //this for loop only when we are not giving size on top !by this we are giving vector graph the initial 7 values that r nothing else but 7 different vector lists.
    for(int i=0;i<7;i++){
        vector<Edge*>ar;
        graph.push_back(ar);
    }

        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
              
             
     vector<bool>visited(graph.size(),false);
//    DFS(0,visited);
//    BFS(0,visited);
//    cout<<ConnectedComponents();
//    cout<<BFScyclecounter(0,isVisited);
//    cout<<isTree(0);
    cout<<isForest(0);
//    hasPath(0,6,visited,to_string(0)+"->");
//    allPath(0,6,visited,to_string(0)+"->");
//    preOrderPath(0,visited," ") ; 
//    postOrderPath(0,visited," ") ;      
//    Pathnweight(0,0,visited," ") ;
  /*
  Pair_path* ans=lightestweight(0,6,visited);
  cout<<ans->s<<" -> "<<ans->wt<<endl; 
  */
  /*
  lightestweight_01(0,6,visited,0,"");   
  cout<<fans<< " @ "<<fwt<<endl;
  */
  /*
  Pair_path2* ans=heaviestweight(0,6,visited);
  cout<<ans->s<<" -> "<<ans->wt<<endl; 
  */
  /*
  heaviestweight_01(0,6,visited,0,"");   
  cout<<fans2<< " @ "<<fwt2<<endl;
  */
  //  hamiltonian(0,0,0,0,visited,"");
  /*
  vector<int>vis(7,0);
  cout<<(boolalpha)<< bipartite(0,vis)<<endl;
  */
 
}



//main.......................................................
 int main(){
        solve();
        //display();
        cout<<endl;
        /*removeEdge(3,2);
        display();*/

        removeVertex(3);
        display();
        return 0;
    }