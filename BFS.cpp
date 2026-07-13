#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int g[100][100];
int visited[100];

void bfs(int v, int n)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    q.push(v);
    visited[v] = 1;
    cout << "BFS traversal - " << endl;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int w = 0; w < n; w++)
        {
            if (g[u][w] == 1 && visited[w] == 0)
            {
                q.push(w);
                visited[w] = 1;
            }
        }
    }
    cout << endl;
}

int main()
{
    fstream file;
    file.open("graph.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening file!!" << endl;
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
    cout << "Enter the starting vertex -  ";
    cin >> v;
    bfs(v, n);
    return 0;
}