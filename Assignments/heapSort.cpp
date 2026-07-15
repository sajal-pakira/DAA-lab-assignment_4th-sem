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
}