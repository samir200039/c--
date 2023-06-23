//detect a cycle in graph (undirected) using bfs
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[]) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacent : adj[node]) {
            if (!vis[adjacent]) {
                vis[adjacent] = 1;
                q.push({adjacent, node});
            } else if (parent != adjacent) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adj, vis))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclePresent = isCycle(n, adj);

    if (isCyclePresent)
        cout << "Cycle is detected!" << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}


/*Hence, the condition parent != adjacent ensures that the adjacent node is not the immediate parent of the current node. 
If the condition is true, it indicates the presence of a cycle in the graph,
 and the function returns true.*/

/*output
Input:
6 6
0 1
1 2
2 3
3 4
4 5
5 2
*/