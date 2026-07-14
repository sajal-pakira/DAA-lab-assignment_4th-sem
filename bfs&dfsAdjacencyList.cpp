#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int vertex;
    Node *next;
};

int n;
int e;
Node *adjList[100] = {NULL};
int visited[100] = {0};

void insertEdge(int u,int j){
    
}

int main()
{
    cout << "Enter number of vertices -  ";
    cin >> n;
    cout << "Enter number of edges -  ";
    cin >> e;
    cout << "Enter all edges (in <u v> form) " << endl;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        insertEdge(u,v);
    }
}