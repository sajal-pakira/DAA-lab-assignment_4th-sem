#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("graph.txt", ios::in);
    if (!file)
    {
        cout << "Error in file opening!!";
        return 1;
    }
    int n;
    file >> n;
    int graph[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> graph[i][j];
        }
    }
    int degree = 0;
    cout << "Adajacency Matrix --" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                degree += 1;
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total Degree of graph is " << degree << endl;
    cout << "Number of edges of graph is " << degree / 2 << endl;
    int adjvrtx;
    cout << "Enter a vertex -  ";
    cin >> adjvrtx;
    cout << "Adjacent vertices of vertex " << adjvrtx << " are -  ";
    for (int i = 0; i < n; i++)
    {
        if (graph[adjvrtx][i] == 1)
            cout << i << " ";
    }
    file.close();
    return 0;
}