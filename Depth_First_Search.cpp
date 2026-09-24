#include <iostream>
#include <vector>
using namespace std;

void DFS(int current, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[current] = true;

    cout << current << " ";

    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, graph, visited);
        }
    }
}

int main()
{
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    DFS(start, graph, visited);

    return 0;
} 
