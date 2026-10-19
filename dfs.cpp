#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    
    public:
    Graph(int V){
        this->V = V;
        l= new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsTraversal(int curr, vector<bool> &vis){

        cout << curr <<" ";
        vis[curr]=true;

        for(int v: l[curr]){
            if(!vis[v]){
                dfsTraversal(v, vis);
            }
        }
    }

    void dfs(){
        int src = 0;
        vector<bool>vis(V, false);

        dfsTraversal(src, vis);
        cout<<endl; 
    }


};

int main(){
    int V, E;
    int u, v;

    cout << "Enter number of Vertex : ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of Edge: ";
    cin >> E;

    cout << "Enter Edges(u v): "<<endl;
    for(int i=0; i<E; i++){
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<"DFS Traversal: ";
    g.dfs();

    return 0;
    
}