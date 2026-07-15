#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int arr[], int st, int en)
{
    int pvtIdx = st + rand() % (en - st + 1);
    swap(arr[pvtIdx], arr[en]);
    int pivot = arr[en];
    int idx = st - 1;
    for (int j = st; j < en; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[en], arr[idx]);
    return idx;
}

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
    int arr[100];
    int n;
    cout << "Enter size of array -  ";
    cin >> n;
    cout << "Enter elements - " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rQuickSort(arr, 0, n - 1);
    cout << "Sorted array -  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}