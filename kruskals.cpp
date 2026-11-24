#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

class DSU {
    vector<int> parent, rankValue;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rankValue.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        // Same set means adding this edge creates a cycle
        if (rootU == rootV) {
            return false;
        }

        if (rankValue[rootU] < rankValue[rootV]) {
            swap(rootU, rootV);
        }

        parent[rootV] = rootU;

        if (rankValue[rootU] == rankValue[rootV]) {
            rankValue[rootU]++;
        }

        return true;
    }
};

int main() {
    int vertices, edgesCount;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    if (vertices <= 0 || edgesCount < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<Edge> edges(edgesCount);

    cout << "Enter each edge (u v weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u < 1 || edges[i].u > vertices ||
            edges[i].v < 1 || edges[i].v > vertices) {
            cout << "Vertex numbers must be from 1 to "
                 << vertices << ".\n";
            return 0;
        }
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });

    DSU dsu(vertices);
    vector<Edge> mst;
    long long totalWeight = 0;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
        }

        if (static_cast<int>(mst.size()) == vertices - 1) {
            break;
        }
    }

    if (static_cast<int>(mst.size()) != vertices - 1) {
        cout << "\nGraph is disconnected. MST does not exist.\n";
        return 0;
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    cout << "From\tTo\tWeight\n";

    for (const Edge& edge : mst) {
        cout << edge.u << "\t"
             << edge.v << "\t"
             << edge.weight << "\n";
    }

    cout << "Total weight: " << totalWeight << "\n";

    return 0;
}