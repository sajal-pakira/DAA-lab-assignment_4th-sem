#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int arr[100];

int BS(int low, int high, int t)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == t)
        return mid;
    else if (arr[mid] < t)
        return BS(mid + 1, high, t);
    else
        return BS(low, mid - 1, t);
}

int main()
{
    int n;
    cout << "Enter size of array -  ";
    cin >> n;
    srand(time(0));
    cout << "Enter elements in sorted order -- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int t;
    cout << "\nEnter target -  ";
    cin >> t;
    int indx = BS(0, n - 1, t);
    if (indx == -1)
        cout << "Not found!!";
    else
        cout << indx;
    return 0;
}