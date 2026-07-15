#include <iostream>
using namespace std;

int graph[100][100];
int visited[100] = {0};
int stack[100];

int top = -1;

bool isEmpty()
{
    return top == -1;
}

void push(int val)
{
    if (top == 99)
    {
        cout << "Stack overflow!!";
        return;
    }
    stack[++top] = val;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow!!";
        return -1;
    }
    return stack[top--];
}

void dfsIterative(int v, int n)
{
    push(v);
    visited[v] = 1;
    while (!isEmpty)
    {
        int u = pop();
        cout << u << " ";
        for (int w = 0; w < n; w++)
        {
            if (graph[u][w] == 1 && visited[w] == 0)
            {
                push(w);
                visited[w] = 0;
            }
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

    dfsIterative(start, n);

    return 0;
}