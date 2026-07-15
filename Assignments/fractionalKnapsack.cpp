#include <iostream>
using namespace std;

struct Item
{
    int profit;
    int weight;
    float ratio;
};

Item items[100];

void sortItems(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (items[j].ratio <= items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of objects -  ";
    cin >> n;
    cout << "Enter knapsack capacity -  ";
    int c;
    cin >> c;
    cout << "Enter profit & weight of each object " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    sortItems(n);
    float totalProfit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
            break;
        if (items[i].weight <= c)
        {
            cout << "Take 100% of item " << i + 1 << endl;
            c -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            float fraction = (float)c / items[i].weight;
            cout << "Take " << fraction * 100 << "% of item " << i + 1 << endl;
            totalProfit += items[i].profit * fraction;
            c = 0;
        }
    }
    cout << "Maximum profit -  " << totalProfit << endl;
    return 0;
}