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

void bfs(int v, int n)
{
}