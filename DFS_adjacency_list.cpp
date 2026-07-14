#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj[100];
int visited[100];

void DFS(int v, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    s.push(v);
    visited[v] = 1;
    cout << "DFS traversal --  " << endl;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            int w = adj[u][i];
            if (visited[w] == 0)
            {
                s.push(w);
                visited[w] = 1;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n, e;
    cout << "Enter number of edges -  ";
    cin >> e;
    cout << "Enter number of vertices -  ";
    cin >> n;
    cout << "Enter all edges <u v> " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int v;
    cout << "Enter starting vertex -  ";
    cin >> v;
    DFS(v, n);
    return 0;
}