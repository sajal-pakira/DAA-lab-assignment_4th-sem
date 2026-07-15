#include <iostream>
using namespace std;

int visited[100];
int graph[100][100];

void dfs(int v, int n)
{
    visited[v] = 1;
    cout << v << " ";
    for (int w = 0; w < n; w++)
    {
        if (graph[v][w] == 1 && visited[w] == 0)
        {
            dfs(w, n);
        }
    }
}

int main()
{
    int n, start;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "Enter the starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, n);

    return 0;
}