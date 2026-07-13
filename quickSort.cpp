#include <iostream>
using namespace std;

int arr[100];

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int hPartition(int low, int high)
{
    int i = low, j = high + 1;
    int pivot = arr[low];
    while (i < j)
    {
        do
        {
            i += 1;
        } while (arr[i] <= pivot && i <= j);
        do
        {
            j += 1;
        } while (arr[j] > pivot);
        if (i < j)
            swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
}

void quickSort(int i, int j)
{
    if (i < j)
    {
        int pvt = hPartition(i, j);
        quickSort(i, pvt - 1);
        quickSort(pvt + 1, j);
    }
}

int main()
{
    cout << "Enter size of array -  ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(0, n - 1);
    return 0;
}