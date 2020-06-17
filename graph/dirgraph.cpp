#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class edge{
    public:
    int v=0;
    int w=0;
    edge(int v,int w){
        this->v=v;
        this->w=w;
    }
    edge(){

    }
};

//vector<vector<edge *>> graph(7,vector<edge *>());
vector<vector<edge *>> graph;
int incoming[7];

void addedge(int u,int v,int w){
    if(u<0||v<0||u>graph.size()||v>graph.size())
    return;

    graph[u].push_back(new edge(v,w));
    incoming[v]++;
   // graph[v].push_back(new edge(u,w));
}

void display(){
     for(int i=0;i<graph.size();i++){
           cout<<i<<"=>";
           for(int j=0;j<graph[i].size();j++){
               cout<<"("<<graph[i][j]->v<<","<<graph[i][j]->w<<")";
           }
           cout<<endl;
       }
}

//topological sort=======================
bool tsort(int src,vector<int>& st,vector<bool>& visited,vector<bool>& cycle){
     visited[src]=true;
      cycle[src]=true;
      bool res;
    for(edge* e:graph[src]){
       
         int v=e->v;
          if(!visited[v])
            res = res || tsort(e->v,st,visited,cycle) ;
          else if(cycle[v])
            return true;
    }

    cycle[src]=false;
    st.push_back(src);
    return res;
}

void tsort_(){
 vector<int> st;
 vector<bool> cycle(graph.size(),false);
  vector<bool> visited(graph.size(),false);
  bool res = false;

 for(int i=0;i<graph.size() && !res;i++){
     if(!visited[i])
  res = res || tsort(i,st,visited,cycle);
 }

 for(int i=st.size()-1 ;i>=0 && !res;i--){
     cout<<st[i]<<" ";
 }
 cout<<endl;
}

//khaans algo=============================
list<int> zerodeg;

void incomdeg(list<int>& zerodeg,vector<bool>& vis){
    for(int i=0;i<graph.size();i++){
        if(!vis[i]&&incoming[i]==0){
        zerodeg.push_back(i);
        vis[i]=true;
        }
    }
}

void khaans(){
    vector<bool> vis(graph.size(),false);
    incomdeg(zerodeg,vis);
    while(zerodeg.size()>0){

    int zero=zerodeg.front();
    zerodeg.pop_front();

    for(edge* e:graph[zero]){
        int v=e->v;
        incoming[v]-=1;
            }
    incomdeg(zerodeg,vis);
    cout<<zero<<" ";
    }

}

void solve(){
    for(int i=0;i<7;i++){
        vector<edge *>ar;
        graph.push_back(ar);
    }
    for(int i=0;i<graph.size();i++){
    incoming[i]=0;
}
       
       addedge(0,1,10);
       addedge(0,3,10);
    //    addedge(3,0,10);
       addedge(1,2,10);
       addedge(2,3,40);
       addedge(3,4,2);
       addedge(4,5,2);
      // addedge(5,2,10);
       addedge(5,6,8);
       addedge(4,6,3);
      
       //display();
      // tsort_();
      khaans();
}

int main(){
    solve();
    return 0;
}