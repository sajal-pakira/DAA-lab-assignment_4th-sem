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
int v;

Node *adjList[100] = {NULL};
int visited[100] = {0};

void insertEdge(int u, int v)
{
    Node *curr1 = new Node;
    curr1->vertex = v;
    curr1->next = NULL;
    if (adjList[u] == NULL)
    {
        adjList[u] = curr1;
    }
    else
    {
        Node *temp = adjList[u];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = curr1;
    }
    Node *curr2 = new Node;
    curr2->vertex = u;
    curr2->next = NULL;
    if (adjList[v] == NULL)
    {
        adjList[v] = curr2;
    }
    else
    {
        Node *temp = adjList[v];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = curr2;
    }
}

int main()
{
    cout << "Enter number of vertices -  ";
    cin >> n;
    cout << "Enter number of edges -  ";
    cin >> e;
    cout << "Enter all edges (in <u v> form) " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        insertEdge(u, v);
    }
    cout << "Enter starting vertex -  ";
    cin >> v;
    
}