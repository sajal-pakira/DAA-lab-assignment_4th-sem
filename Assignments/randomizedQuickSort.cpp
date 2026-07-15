#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void rQuickSort(int arr[], int i, int j)
{
    if (i < j)
    {
        int pivIdx = partition(arr, i, j);
        rQuickSort(arr, i, pivIdx - 1);
        rQuickSort(arr, pivIdx + 1, j);
    }
}

int main()
{
    srand(time(0));
}