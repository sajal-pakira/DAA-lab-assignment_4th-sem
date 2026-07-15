#include <iostream>
using namespace std;

int adj[100][100];
int visited[100] = {0};
int queue[100];

int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == 99)
    {
        cout << "Queue Overflow!!";
        return;
    }
    if (front == -1)
        front++;
    queue[++rear] = val;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow!!";
        return -1;
    }
    return queue[front++];
}

void bfs(int v, int n)
{
    enqueue(v);
    visited[v] = 1;
    while (front <= rear)
    {
        int u = dequeue();
        cout << u << " ";
        for (int w = 0; w < n; w++)
        {
            if (adj[u][w] == 1 && visited[w] == 0)
            {
                enqueue(w);
                visited[w] = 1;
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertices -  ";
    int n;
    cin >> n;
    cout << "Enter starting vertex -  ";
    int v;
    cin >> v;
    bfs(v, n);
    return 0;
}