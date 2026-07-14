#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int vertex;
    Node *next;
};

Node *adjList[100] = {NULL};

void insertEdge(int i, int j)
{
    Node *curr = new Node;
    curr->vertex = j;
    curr->next = NULL;
    if (adjList[i] == NULL)
    {
        adjList[i] = curr;
        return;
    }
    Node *temp = adjList[i];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = curr;
}

void makeAdjacencyList()
{
}

int main()
{
}