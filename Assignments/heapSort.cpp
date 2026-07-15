#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= size && arr[left] > arr[largest])
        largest = left;
    if (right <= size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int arr[], int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter size - ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    buildHeap(arr, n);
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i]<<" ";
    }
}