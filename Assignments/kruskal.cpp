#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
};

Edge edges[100];
int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union1(int x, int y)
{
    parent[find(y)] = find(x);
}

void sortEdges(int e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - 1 - i; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices -  ";
    cin >> n;
    int e;
    cout << "Enter number of edges -  ";
    cin >> e;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    cout << "Enter source, destination & weight of each edge " << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sortEdges(e);
    int cost = 0;
    for (int i = 0; i < e; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            cout << "<" << edges[i].u << " " << edges[i].v << "> : " << edges[i].w << endl;
            cost += edges[i].w;
            union1(edges[i].u, edges[i].v);
        }
    }
    cout << "Minimum cost -  " << cost;
    return 0;
}