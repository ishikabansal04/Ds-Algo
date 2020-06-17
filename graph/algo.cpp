
//dijikstra algo
/*
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}


int findMinVertex(int *distance,bool *visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 ||distance[i]<distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

void dijkstra(int**edges,int n){
    int *distance=new int[n];
    bool * visited=new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++){
        int minvertex=findMinVertex(distance,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 &&!visited[j]){
                int dist=distance[minvertex]+edges[minvertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<< " ->  "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}
int main(){

    //taking inputs===========using adjacency matrix
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    cout<<endl;
    dijkstra(edges,n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete [] edges;
}
*/
//prims algo====================

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}


int findMinVertex(int *weights,bool *visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 ||weights[i]<weights[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}
void prims(int **edges,int n){
    int *parent=new int[n];
    int *weights=new int[n];
    bool *visited=new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    parent[0]=-1;
    weights[0]=0;
    for(int i=0;i<n;i++){
        int minvertex=findMinVertex(weights,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                if(edges[minvertex][j]<weights[j]){
                    weights[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
    }
}
int main(){

    //taking inputs===========using adjacency matrix
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    cout<<endl;
    prims(edges,n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete [] edges;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

// int *sizeoftree=new int[Edge.size()];

int findParent(int v,int *parent){  //recursive function
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}

// void Union(int pt1, int pt2,int *parent){
//     if(sizeoftree[pt1]<=sizeoftree[pt2]){
//         parent[pt1]=pt2;
//         sizeoftree[pt2]+=sizeoftree[pt1];
//     }
//     else{
//         parent[pt2]=pt1;
//         sizeoftree[pt1]+=sizeoftree[pt2];
//     }
// }
void kruskals(Edge*input,int n,int E){
    //sort input arr in asc order based on weights=======
    sort(input,input+E,compare);

    Edge*output=new Edge[n-1];
    
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int count=0;  // how many edges are inserted to mst
    int i=0;  //count of current edge
    while(count!=n-1){
        Edge currEdge=input[i];

// check if we can add this edge in mst or not
    int sourceParent=findParent(currEdge.source,parent);
    int destParent=findParent(currEdge.dest,parent);
    if(sourceParent!=destParent){
        output[count]= currEdge;
        count++;
        // Union(sourceParent,destParent,parent);
    }
        i++;
    }

    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest)
        cout<<output[i].source <<" "<< output[i].dest<<" "<<output[i].weight<<endl;
        else
        cout<<output[i].dest <<" "<< output[i].source<<" "<<output[i].weight<<endl;
    }
}
int main(){

    //taking inputs===========
    int n,E;
    cin>>n>>E;
    Edge* input=new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,E);
}*/