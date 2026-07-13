#include <iostream>
using namespace std;

int arr[100];
int temp[100];

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int i, int j)
{
    if (i < j)
    {
        int mid = i + (j - i) / 2;
        mergeSort(i, mid);
        mergeSort(mid + 1, j);
        merge(i, mid, j);
    }
}

int main()
{
    int n;
    cout << "Enter size of array -  ";
    cin >> n;
    cout << "Enter elements - " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(0, n - 1);
    cout << "After sorting --  " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}