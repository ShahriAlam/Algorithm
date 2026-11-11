#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> reach(n, vector<int>(n));

    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> reach[i][j];
        }
    }

    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }

    cout << "\nTransitive closure:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}