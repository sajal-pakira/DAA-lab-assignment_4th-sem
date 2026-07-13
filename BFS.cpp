#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int g[100][100];
int visited[100];

void bfs(int v, int n)
{
}

int main()
{
    fstream file;
    file.open("DAA_ASSIGNMEN_LIST_pages-to-jpg-0001.jpg", ios::in);
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
}