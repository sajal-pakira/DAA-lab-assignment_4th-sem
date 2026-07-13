#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int g[100][100];
int visited[100];

void bfs(int v, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    s.push(v);
    visited[v] = 1;
    cout << "DFS traversal -  ";
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        cout << u << " ";
        for (int w = 0; w < n; w++)
        {
            if (g[u][w] == 1 && visited[w] == 0)
            {
                s.push(w);
                visited[w] = 1;
            }
        }
    }
}

int main()
{
    fstream file;
    file.open("graph.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening file!!";
        return 1;
    }
    int n;
    file >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> g[i][j];
        }
    }
    int v;
    cout << "Enter starting vertex -  ";
    cin >> v;
    bfs(v, n);
    return 0;
}