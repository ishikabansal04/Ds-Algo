#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Edge{ //basically a pair cls to store final vtx and weight of edge corresponding to every initial vtx
    public:
    int v=0;
    int w=0;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};

vector<vector<Edge*>>edges(7,vector<Edge*>());
void AddEdge(int u,int v,int w){
    edges[u].push_back(new Edge(v,w));
    edges[v].push_back(new Edge(u,w));
}

void RemoveEdge(int u,int v){
    for(int i=0;i<edges[u].size();i++){
        if(edges[u][i]->v==v){
            edges[u].erase(edges[u].begin()+i);
            break;
        }
    }
    for(int i=0;i<edges[v].size();i++){
        if(edges[v][i]->v==u){
            edges[v].erase(edges[v].begin()+i);
            break;
        }
    }
}
void RemoveVertex(int u){
    for(int i=edges[u].size()-1;i>=0;i--){
        Edge *e=edges[u][i];
        RemoveEdge(u,e->v);
    }
    // edges.erase(edges.begin()+u);
}

void display(){
    for(int i=0;i<edges.size();i++){
        cout<<i<<"=>{ ";
        for(int j=0;j<edges[i].size();j++){
            cout<<edges[i][j]->v<<":"<<edges[i][j]->w<<", ";
        }
        cout<<"}"<<endl;
    }
}

void DFS(vector<bool>&isVis,int src){    //"&" is very imp else it will make elements false again n again
    if(isVis[src]){
        return;
    }
    cout<<src<<" ";
    isVis[src]=true;
    for(Edge *e:edges[src]){
        int v=e->v;
        // if(v==src)continue;
        if(!isVis[v]){
            DFS(isVis,v);
        }
    }
}

void BFS(int src){
    queue<int>que;
    vector<bool>Vis(7,false);
    que.push(src);
    Vis[src]=true;
    while(que.size()!=0){
        int rn=que.front();
        que.pop();
        cout<<rn<<" ";
        for(Edge *e:edges[rn]){
            int v=e->v;
            if(!Vis[v]){
                que.push(v);
            }
            Vis[v]=true;
        }
    }
}

void hasPath(int src,int dest,vector<bool>&isVis){
    
}

int main(){
    AddEdge(0,1,10);
     AddEdge(1,2,10);
      AddEdge(2,3,40);
       AddEdge(0,3,10);
        AddEdge(3,4,2);
         AddEdge(4,5,2);
          AddEdge(4,6,8);
        //   RemoveEdge(3,4);
        //   RemoveVertex(4);
        vector<bool>isVis(7,false);
 display();
//  DFS(isVis,0);
 BFS(0);
    return 0;
}