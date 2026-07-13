#include <iostream>
using namespace std;

int arr[100];

int main()
{
    cout << "Enter size of array -  ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}