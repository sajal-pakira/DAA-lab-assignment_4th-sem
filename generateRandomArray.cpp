#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int arr[], int n, int min, int max)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter size of array -  ";
    cin >> n;
    generateRandomArray(arr, n, 1, 100);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}