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
    fstream file;
    file.open("graph.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening file!!";
        return;
    }
    int n;
    file >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> data;
            if (data == 1)
            {
                insertEdge(i, j);
            }
        }
    }
}

int main()
{
}