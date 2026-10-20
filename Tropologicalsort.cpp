#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v); //only for directed edge
    }

    void dfs(int curr, vector<bool> &vis, stack<int> &s){
        vis[curr] = true;

        for(int v : l[curr]){
            if(!vis[v]){
                dfs(v, vis, s);
            }
        }
        s.push(curr);
    }

    void topoSort(){
        vector<bool>vis(V, false);
        stack<int>s;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }
        while(s.size()>0){
            cout<< s.top() << " ";
            s.pop();
        }
        cout << endl;
    }


};

int main(){
    int V, E;
    int u, v;

    cout<<"Enter number of Vertex: ";
    cin>> V;

    Graph g(V);

    cout<<"Enter number of Edge: ";
    cin>> E;

    cout<<"Enter Edges: (u  v): " << endl;

    for(int i=0; i<E; i++){
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<"Topological Sort: ";

    g.topoSort();

    return 0;

}