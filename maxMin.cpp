#include <iostream>
using namespace std;
int arr[100];

void maxmin(int i, int j, int &max, int &min)
{
    int max1, min1;
    if (i == j)
    {
        max = min = arr[i];
    }
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            min = arr[i];
            max = arr[j];
        }
        else
        {
            max = arr[i];
            min = arr[j];
        }
    }
    else
    {

        int mid = i + (j - i) / 2;
        maxmin(i, mid, max, min);
        maxmin(mid + 1, j, max1, min1);
        if (max1 > max)
            max = max1;
        if (min1 < min)
            min = min1;
    }
}

int main()
{
    int n;
    cout << "Enter size of array -  ";
    cin >> n;
    cout << "Enter elements -  " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max, min;
    maxmin(0, n - 1, max, min);
    cout << "Maximum value - " << max << endl;
    cout << "Minimum value - " << min << endl;
    return 0;
}