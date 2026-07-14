#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj[100];
int visited[100];

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
}